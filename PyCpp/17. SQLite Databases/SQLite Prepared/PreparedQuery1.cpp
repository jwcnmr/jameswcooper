#include "PreparedQuery.h"
#include "Query.h"


PreparedQuery::PreparedQuery(sqltDatabase db, string query): 
	Query(db, query) 	{
		 int rc = sqlite3_prepare_v2(db.getDb(), query.c_str(), query.size(),
			 &stmt, nullptr);
		 checkerr(rc);
	}
void PreparedQuery::setVariable(int index, string value) {
	int rc = sqlite3_bind_text(stmt, 1,value.c_str(), value.length(), NULL);
	checkerr(rc);
}
void PreparedQuery::setVariable(int index, double value) {
	int rc = sqlite3_bind_text(stmt, 1, value.c_str(), value.length(), NULL);
	checkerr(rc);
}

int PreparedQuery::execute() {
	int rc = 0;
	while (SQLITE_ROW == (rc = sqlite3_step(stmt))) {
		const unsigned char* name = sqlite3_column_text(stmt, 0);
		const unsigned char* val = sqlite3_column_text(stmt, 1);
		std::cout << name << " is " << val << std::endl;
	}
	sqlite3_finalize(stmt);
	return 0;
