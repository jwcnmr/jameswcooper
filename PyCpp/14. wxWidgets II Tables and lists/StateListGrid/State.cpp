#include <string>
#include <vector>

#include "State.h"
using std::string;
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
	void State::setName(string nm) {name = nm; }
	void State::setAbbrev(string ab) { abbrev = ab; };
	void State::setDate(string dt) { date = dt; };
	void State::setCapital(string cap) { capital = cap; };
	string State::getLineString() {
		return name + ", " + abbrev + ", " + capital + ", " + date;
	}


