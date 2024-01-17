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
#include "PreparedQuery.h"

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
        db->open("mygroceries");
        //using prepared query
        string sqlp = "Select distinct foodname, price, storename from prices \
            join foods on(foods.foodkey = prices.foodkey) \
            join stores on(stores.storekey = prices.storekey) \
            where price > ? and storename like ?";
        mysqlx::SqlStatement sqQuery = db->getSqlStatement(sqlp);
        msqPreparedQuery* prep = new msqPreparedQuery(db, &sqQuery);
        prep->setVariable(2.0);
        prep->setVariable("S%");
        Results* res1 = prep->execute();
        for (int i = 0; i < res1->getSize(); i++) {
            res1->setCursor(i);
            dbMap dm1 = res1->getRow();
            
            cout << dm1["foodname"] << " " << dm1["price"] << " "
                << dm1["storename"] << endl;
           
             
           
        }

        // Close the session
        db->close();
    }
    catch (const mysqlx::Error& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
