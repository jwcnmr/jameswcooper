<<<<<<< HEAD
#pragma once

#include <string>
#include <vector>
#include "StrFuncs.h"

using std::string;

class State {
private:
	string name;
	string abbrev;
	string date;
	string capital;


public:
	State(std::string line);
	string getName();
	string getAbbrev();
	string getDate();	
	string getCapital();

};
=======
#pragma once

#include <string>
#include <vector>
#include "StrFuncs.h"

using std::string;

class State {
private:
	string name;
	string abbrev;
	string date;
	string capital;


public:
	State(std::string line);
	string getName();
	string getAbbrev();
	string getDate();	
	string getCapital();

};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
