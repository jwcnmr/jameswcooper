<<<<<<< HEAD
//String functions

#include <string>
#include "StrFuncs.h"
#include <vector>
using namespace std;

string Strfuncs::strip(string line) {
	const string WHITESPACE = " \n\r\t\f\v";   //whitespace characters
	size_t first = line.find_first_not_of(WHITESPACE);
	size_t last = line.find_last_not_of(WHITESPACE) + 1;
	return line.substr(first, last);                //strip whitespaces
}

std::vector<string> Strfuncs::split(string line, string delim) {

	vector<string> tokens;            //create vector of tokens
	string fline = line;
	size_t start = 0;
	while (start >= 0 && start <= fline.size()) {
		start = line.find(delim, 0);
		string val = strip(line.substr(0, start));
		tokens.push_back(val);                  //add each token to vector
		line = strip(line.substr(start + 1, line.size()));
		int k = 0;
	}
	return tokens;

}
=======
//String functions

#include <string>
#include "StrFuncs.h"
#include <vector>
using namespace std;

string Strfuncs::strip(string line) {
	const string WHITESPACE = " \n\r\t\f\v";   //whitespace characters
	size_t first = line.find_first_not_of(WHITESPACE);
	size_t last = line.find_last_not_of(WHITESPACE) + 1;
	return line.substr(first, last);                //strip whitespaces
}

std::vector<string> Strfuncs::split(string line, string delim) {

	vector<string> tokens;            //create vector of tokens
	string fline = line;
	size_t start = 0;
	while (start >= 0 && start <= fline.size()) {
		start = line.find(delim, 0);
		string val = strip(line.substr(0, start));
		tokens.push_back(val);                  //add each token to vector
		line = strip(line.substr(start + 1, line.size()));
		int k = 0;
	}
	return tokens;

}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
