#pragma once
#include <string>
#include <vector>
#include "State.h"

using namespace std;

class States {
protected:
	vector<State*> states;

public:
	States(string fileName); 
	vector<State*> getStates();
	State* getState(int index);
};

