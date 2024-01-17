<<<<<<< HEAD
#pragma once

#include <string>
#include <vector>

class Strfuncs {
	//trim a string to remove whitespace
	//characters from the beginning and end
public:
	static std::string strip(std::string line);

	//Split a string at the delimiter into a vector of strings,
	// each stripped of whitespace
	static std::vector<std::string> split(std::string line, std::string delim);
	static std::string to_Lower(std::string str);
};
=======
#pragma once

#include <string>
#include <vector>

class Strfuncs {
	//trim a string to remove whitespace
	//characters from the beginning and end
public:
	static std::string strip(std::string line);

	//Split a string at the delimiter into a vector of strings,
	// each stripped of whitespace
	static std::vector<std::string> split(std::string line, std::string delim);
	static std::string to_Lower(std::string str);
};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
