// Simple Sql database classes.cpp : 
// This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>


using std::string;
using std::vector;
using std::tuple;
using std::map;
using std::cout;
using std::endl;
using std::pair;
using std::ifstream;

//convenient abbreviation for the map
typedef  map<string, string> dbMap;

//header for Results class

class Results {
private:
    vector<dbMap> rows;
    int cursor = 0;
public:
    Results(vector<dbMap> crows); //constructor
    dbMap getRow();               //get the whole row  
    string getVal(string name);   //get e value from the map  
    size_t getSize();             //get the size of the map
    string getCol(int index);     //get one value by column number  
};

//The basic database object
//contains a pointer to the sqlite database
class sqltDatabase {
private:
    sqlite3* sqldb{ NULL };
    string dbname;
    bool exists(const std::string& name) {
        ifstream f(name.c_str());
        return f.good();
    }
public:
    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    sqltDatabase(std::string filename) {
        
        /* Open database */      
        dbname = filename;
        //only open if it exists
        if (exists(dbname.c_str())) {
            int rc = sqlite3_open("groceries.db", &sqldb);
            
        } 
        // sqldb will be NULL if this fails 
    }
    //return the sqlite pointer
    sqlite3* getDb() {
        return sqldb;
    }
    //close the database connection
    void close() {
        sqlite3_close(sqldb);
    }
    
};

//The query class executes an SQL statment
//and returns the results in an Results object
class Query {
public:
    static dbMap stRow; //the map accrues here
    static vector <dbMap> stRows;     //vector of maps 
private:
    string qstring ;
    sqlite3* sqdb;
    char* errMsg = 0;
   
public:
    Query(sqltDatabase db, string sqlstring) {
        sqdb = db.getDb();
        qstring = sqlstring;
    }

    static int callback(void* data, int count, char** colVal, char** colName) {
        Query::stRow.clear();  //clear the map variable
        for (int i = 0; i < count; i++) {
            string s1 = string(colName[i]); //name
            string s2 = string(colVal[i]);  //value
            Query::stRow.insert({ s1, s2 }); //insert into map  
        }
        Query::stRows.push_back(Query::stRow); //add map to vector
        return 0;
    }
    //execute the query:
    // the results are assembled in the static callback function
    // as a vector of maps, one for each line of the results
    //a pointer to a Results object is returned, containint that vector
   
    Results* execute() {
        int rc = sqlite3_exec(sqdb, qstring.c_str(), Query::callback,
            nullptr, &errMsg);    
        return new Results(stRows);
    }
   
};
//the Results class holds the vector of maps from the last query
//and provides various ways to access them
  
    //copy from the Query static vector
    Results::Results(vector<dbMap> crows) {
        for (int i = 0; i < crows.size(); i++) {
            rows.push_back(crows[i]);
        }
    }
    //get one row as a map
    dbMap Results::getRow() {
        return rows[cursor++];
    }
    //get the value of the named column in the current row
    string Results::getVal(string name) {
        return rows[cursor][name];
        cursor++;
    }
    //get the size of the result
   size_t Results::getSize() {
        return rows.size();
    }
    //get the value of the map entry by index
    string Results::getCol(int index) {
        if (cursor < rows.size()) {
            dbMap map = rows[cursor];
            auto it = map.begin();
            std::advance(it, index);
            return it->second;
        }
        else
            return "";
    }

    // ----Here is the static initialization ----
// of the row map and rows vector
dbMap Query::stRow; 
vector<dbMap> Query::stRows;

//program starts here
int main(int argc, char* argv[]) {
    //open the database
    sqltDatabase db("groceries.db");

    // create the query
    //note the continuation character within a string
    Query qry(db, 
        "Select foodname, price, storename from prices \
        join foods on (foods.foodkey = prices.foodkey)  \
        join stores on (stores.storekey = prices.storekey) \
        order by foodname, price");
        
    //execute the query
        Results* res =qry.execute();      //execute the query
       
        //print out results of query
        for (int i = 0; i < res->getSize(); i++) {
            dbMap r = res->getRow();
            cout << r["foodname"] << ": " << r["price"]
                << ": " << r["storename"] << endl;
        }
    return 0;
}

