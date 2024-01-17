<<<<<<< HEAD
#include "globaldefs.h"
#include "Query.h"
#include <iostream>

using std::cout;
using std::endl;

// ----Here is the static initialization ----
// of the row map and rows vector
dbMap Query::stRow;
vector<dbMap> Query::stRows;
int Query::returnCode;


    Query::Query(sqltDatabase db, string sqlstring) {
        sqdb = db.getDb();
        qstring = sqlstring;
    }

    //this one is  static
    int Query::callback(void* data, int count, char** colVal, char** colName) {
       
        Query::stRow.clear();
        //copy each value pair into a map
        for (int i = 0; i < count; i++) {
           // std::cout << " " << colName[i] << " " << colVal[i] << " " << endl;
            string s1 = string(colName[i]);
            string s2 = string(colVal[i]);
            Query::stRow.insert({ s1, s2 });        
        }
        Query::stRows.push_back(Query::stRow);

        return 0;
    }
    //execute the query:
    // the results are assembled in the static callback function
    // as a vector of maps, one for each line of the results
    //a pointer to a Results object is returned, containint that vector

    Results* Query::execute() {
        cout << qstring << endl;
        Query::stRows.clear(); //clear both static variables
        returnCode = sqlite3_exec(sqdb, qstring.c_str(), Query::callback,
            nullptr, &errMsg);
        if (returnCode != 0) {
            cout << errMsg << endl;
        }
        size_t size = stRows.size();
        return new Results(stRows);
    }


=======
#include "globaldefs.h"
#include "Query.h"
#include <iostream>

using std::cout;
using std::endl;

// ----Here is the static initialization ----
// of the row map and rows vector
dbMap Query::stRow;
vector<dbMap> Query::stRows;
int Query::returnCode;


    Query::Query(sqltDatabase db, string sqlstring) {
        sqdb = db.getDb();
        qstring = sqlstring;
    }

    //this one is  static
    int Query::callback(void* data, int count, char** colVal, char** colName) {
       
        Query::stRow.clear();
        //copy each value pair into a map
        for (int i = 0; i < count; i++) {
           // std::cout << " " << colName[i] << " " << colVal[i] << " " << endl;
            string s1 = string(colName[i]);
            string s2 = string(colVal[i]);
            Query::stRow.insert({ s1, s2 });        
        }
        Query::stRows.push_back(Query::stRow);

        return 0;
    }
    //execute the query:
    // the results are assembled in the static callback function
    // as a vector of maps, one for each line of the results
    //a pointer to a Results object is returned, containint that vector

    Results* Query::execute() {
        cout << qstring << endl;
        Query::stRows.clear(); //clear both static variables
        returnCode = sqlite3_exec(sqdb, qstring.c_str(), Query::callback,
            nullptr, &errMsg);
        if (returnCode != 0) {
            cout << errMsg << endl;
        }
        size_t size = stRows.size();
        return new Results(stRows);
    }


>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
