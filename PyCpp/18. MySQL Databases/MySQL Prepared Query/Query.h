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

