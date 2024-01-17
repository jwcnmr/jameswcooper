<<<<<<< HEAD
#pragma once
#include "globaldefs.h"
#include "msqDatabase.h"
#include "Query.h"
#include "Results.h"


class Query
{
protected:
	//sqlite3_stmt* stmt{ NULL };
	string sql;
	msqDatabase* db;
	mysqlx::SqlStatement* sqQuery;
	mysqlx::Session* session;
	vector <dbMap*>* stpRows{ NULL };
	dbMap* stpRow{ NULL };
	vector<string>* prepqueries;
	
public:
	Query(msqDatabase* db, string query);
	Query() = default;
	Results* execute();
	void closeStatement();
	void rewindStatement();
	string makeString(mysqlx::Value r);

};

=======
#pragma once
#include "globaldefs.h"
#include "msqDatabase.h"
#include "Query.h"
#include "Results.h"


class Query
{
protected:
	//sqlite3_stmt* stmt{ NULL };
	string sql;
	msqDatabase* db;
	mysqlx::SqlStatement* sqQuery;
	mysqlx::Session* session;
	vector <dbMap*>* stpRows{ NULL };
	dbMap* stpRow{ NULL };
	vector<string>* prepqueries;
	
public:
	Query(msqDatabase* db, string query);
	Query() = default;
	Results* execute();
	void closeStatement();
	void rewindStatement();
	string makeString(mysqlx::Value r);

};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
