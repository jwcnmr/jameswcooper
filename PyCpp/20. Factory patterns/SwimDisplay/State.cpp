<<<<<<< HEAD
#include "State.h"
#include <vector>
#include "Strfuncs.h"
using std::vector;

	State::State(std::string line) {
		vector<std::string> tokens = Strfuncs::split(line, ",");
		name = tokens[0];
		abbrev = tokens[1];
		date = tokens[2];
		capital = tokens[3];
	}
	string State::getName() { return name; }
	string State::getAbbrev() { return abbrev; }
	string State::getDate() { return date; }
	string State::getCapital() { return capital; }
=======
#include "State.h"
#include <vector>
#include "Strfuncs.h"
using std::vector;

	State::State(std::string line) {
		vector<std::string> tokens = Strfuncs::split(line, ",");
		name = tokens[0];
		abbrev = tokens[1];
		date = tokens[2];
		capital = tokens[3];
	}
	string State::getName() { return name; }
	string State::getAbbrev() { return abbrev; }
	string State::getDate() { return date; }
	string State::getCapital() { return capital; }
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
