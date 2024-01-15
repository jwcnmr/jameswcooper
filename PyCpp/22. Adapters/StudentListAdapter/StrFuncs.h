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
};
