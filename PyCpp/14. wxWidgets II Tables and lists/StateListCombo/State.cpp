<<<<<<< HEAD
#include <string>
#include <vector>

#include "State.h"

using std::string;
using std::vector;

	State::State(std::string line) {
		vector<string> tokens = Strfuncs::split(line, ",");
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
#include <string>
#include <vector>

#include "State.h"

using std::string;
using std::vector;

	State::State(std::string line) {
		vector<string> tokens = Strfuncs::split(line, ",");
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
