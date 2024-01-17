<<<<<<< HEAD
#include "globaldefs.h"
#include "sqltDatabase.h"
#include "Query.h"
#include "Table.h"

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
			idname += "AUTOINCREMENT ";
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
	Table::Table(string name, sqltDatabase sqdb) {
		tbName = name;
		db = sqdb;	
	}
	//return the table name
	string Table::name() {
		return tbName;
	}
	// add any type of column
	void Table::addColumn(Column* column) {
		columns.push_back(column);
	}
	//create a table after the columns have been added
	//generates the SQL to create a table and the columns
	void Table::create() {
		string sql = "create table " +  tbName + " (";
		for (auto v : columns) {
			sql += v->getSql() + ", ";
			
		}
		//remove last trailing comma and space
		size_t index = sql.find_last_of(", ");
		sql = sql.erase(index-1);
		sql += ")";
		sqltQuery qry(db, sql);
		qry.execute();
	}
	//add a row to a table
	// colnames is a string listing the column names
	// values is a string listing values for each column
	int Table::addRow(string colNames, string values) {
		string sql = "insert into " + tbName ; 
		sql += " (" + colNames + ")";
		sql += "values (" + values + ")";
		sqltQuery qry(db, sql);
		qry.execute();
		return 0;
	}
	//convenience method to get a key value	
	int Table::getKey(string keyname, string column, string value) {
		//get the key from the column that has a given value
		//select storekey from tbname where storename = value"
		string sql = "select " + keyname + " from " + tbName + " where " + column + "=\""+value+"\"";
		sqltQuery keyQuery(db, sql);
		Results* res = keyQuery.execute();
		res->setCursor(0);
		dbMap m = res->getRow();
		string skey = m[keyname];
		int key = stoi(skey);
		return key;
	}
=======
#include "globaldefs.h"
#include "sqltDatabase.h"
#include "Query.h"
#include "Table.h"

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
			idname += "AUTOINCREMENT ";
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
	Table::Table(string name, sqltDatabase sqdb) {
		tbName = name;
		db = sqdb;	
	}
	//return the table name
	string Table::name() {
		return tbName;
	}
	// add any type of column
	void Table::addColumn(Column* column) {
		columns.push_back(column);
	}
	//create a table after the columns have been added
	//generates the SQL to create a table and the columns
	void Table::create() {
		string sql = "create table " +  tbName + " (";
		for (auto v : columns) {
			sql += v->getSql() + ", ";
			
		}
		//remove last trailing comma and space
		size_t index = sql.find_last_of(", ");
		sql = sql.erase(index-1);
		sql += ")";
		sqltQuery qry(db, sql);
		qry.execute();
	}
	//add a row to a table
	// colnames is a string listing the column names
	// values is a string listing values for each column
	int Table::addRow(string colNames, string values) {
		string sql = "insert into " + tbName ; 
		sql += " (" + colNames + ")";
		sql += "values (" + values + ")";
		sqltQuery qry(db, sql);
		qry.execute();
		return 0;
	}
	//convenience method to get a key value	
	int Table::getKey(string keyname, string column, string value) {
		//get the key from the column that has a given value
		//select storekey from tbname where storename = value"
		string sql = "select " + keyname + " from " + tbName + " where " + column + "=\""+value+"\"";
		sqltQuery keyQuery(db, sql);
		Results* res = keyQuery.execute();
		res->setCursor(0);
		dbMap m = res->getRow();
		string skey = m[keyname];
		int key = stoi(skey);
		return key;
	}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
