<<<<<<< HEAD
#pragma once
#include "globaldefs.h"
#include "Query.h"
class msqPreparedQuery :
    public Query
{
private:
    msqDatabase* db;
public:
    mysqlx::SqlStatement* sqQuery;
    msqPreparedQuery(msqDatabase* db, mysqlx::SqlStatement* psQuery);
    void setVariable(string value);
    void setVariable(double value);
    void setVariable( int value);
    Results* execute();
};

=======
#pragma once
#include "globaldefs.h"
#include "Query.h"
class msqPreparedQuery :
    public Query
{
private:
    msqDatabase* db;
public:
    mysqlx::SqlStatement* sqQuery;
    msqPreparedQuery(msqDatabase* db, mysqlx::SqlStatement* psQuery);
    void setVariable(string value);
    void setVariable(double value);
    void setVariable( int value);
    Results* execute();
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
