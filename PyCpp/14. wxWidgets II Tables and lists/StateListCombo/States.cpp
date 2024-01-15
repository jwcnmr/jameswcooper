#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "States.h"

using namespace std;

States::States(string fileName) {

	std::ifstream myfile(fileName);
	std::string line;
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