#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "States.h"

using std::string;
using std::ifstream;

States::States(string fileName) {

	ifstream myfile(fileName);
	string line;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			states.push_back(new State(line));
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}
vector<State*> States::getStates() {
	return states;
}
State* States::getState(int index) {
	return states[index];
}