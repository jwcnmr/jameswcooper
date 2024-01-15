#include "globaldefs.h"
#include "Query.h"

//create a query-

Query::Query(msqDatabase* datab, string query){
	sql = query;
	db = datab;
	session = db->getSession();
}

//convert row Value into a string 
//by checking its type
string Query::makeString(mysqlx::Value r) {
	string sval = "";
	int itype = r.getType();
	if (itype == r.FLOAT) {
		float val = float(r);
		sval = std::to_string(val);
	}
	if (itype == r.INT64) {
		int val = int(r);
		sval = std::to_string(val);
	}
	if (itype == r.STRING) {
		string val = string(r);
		sval = val;
	}
	return sval;
}

//execute the query and get back the column names and values
Results* Query::execute() {
	stpRows = new vector<dbMap*>;	//vector of rows	
	mysqlx::SqlResult res = db->runQuery(sql); //run the query
	const mysqlx::Columns& columns = res.getColumns(); //get the columns
	mysqlx::Row row;
	while ((row = res.fetchOne())) {
		dbMap* stpRow = new dbMap;	//create a map for this row
		for (unsigned index = 0; index < res.getColumnCount(); index++) {		
			string s1 = columns[index].getColumnName();
			stpRow->insert({ s1, row[index]});  //add to current map
		}
		stpRows->push_back(stpRow);	//add complete row to vector
	}	
	return new Results(stpRows);  //return Results object
}

void Query::closeStatement(){
	//sqlite3_finalize(stmt);
}
void Query::rewindStatement() {
	//sqlite3_reset(stmt);
}