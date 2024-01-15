#pragma once
#include "globaldefs.h"
#include "sqltDatabase.h"
#include <tuple>

//The base Column class
// derived types include, integer, primary, string and float
//abstract base class
class Column {
protected:
	string colname;			//the name
	bool primary{ false };  //and whether it's primary

public:
	Column(string name);
	bool isPrimary();
	string name();
	virtual string getSql()=0; //derived classes fill this one in
};

//The Integer column class --derived from Column

class IntCol :public Column {
public:
	IntCol(string name);
	string getSql(); 
};

//The character column CharCol has a name and width
class CharCol : public Column {
private:
	int width{ 0 };
public:
	CharCol(string name, int cwidth);
	string getSql();
};

//A primary column is usually the key column
// usually is auto incremented
class PrimaryCol :public Column {
private:
	bool autoinc;
public:
	PrimaryCol(string name, bool auto_inc = true);
	string getSql();
};

//Holds float values
class FloatCol :public Column {
public:
	FloatCol(string name);
	string getSql();
};

//The base table class
class Table {
protected:
	string tbName;
	sqltDatabase db;
	string primaryString{ "" };
	vector<Column*> columns;
public:
	Table(string name, sqltDatabase sqdb);
	string name();
	void addColumn(Column* column);
	void create();
	int addRow(string tables, string values);
	int getKey(string keyname, string column, string value);
};