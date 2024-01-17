<<<<<<< HEAD
#include "globaldefs.h"
#include "PreparedQuery.h"


msqPreparedQuery::msqPreparedQuery(msqDatabase* pdb, mysqlx::SqlStatement* psQuery):Query(pdb, "")  {
	sqQuery = psQuery;
	db = pdb;
}

//bind a text value to the query
void msqPreparedQuery::setVariable(string value) {
	sqQuery->bind(value);
}
//bind a double value to the query
void msqPreparedQuery::setVariable(double value) {
	sqQuery->bind(value);
}
//bind an int value to the query
void msqPreparedQuery::setVariable(int value) {
	sqQuery->bind(value);
}

//execute the query and get back the column names and values
Results* msqPreparedQuery::execute() {
	stpRows = new vector<dbMap*>;	//vector of rows
	mysqlx::SqlResult res = sqQuery->execute();		//run the bound query
	const mysqlx::Columns& columns = res.getColumns(); //get the columns
	mysqlx::Row row;
	while ((row = res.fetchOne())) {		//get the rows one by one
		dbMap* stpRow = new dbMap;
		//get each column
		for (unsigned index = 0; index < res.getColumnCount(); index++) {
			string s1 = columns[index].getColumnName();
			stpRow->insert({ s1, row[index]});  //add to current map
		}
		stpRows->push_back(stpRow);		//add to the list of rows
	}
	return new Results(stpRows);  //create Results
}

=======
#include "globaldefs.h"
#include "PreparedQuery.h"


msqPreparedQuery::msqPreparedQuery(msqDatabase* pdb, mysqlx::SqlStatement* psQuery):Query(pdb, "")  {
	sqQuery = psQuery;
	db = pdb;
}

//bind a text value to the query
void msqPreparedQuery::setVariable(string value) {
	sqQuery->bind(value);
}
//bind a double value to the query
void msqPreparedQuery::setVariable(double value) {
	sqQuery->bind(value);
}
//bind an int value to the query
void msqPreparedQuery::setVariable(int value) {
	sqQuery->bind(value);
}

//execute the query and get back the column names and values
Results* msqPreparedQuery::execute() {
	stpRows = new vector<dbMap*>;	//vector of rows
	mysqlx::SqlResult res = sqQuery->execute();		//run the bound query
	const mysqlx::Columns& columns = res.getColumns(); //get the columns
	mysqlx::Row row;
	while ((row = res.fetchOne())) {		//get the rows one by one
		dbMap* stpRow = new dbMap;
		//get each column
		for (unsigned index = 0; index < res.getColumnCount(); index++) {
			string s1 = columns[index].getColumnName();
			stpRow->insert({ s1, row[index]});  //add to current map
		}
		stpRows->push_back(stpRow);		//add to the list of rows
	}
	return new Results(stpRows);  //create Results
}

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
