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
	State(string line);
	string getName();
	string getAbbrev();
	string getDate();	
	string getCapital();
	void setName(string nm);
	void setAbbrev(string ab);
	void setDate(string dt);
	void setCapital(string cap);
	string getLineString();

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
	State(string line);
	string getName();
	string getAbbrev();
	string getDate();	
	string getCapital();
	void setName(string nm);
	void setAbbrev(string ab);
	void setDate(string dt);
	void setCapital(string cap);
	string getLineString();

};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
