#pragma once
#include <string>
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