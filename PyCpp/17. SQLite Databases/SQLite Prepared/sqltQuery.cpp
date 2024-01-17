#include "globaldefs.h"
#include "Query.h"
#include <iostream>

using std::cout;
using std::endl;

// ----Here is the static initialization ----
// of the row map and rows vector
dbMap sqltQuery::stRow;
vector<dbMap> sqltQuery::stRows;
int sqltQuery::returnCode;
void sqltQuery::checkerr(int rc) {
    if (rc != SQLITE_OK) {
        cout << "error: " << sqlite3_errmsg(sqdb) << std::endl;
    }
}

    sqltQuery::sqltQuery(sqltDatabase db, string sqlstring) {
        sqdb = db.getDb();
        qstring = sqlstring;
    }

    //this one is  static
    int sqltQuery::callback(void* data, int count, char** colVal, char** colName) {
       
        sqltQuery::stRow.clear();
        //copy each value pair into a map
        for (int i = 0; i < count; i++) {
           // std::cout << " " << colName[i] << " " << colVal[i] << " " << endl;
            string s1 = string(colName[i]);
            string s2 = string(colVal[i]);
            sqltQuery::stRow.insert({ s1, s2 });        
        }
        sqltQuery::stRows.push_back(sqltQuery::stRow);

        return 0;
    }
    //execute the query:
    // the results are assembled in the static callback function
    // as a vector of maps, one for each line of the results
    //a pointer to a Results object is returned, containint that vector

    Results* sqltQuery::execute() {
        //cout << qstring << endl;
        sqltQuery::stRows.clear(); //clear both static variables
        returnCode = sqlite3_exec(sqdb, qstring.c_str(), sqltQuery::callback,
            nullptr, &errMsg);
        if (returnCode != 0) {
            cout << errMsg << endl;
        }
        size_t size = stRows.size();
        return new Results(stRows);
    }


