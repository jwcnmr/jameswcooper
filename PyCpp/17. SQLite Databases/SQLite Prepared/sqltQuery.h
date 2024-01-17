#pragma once
#include "globaldefs.h"
#include "Results.h"
#include "sqltDatabase.h"

//The query class executes an SQL statment
//and returns the results in an Results object
class sqltQuery {
public:
    static vector <dbMap> stRows;
    static map<string, string> stRow;
    static int returnCode;
protected:
    string qstring;
    sqlite3* sqdb;
    char* errMsg = 0;

public:
    sqltQuery(sqltDatabase db, string sqlstring);
    static int callback(void* data, int count, char** colVal, char** colName);
    Results* execute();
    void checkerr(int rc);
};
