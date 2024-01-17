<<<<<<< HEAD
#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Strfuncs {
	//trim a string to remove whitespace
	//characters from the beginning and end
public:
	static string strip(string line);

	//Split a string at the delimiter into a vector of strings,
	// each stripped of whitespace
	static vector<string> split(string line, string delim);
	static string to_Lower(string str);
};
=======
#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

class Strfuncs {
	//trim a string to remove whitespace
	//characters from the beginning and end
public:
	static string strip(string line);

	//Split a string at the delimiter into a vector of strings,
	// each stripped of whitespace
	static vector<string> split(string line, string delim);
	static string to_Lower(string str);
};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
