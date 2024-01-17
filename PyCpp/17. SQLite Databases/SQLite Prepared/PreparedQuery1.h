<<<<<<< HEAD
#pragma once
#include "globaldefs.h"
#include "sqltDatabase.h"
#include "Query.h"
class PreparedQuery:public Query
{
private:
	sqlite3_stmt* stmt{ NULL };
	
public:
	PreparedQuery(sqltDatabase db, string query);
	void setVariable(int index, string value);
	void setVariable(int index, double value);
	int execute();

};

=======
#pragma once
#include "globaldefs.h"
#include "sqltDatabase.h"
#include "Query.h"
class PreparedQuery:public Query
{
private:
	sqlite3_stmt* stmt{ NULL };
	
public:
	PreparedQuery(sqltDatabase db, string query);
	void setVariable(int index, string value);
	void setVariable(int index, double value);
	int execute();

};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
