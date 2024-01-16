#include "sqltPrepQuery.h"
#include "Query.h"
#include "Results.h"

//create a prepared query- The "stmt" variable holds the pointer
//to the resulting prepared statement.
sqltPrepQuery::sqltPrepQuery(sqltDatabase db, string query): 
	sqltQuery(db, query) 	{
	int rc = sqlite3_prepare_v2(db.getDb(), query.c_str(), 
		(int)query.size(), &stmt, NULL);
	prepqueries = new vector<string>;
	checkerr(rc);
}

//bind a text value to the query
void sqltPrepQuery::setVariable(int index, string value) { 
	sval = value;	//this MUST be a class level variable
	const char* val1 = sval.c_str(); 
	size_t sz = strlen(val1);
	int rc = sqlite3_bind_text(stmt, index, val1, (int)sz, SQLITE_TRANSIENT);
	checkerr(rc);
}
//bind a double value to the query
void sqltPrepQuery::setVariable(int index, double value) {
	int rc = sqlite3_bind_double(stmt, index, value);
	checkerr(rc);
}
//bind an int value to the query
void sqltPrepQuery::setVariable(int index, int value) {
	int rc = sqlite3_bind_int(stmt, index, value);
	checkerr(rc);
}

//execute the query and get back the column names and values
Results* sqltPrepQuery::execute() {
	stpRows = new vector<dbMap*>;	//vector of rows
	while (sqlite3_step(stmt) != SQLITE_DONE){	
		stpRow = new dbMap;		//map for one row
		for (int col = 0; col < sqlite3_column_count(stmt); col++) {
			const char* name = sqlite3_column_name(stmt, col);
			const unsigned char* val = sqlite3_column_text(stmt, col);
			string s1 = string(name);
			string s2 = string((const char*)val);
			//std::cout << name << " is " << val << std::endl;
			stpRow->insert({s1, s2});  //add to current map
		}
		//add that map to the row vector
		stpRows->push_back(stpRow);
	}	
	rewindStatement(); //comment this out if you prefer
	return new Results(stpRows);  //create Results
}
void sqltPrepQuery::closeStatement(){
	sqlite3_finalize(stmt);
}
void sqltPrepQuery::rewindStatement() {
	sqlite3_reset(stmt);
}