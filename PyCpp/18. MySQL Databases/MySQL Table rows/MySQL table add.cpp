// MySQL test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <mysqlx/xdevapi.h>

using std::cout;
using std::endl;
using namespace::mysqlx;

int main(int argc, const char* argv[]) {
    try {
        std::string user = "newuser";
        std::string password = "new_user";
        std::string host = "localhost";
        unsigned int port = 33060;
     
        // Create a session to connect to the MySQL Server
        mysqlx::Session session(host, port, user, password);
        
        // Use the session to execute SQL statements
        Schema schema = session.getSchema("mygroceries");
        session.sql("USE groceries").execute();
        
        Table table = schema.getTable("foods");
        table.insert("foodname").values("Pineapple").execute();
        
        Table tb2 = schema.getTable("prices");
        tb2.insert("storekey", "foodkey", "price").values(3, 8, 3.75).execute();
            
        // Close the session
        session.close();
    }
    catch (const mysqlx::Error& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
