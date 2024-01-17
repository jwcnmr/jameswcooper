<<<<<<< HEAD
// MySQL test.cpp : 
// Opens a database and runs a query
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
        
        // Tell MySQL which database to use
        session.sql("USE groceries").execute();
        
        // Perform any operations on the table or query data as needed
        string sql = "Select distinct foodname, price, storename from prices \
            join foods on(foods.foodkey = prices.foodkey) \
            join stores on(stores.storekey = prices.storekey)";
               
        //execute a query and print out the result
        SqlResult res = session.sql(sql).execute(); //query result
        const Columns& columns = res.getColumns();  //array of columns
        Row row;
        while ((row = res.fetchOne())) {    //get each row
            //get each column
            for (unsigned index = 0; index < res.getColumnCount(); index++) {              
               //print out the column name and content
                cout << columns[index].getColumnName() << ": " << row[index] << endl;
            }
        }   
        // Close the session
        session.close();
    }
    catch (const mysqlx::Error& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
=======
// MySQL test.cpp : 
// Opens a database and runs a query
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
        
        // Tell MySQL which database to use
        session.sql("USE groceries").execute();
        
        // Perform any operations on the table or query data as needed
        string sql = "Select distinct foodname, price, storename from prices \
            join foods on(foods.foodkey = prices.foodkey) \
            join stores on(stores.storekey = prices.storekey)";
               
        //execute a query and print out the result
        SqlResult res = session.sql(sql).execute(); //query result
        const Columns& columns = res.getColumns();  //array of columns
        Row row;
        while ((row = res.fetchOne())) {    //get each row
            //get each column
            for (unsigned index = 0; index < res.getColumnCount(); index++) {              
               //print out the column name and content
                cout << columns[index].getColumnName() << ": " << row[index] << endl;
            }
        }   
        // Close the session
        session.close();
    }
    catch (const mysqlx::Error& error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
