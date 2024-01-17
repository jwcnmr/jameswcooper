#include "globaldefs.h"
#include "msqDatabase.h"
//#include "Database.h"
#include "Query.h"
#include "msqTable.h"

#include <string>

using std::string;
using std::to_string;

// column types within any table --abstract base class
// derived types include, integer, primary, string and float

	Column::Column(string name) {
		colname = name;
	}
	string Column::name() {
		return colname;
	}
	bool Column::isPrimary() {
		return primary;
	}
	

	IntCol::IntCol(string name) :Column(name) {}
	string IntCol::getSql() {
		return colname + " INT NOT NULL ";
	}


	PrimaryCol::PrimaryCol(string name, bool auto_inc) :Column(name) {
		primary = true;
		autoinc = auto_inc;		
	}
	
	string PrimaryCol::getSql() {
		string idname = colname +
			" INTEGER NOT NULL PRIMARY KEY ";
		if (autoinc) {
			idname += "AUTO_INCREMENT ";
		}
		return idname;
	}

	
	CharCol::CharCol(string name, int cwidth) :Column(name) {
		width = cwidth;  //character string width
	}
	string CharCol::getSql() {
		string idname = colname + " VARCHAR(" + 
			to_string(width) + ") NOT NULL ";
		return idname;
	}
	FloatCol::FloatCol(string name) :Column(name) {
		
	}
	string FloatCol::getSql() {
		string idname = colname + " FLOAT NOT NULL ";
		return idname;
	}

//--------------------------
	msqTable::msqTable(string name, msqDatabase* sqdb) {
		tbName = name;
		db = sqdb;	
	}
	//return the table name
	string msqTable::name() {
		return tbName;
	}
	// add any type of column
	void msqTable::addColumn(Column* column) {
		columns.push_back(column);
	}
	//create a table after the columns have been added
	//generates the SQL to create a table and the columns
	void msqTable::create() {
		string runSql = "create table " +  tbName + " (";
		for (auto v : columns) {
			runSql += v->getSql() + ", ";
			
		}
		//remove last trailing comma and space
		size_t index = runSql.find_last_of(", ");
		runSql = runSql.erase(index-1);
		runSql += ")";
		db->runSql(runSql);
	}
	//add a row to a table
	// colnames is a string listing the column names
	// values is a string listing values for each column
	int msqTable::addRow(string colNames, string values) {
		string runSql = "insert into " + tbName ; 
		runSql += " (" + colNames + ")";
		runSql += "values (" + values + ")";
		Query qry(db, runSql);
		qry.execute();
		return 0;
	}
	//convenience method to get a key value	
	int msqTable::getKey(string keyname, string column, string value) {
		//get the key from the column that has a given value
		//select storekey from tbname where storename = value"
		string sql = "select " + keyname + " from " + tbName + " where " + column + "=\""+value+"\"";
		Query keyQuery(db, sql);
		Results* res = keyQuery.execute();
		res->setCursor(0);
		dbMap m = res->getRow();
		mysqlx::Value v = m[keyname];
		int key = int(v);
		return key;
	}
