
// MySQL test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <mysqlx/xdevapi.h>
#include <time.h>

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
        cout << "session" << endl;
        Schema schema = session.getSchema("groceries");
       // std::cout << "schema" << std::endl;
        session.sql("USE groceries").execute();
       

        // Perform any operations on the table or query data as needed
        string sql = "Select distinct foodname, price, storename from prices \
            join foods on(foods.foodkey = prices.foodkey) \
            join stores on(stores.storekey = prices.storekey) \
            where price > ? and storename like ? ";
               
        clock_t start, end;     //two clock objects
        double cputime;         //time goes here
        cout << std::fixed;     //fixed precision output
        start = clock();        //start the clock
        SqlResult res = session.sql(sql).bind(1.0).bind("S%").execute();      
        end = clock();          //end the clock
        cputime = ((double)end - start) ; //save the time
        cout  << std::setprecision(9) << cputime << endl;

        start = clock();
        SqlResult res1 = session.sql(sql).bind(0.5).bind("V%").execute();
        end = clock();
        cputime = ((double)end - start);
        cout << std::setprecision(9)  << cputime << endl;

        const Columns& columns = res.getColumns();
        Row row;
        while ((row = res.fetchOne())) {
            for (unsigned index = 0; index < res.getColumnCount(); index++)
                cout << columns[index].getColumnName()<<": " << row[index] << endl;
        }
        cout << endl;
        while ((row = res1.fetchOne())) {
            for (unsigned index = 0; index < res1.getColumnCount(); index++)
                cout << columns[index].getColumnName() << ": " << row[index] << endl;
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
