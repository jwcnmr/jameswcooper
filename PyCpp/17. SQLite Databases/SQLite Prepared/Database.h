#pragma once
#include "globaldefs.h"
class Database {
public:
    virtual int open(std::string filename) = 0;
    virtual int create(std::string filename) = 0;
   
    virtual string getName() =0;
    virtual vector<string> getTableNames() =0;
    //close the database connection
    virtual void close() = 0;
};

