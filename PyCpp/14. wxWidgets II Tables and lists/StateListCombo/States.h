<<<<<<< HEAD
#pragma once
#include <string>
#include <vector>
#include "State.h"

using std::vector;

class States {
protected:
	vector<State*> states;

public:
	States(string fileName); 
	vector<State*> getStates();
	State* getState(int index);
};

=======
#pragma once
#include <string>
#include <vector>
#include "State.h"

using std::vector;

class States {
protected:
	vector<State*> states;

public:
	States(string fileName); 
	vector<State*> getStates();
	State* getState(int index);
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
