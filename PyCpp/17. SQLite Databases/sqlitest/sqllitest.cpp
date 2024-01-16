// sqllitest.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>

// the callback routine that SQLite calls for each row
// of the query
int callback(void* data, int argc, char** colVal, char** colName) {
    // each callback returns one row
    for ( int i = 0; i < argc; i++) {      
        std::cout  << " " << colVal[i] << " "; //print each value in row
    }
    std::cout << std::endl; //end line for each row
    return 0;
}

//main program
int main(int argc, char* argv[]) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    const char* sql;
    const char* data = "Callback function called";
    /* Open database */
    rc = sqlite3_open("groceries.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
    /* Create SQL statement */
    sql = "Select foodname, price, storename \
        from foods, prices, stores \
        where foods.foodkey = prices.foodkey \
        and stores.storekey = prices.storekey \
        order by foodname, price";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }
    //program returns here when callbacks are finished
    sqlite3_close(db);
    return 0;
}

