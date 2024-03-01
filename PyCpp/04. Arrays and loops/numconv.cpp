// numconv.cpp : 
// Examples of converting numbers and strings
// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iostream>
#include <format>
using std::string;
using std::stod;
using std::cout;
using std::endl;
using std::to_string;
using std::format;

int main()
{
		double x = 2.34;
		double y = 12;
		int k = (int)x;
		float f = y;	//compiler warning
		float f1 = (float)y;	//no warning
	
		//convert string to numbers	
		string snum = "123.4";
		double dnum = stod(snum);	//convert to double
		float fnum = stof(snum);	//convert to float
		int inum = stoi(snum);		//convert to int
		cout << dnum << " " << inum << endl;

		//convert number to string
		string newst = to_string(dnum);
		cout << newst << endl;

		string outf = format("{:.2f}", dnum );
		cout << outf << endl;


	
}

