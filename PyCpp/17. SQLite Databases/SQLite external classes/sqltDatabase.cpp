#include "globaldefs.h"
#include "sqltDatabase.h"
#include <fstream>
using std::ifstream;

    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    bool sqltDatabase::exists(const std::string& name) {
        ifstream f(name.c_str());
        return f.good();
    }
    sqltDatabase::sqltDatabase(std::string filename) {

        /* Open database */
        dbname = filename;
        //only open if it exists
        if (exists(dbname.c_str())) {
            int rc = sqlite3_open("groceries.db", &sqldb);

        }
        // sqldb will be NULL if this fails 
    }
    //return the sqlite pointer
    sqlite3* sqltDatabase::sqltDatabase:: getDb() {
        return sqldb;
    }
    //close the database connection
    void  sqltDatabase::close() {
        sqlite3_close(sqldb);
    }


