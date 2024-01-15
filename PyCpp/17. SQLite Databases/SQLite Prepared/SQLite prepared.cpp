// Simple Sql database classes.cpp : 
// This file contains the 'main' function. Program execution begins and ends there.
//
#include "globaldefs.h"
#include "Results.h"
#include "Query.h"
#include "sqltDatabase.h"
#include "Table.h"
#include "PriceTable.h"
#include "sqltPrepQuery.h"


#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;
using std::to_string;


//program starts here
int main(int argc, char* argv[]) {

    sqltDatabase db;
    /*
    db.create("mygroc.db");

    Table* stores = new Table("stores", db);
    stores->addColumn(new PrimaryCol("storekey"));
    stores->addColumn(new CharCol("storename", 45));
    stores->create();
    stores->addRow("storename", "\"Stop and Shop\"");
    stores->addRow("storename", "\"Village Market\"");
    stores->addRow("storename", "\"Shoprite\"");

    Table* foods = new Table("foods", db);
    foods->addColumn(new PrimaryCol("foodkey"));
    foods->addColumn(new CharCol("foodname", 45));
    foods->create();
    foods->addRow("foodname", "\"Apples\"");
    foods->addRow("foodname", "\"Butter\"");
    foods->addRow("foodname", "\"Cola\"");
    foods->addRow("foodname", "\"Green beans\"");
    foods->addRow("foodname", "\"Hamburger\"");
    foods->addRow("foodname", "\"Milk\"");
    foods->addRow("foodname", "\"Oranges\"");

    PriceTable* prices = new PriceTable(db);


    const int STOP = stores->getKey("storekey", "storename", "Stop and Shop");
    const int RITE = stores->getKey("storekey", "storename", "Shoprite");
    const int VILLAGE = stores->getKey("storekey", "storename", "Village Market");

    const int APPLES = foods->getKey("foodkey", "foodname", "Apples");
    const int BUTTER = foods->getKey("foodkey", "foodname", "Butter");
    const int COLA = foods->getKey("foodkey", "foodname", "Cola");
    const int BEANS = foods->getKey("foodkey", "foodname", "Green beans");
    const int BURGER = foods->getKey("foodkey", "foodname", "Hamburger");
    const int MILK = foods->getKey("foodkey", "foodname", "Milk");
    const int ORANGES = foods->getKey("foodkey", "foodname", "Oranges");

    prices->addRow(std::make_tuple(STOP, APPLES, 0.55));
    prices->addRow(pricetuple(STOP, BUTTER, 4.59));
    prices->addRow(pricetuple(STOP, COLA, 8.95));
    prices->addRow(pricetuple(STOP, BEANS, 3.49));
    prices->addRow(pricetuple(STOP, BURGER, 6.95));
    prices->addRow(pricetuple(STOP, MILK, 3.49));
    prices->addRow(pricetuple(STOP, ORANGES, 0.95));


    prices->addRow(pricetuple(RITE, APPLES, 0.49));
    prices->addRow(pricetuple(RITE, BUTTER, 4.99));
    prices->addRow(pricetuple(RITE, COLA, 9.25));
    prices->addRow(pricetuple(RITE, BEANS, 2.49));
    prices->addRow(pricetuple(RITE, BURGER, 5.95));
    prices->addRow(pricetuple(RITE, MILK, 4.59));
    prices->addRow(pricetuple(RITE, ORANGES, 0.89));

    prices->addRow(pricetuple(VILLAGE, APPLES, 0.69));
    prices->addRow(pricetuple(VILLAGE, BUTTER, 4.29));
    prices->addRow(pricetuple(VILLAGE, COLA, 7.85));
    prices->addRow(pricetuple(VILLAGE, BEANS, 3.99));
    prices->addRow(pricetuple(VILLAGE, BURGER, 7.95));
    prices->addRow(pricetuple(VILLAGE, MILK, 4.59));
    prices->addRow(pricetuple(VILLAGE, ORANGES, 0.99));

    //now issue a query on this new database
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
    vector <dbMap> rows = res->getRows();
    for (dbMap r : rows) {
        cout << r["foodname"] << ": " << r["price"]
            << ": " << r["storename"] << endl;
    }
    //or get the rows one at a time
    cout << endl;

    for (int i = 0; i < res->getSize(); i++) {
        dbMap r = res->getRow();
        cout << r["foodname"] << ": " << r["price"]
            << ": " << r["storename"] << endl;
    }
    db.close();
    */
    db.open("mygroc.db");
    string prepsql =
        "Select distinct foodname, price, storename from prices \
        join foods on (foods.foodkey = prices.foodkey)  \
        join stores on (stores.storekey = prices.storekey) \
        where (foodname = ?) or (foodname = ?) order by foodname, price";
      
        // where price = ? or price = ? order by price";
       // where foodname = ? order by price";
      //  where price > ? order by price";  //example of using double
    sqltPrepQuery pq(db, prepsql);
    pq.setVariable(1, "Milk");
    pq.setVariable(2, "Oranges");

   // pq.setVariable(1, 2.00);  //example of using double
    Results* res = pq.execute();
    for (int i = 0; i < res->getSize(); i++) {
        dbMap dm = res->getRow();
        cout << dm["foodname"] << " " << dm["price"] << " " 
            << dm["storename"]<<endl;
    }
    pq.closeStatement();    //delete the statement
    return 0;
}

