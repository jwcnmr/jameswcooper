#pragma once
#include <string>
using std::string;
//Holds one producr name and count

class Product{
private:
	string name;	//product name
	string count;	//inventory or sales count
public:
	Product(const string nstring);
	string getName();	//return the name
	string getCount();	//return the count
};

