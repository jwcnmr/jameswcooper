// MySQL test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

#include "globaldefs.h"
#include "msqTable.h"
#include "Database.h"
#include "msqDatabase.h"
#include "Query.h"
#include "PriceTable.h"


using std::cout;
using std::endl;
using std::stringstream;
//using namespace::mysqlx;

int main(int argc, const char* argv[]) {
    try {
        std::string user = "newuser";
        std::string password = "new_user";
        std::string host = "localhost";
        unsigned int port = 33060;
     
        // Create a session to connect to the MySQL Server
        msqDatabase* db = new msqDatabase(host, port, user, password);
        db->create("mygroceries");
        //make the food table
        msqTable* foodTable = new msqTable("foods", db);
        foodTable->addColumn(new PrimaryCol("foodkey", true));
        foodTable->addColumn(new CharCol("foodname", 45));
        foodTable->create();
        
        foodTable->addRow("foodname", "\"Apples\"");
        foodTable->addRow("foodname", "\"Butter\"");
        foodTable->addRow("foodname", "\"Cola\"");
        foodTable->addRow("foodname", "\"Green beans\"");
        foodTable->addRow("foodname", "\"Hamburger\"");
        foodTable->addRow("foodname", "\"Milk\"");
        foodTable->addRow("foodname", "\"Oranges\"");

        msqTable* storeTable = new msqTable("stores", db);
        storeTable->addColumn(new PrimaryCol("storekey", true));
        storeTable->addColumn(new CharCol("storename", 45));
        storeTable->create();
        storeTable->addRow("storename", "\"Stop and Shop\"");
        storeTable->addRow("storename", "\"Village Market\"");
        storeTable->addRow("storename", "\"Shoprite\"");

        PriceTable* priceTable = new PriceTable(db);
        
        const int STOP = storeTable->getKey("storekey", "storename", "Stop and Shop");
        const int RITE = storeTable->getKey("storekey", "storename", "Shoprite");
        const int VILLAGE = storeTable->getKey("storekey", "storename", "Village Market");

        const int APPLES = foodTable->getKey("foodkey", "foodname", "Apples");
        const int BUTTER = foodTable->getKey("foodkey", "foodname", "Butter");
        const int COLA = foodTable->getKey("foodkey", "foodname", "Cola");
        const int BEANS = foodTable->getKey("foodkey", "foodname", "Green beans");
        const int BURGER = foodTable->getKey("foodkey", "foodname", "Hamburger");
        const int MILK = foodTable->getKey("foodkey", "foodname", "Milk");
        const int ORANGES = foodTable->getKey("foodkey", "foodname", "Oranges");

        priceTable->addRow(std::make_tuple(STOP, APPLES, 0.55));
        priceTable->addRow(pricetuple(STOP, BUTTER, 4.59));
        priceTable->addRow(pricetuple(STOP, COLA, 8.95));
        priceTable->addRow(pricetuple(STOP, BEANS, 3.49));
        priceTable->addRow(pricetuple(STOP, BURGER, 6.95));
        priceTable->addRow(pricetuple(STOP, MILK, 3.49));
        priceTable->addRow(pricetuple(STOP, ORANGES, 0.95));


        priceTable->addRow(pricetuple(RITE, APPLES, 0.49));
        priceTable->addRow(pricetuple(RITE, BUTTER, 4.99));
        priceTable->addRow(pricetuple(RITE, COLA, 9.25));
        priceTable->addRow(pricetuple(RITE, BEANS, 2.49));
        priceTable->addRow(pricetuple(RITE, BURGER, 5.95));
        priceTable->addRow(pricetuple(RITE, MILK, 4.59));
        priceTable->addRow(pricetuple(RITE, ORANGES, 0.89));

        priceTable->addRow(pricetuple(VILLAGE, APPLES, 0.69));
        priceTable->addRow(pricetuple(VILLAGE, BUTTER, 4.29));
        priceTable->addRow(pricetuple(VILLAGE, COLA, 7.85));
        priceTable->addRow(pricetuple(VILLAGE, BEANS, 3.99));
        priceTable->addRow(pricetuple(VILLAGE, BURGER, 7.95));
        priceTable->addRow(pricetuple(VILLAGE, MILK, 4.59));
        priceTable->addRow(pricetuple(VILLAGE, ORANGES, 0.99));

       
        
        // Perform any operations on the table or query data as needed
        string sql = "Select distinct foodname, price, storename from prices \
            join foods on(foods.foodkey = prices.foodkey) \
            join stores on(stores.storekey = prices.storekey)";
               
        Query* qry = new Query(db, sql);
        Results* res = qry->execute();
        for (int i = 0; i < res->getSize(); i++) {
            res->setCursor(i);
            dbMap dm = res->getRow();
            cout << dm["foodname"] << " " << dm["price"] << " "
                << dm["storename"] << endl;
        }
        cout << endl;
         // Close the session
        db->close();
    }
    catch (const mysqlx::Error& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
