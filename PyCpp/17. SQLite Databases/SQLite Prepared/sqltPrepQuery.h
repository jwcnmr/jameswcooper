#pragma once
#include "globaldefs.h"
#include "sqltDatabase.h"
#include "Query.h"
class sqltPrepQuery:public sqltQuery
{
private:
	sqlite3_stmt* stmt{ NULL };
	string sval;	//used in bind_text 
	vector <dbMap*>* stpRows{ NULL };
	dbMap* stpRow{ NULL };
	vector<string>* prepqueries;
	
public:
	sqltPrepQuery(sqltDatabase db, string query);
	void setVariable(int index, string value);
	void setVariable(int index, double value);
	void setVariable(int index, int value);
	Results* execute();
	void closeStatement();
	void rewindStatement();

};

