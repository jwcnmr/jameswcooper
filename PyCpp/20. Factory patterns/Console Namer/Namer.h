#pragma once
#include <string>
using std::string;

class Namer
{
protected:
	string frname{ NULL };
	string lname{ NULL };

public:
	string getFrname();
	string getLname();

};

