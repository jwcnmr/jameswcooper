<<<<<<< HEAD
#pragma once
#include "globaldefs.h"

class sqltDatabase {
private:
    sqlite3* sqldb{ NULL };
    string dbname;
    bool exists(const std::string& name); 
        
public:
    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    sqltDatabase(std::string filename);
    //return the sqlite pointer
    sqlite3* getDb();
    //close the database connection
    void close();

};

=======
#pragma once
#include "globaldefs.h"

class sqltDatabase {
private:
    sqlite3* sqldb{ NULL };
    string dbname;
    bool exists(const std::string& name); 
        
public:
    //open the database if it exists
    // sqlite otherwise would create an empty one
    //  here we check for existence to avoid creating one
    sqltDatabase(std::string filename);
    //return the sqlite pointer
    sqlite3* getDb();
    //close the database connection
    void close();

};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
