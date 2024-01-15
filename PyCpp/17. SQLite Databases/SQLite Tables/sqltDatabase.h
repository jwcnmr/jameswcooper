#pragma once
#include "globaldefs.h"

class sqltDatabase {
private:
    sqlite3* sqldb{ NULL };
    string filename;
    string dbname;
    bool exists(const std::string& name); 
    vector<string> tableNames;
    int rc{ -1 };
        
public:
    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    int open(std::string filename);
    int create (std::string filename);
    sqltDatabase();
    //return the sqlite pointer
    sqlite3* getDb();
    string getName();
    vector<string> getTableNames();
    //close the database connection
    void close();

};

