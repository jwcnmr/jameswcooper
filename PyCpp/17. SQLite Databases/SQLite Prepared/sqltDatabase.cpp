#include "globaldefs.h"
#include "Database.h"
#include "sqltDatabase.h"
#include <fstream>
#include <cstdio>
#include "Query.h"
using std::ifstream;

    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    bool sqltDatabase::exists(const std::string& name) {
        ifstream f(name.c_str());
        return f.good();
    }
    //get the database name
    string sqltDatabase::getName() {
        return dbname;
    }
    //get the names of the tables
    vector<string> sqltDatabase::getTableNames() {
        sqltQuery qry(*this,
            "SELECT name FROM sqlite_schema \
            WHERE type = 'table'  AND \
            name NOT LIKE 'sqlite_%'");

        qry.execute();
        Results res = Results(sqltQuery::stRows);
        tableNames.clear();

        //print out results of query
        for (int i = 0; i < res.getSize(); i++) {
            dbMap r = res.getRow();
            string val = r["name"];
            tableNames.push_back(val);
        }
        return tableNames;
    }
    sqltDatabase::sqltDatabase() {
       
    }
    int sqltDatabase::open(std::string fname) {
        /* Open database  -- error if it doesn't exist */
        dbname = fname;
        rc = sqlite3_open_v2(dbname.c_str(), &sqldb,
            SQLITE_OPEN_READWRITE, NULL);
        return rc;
    }
    int sqltDatabase::create(std::string fname) {
        /* Open database or create it */
        dbname = fname;
        rc = sqlite3_open_v2(dbname.c_str(), &sqldb,
            SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
        return rc;
    }
        //return the sqlite pointer
        sqlite3* sqltDatabase::sqltDatabase:: getDb() {
        return sqldb;
    }
    //close the database connection
    void  sqltDatabase::close() {
        sqlite3_close(sqldb);
    }


