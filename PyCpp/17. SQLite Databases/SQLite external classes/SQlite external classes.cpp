<<<<<<< HEAD
// Simple Sql database classes.cpp : 
// This file contains the 'main' function. Program execution begins and ends there.
//
#include "globaldefs.h"
#include "Results.h"
#include "Query.h"
#include "sqltDatabase.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;


//program starts here
int main(int argc, char* argv[]) {

    sqltDatabase db("groceries.db");

    //note the continuation character within a string
    Query qry(db,
        "Select foodname, price, storename from prices \
        join foods on (foods.foodkey = prices.foodkey)  \
        join stores on (stores.storekey = prices.storekey) \
        order by foodname, price");

    Results* res = qry.execute();      //execute the query
    cout << res->getVal("foodname") << endl;

    string val = res->getCol(1);
    cout << "col1 = " << val << endl;

    //print out results of query
    for (int i = 0; i < res->getSize(); i++) {
        dbMap r = res->getRow();
        cout << r["foodname"] << ": " << r["price"]
            << ": " << r["storename"] << endl;
    }
    return 0;
}

