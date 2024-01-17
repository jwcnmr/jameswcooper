<<<<<<< HEAD
#include "globaldefs.h"
#include "msqDatabase.h"

#include <iostream>
using mysqlx::Session;
using mysqlx::Schema;
using mysqlx::SqlStatement;
using std::cout;
using std::endl;

// Create a session to connect to the MySQL Server
msqDatabase::msqDatabase(string host, int port, string user, string password) { 
    session = new Session(host, port, user, password);   
}
//get a pointer to the current session
mysqlx::Session* msqDatabase::getSession() {
    return session;
}

//return an SqlStatement object
mysqlx::SqlStatement msqDatabase::getSqlStatement(string sqlp) {
    return session->sql(sqlp);
}
msqDatabase::msqDatabase() = default;

//Select the database (schema) to work with
void msqDatabase::setSchema() {
    session->sql("USE " + dbName).execute();
    auto mySchema = session->getSchema(dbName);
    db = &mySchema;
}


//open database (schema)
int msqDatabase::open(string name) {
    dbName = name;
    setSchema();
    return 0;
}

//create new database, delete prior vsn if del is true
int msqDatabase::create(string name, bool del) {
    dbName = name;
    if (del) {
        session->sql("DROP DATABASE IF EXISTS "+ dbName).execute();
    }
    session->sql("create database " + dbName).execute();
    setSchema();
    return 0;
}

//get the name of the database (schema)
string msqDatabase::getName() {
    return dbName;
}
//close the session
void msqDatabase::close() {
    session->close();
}

//get the names of all tables
vector<string> msqDatabase::getTableNames() {
    return db->getTableNames();
}
//runs any sql that does not produce a Result
void msqDatabase::runSql(string sqltext) {
    session->sql(sqltext).execute();
}

//run any sql that returns an SqlResult
mysqlx::SqlResult msqDatabase::runQuery(string sqltext) {
    return session->sql(sqltext).execute();
=======
#include "globaldefs.h"
#include "msqDatabase.h"

#include <iostream>
using mysqlx::Session;
using mysqlx::Schema;
using mysqlx::SqlStatement;
using std::cout;
using std::endl;

// Create a session to connect to the MySQL Server
msqDatabase::msqDatabase(string host, int port, string user, string password) { 
    session = new Session(host, port, user, password);   
}
//get a pointer to the current session
mysqlx::Session* msqDatabase::getSession() {
    return session;
}

//return an SqlStatement object
mysqlx::SqlStatement msqDatabase::getSqlStatement(string sqlp) {
    return session->sql(sqlp);
}
msqDatabase::msqDatabase() = default;

//Select the database (schema) to work with
void msqDatabase::setSchema() {
    session->sql("USE " + dbName).execute();
    auto mySchema = session->getSchema(dbName);
    db = &mySchema;
}


//open database (schema)
int msqDatabase::open(string name) {
    dbName = name;
    setSchema();
    return 0;
}

//create new database, delete prior vsn if del is true
int msqDatabase::create(string name, bool del) {
    dbName = name;
    if (del) {
        session->sql("DROP DATABASE IF EXISTS "+ dbName).execute();
    }
    session->sql("create database " + dbName).execute();
    setSchema();
    return 0;
}

//get the name of the database (schema)
string msqDatabase::getName() {
    return dbName;
}
//close the session
void msqDatabase::close() {
    session->close();
}

//get the names of all tables
vector<string> msqDatabase::getTableNames() {
    return db->getTableNames();
}
//runs any sql that does not produce a Result
void msqDatabase::runSql(string sqltext) {
    session->sql(sqltext).execute();
}

//run any sql that returns an SqlResult
mysqlx::SqlResult msqDatabase::runQuery(string sqltext) {
    return session->sql(sqltext).execute();
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}