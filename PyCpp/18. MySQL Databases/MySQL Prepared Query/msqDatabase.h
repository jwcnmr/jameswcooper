<<<<<<< HEAD
#pragma once
#include "Database.h"
#include "globaldefs.h"
#include <mysqlx/xdevapi.h>
#include <vector>

using std::vector;
using std::string;
    
class msqDatabase :public Database
{
private:  
    mysqlx::Session* session;
    string dbName;
    mysqlx::Schema* db;  //actual database
    void setSchema();  

public:
    msqDatabase(string host, int port, string user, string password);
    msqDatabase();
    mysqlx::Session* getSession();
    mysqlx::SqlStatement getSqlStatement(string sql);
    mysqlx::SqlStatement* psqStatement;
    
    int open(string name);
    int create(string name, bool del =true);
    string getName();
    void close();
    vector<string> getTableNames();
    void runSql(string sqltext);
    mysqlx::SqlResult runQuery(string sqltext); 

};

=======
#pragma once
#include "Database.h"
#include "globaldefs.h"
#include <mysqlx/xdevapi.h>
#include <vector>

using std::vector;
using std::string;
    
class msqDatabase :public Database
{
private:  
    mysqlx::Session* session;
    string dbName;
    mysqlx::Schema* db;  //actual database
    void setSchema();  

public:
    msqDatabase(string host, int port, string user, string password);
    msqDatabase();
    mysqlx::Session* getSession();
    mysqlx::SqlStatement getSqlStatement(string sql);
    mysqlx::SqlStatement* psqStatement;
    
    int open(string name);
    int create(string name, bool del =true);
    string getName();
    void close();
    vector<string> getTableNames();
    void runSql(string sqltext);
    mysqlx::SqlResult runQuery(string sqltext); 

};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
