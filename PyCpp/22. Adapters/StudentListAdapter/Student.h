#pragma once
#include <random>
#include "baseincludes.h"
class Student {
	static int randint(int min, int max) {
		int value = rand();
		int range = value % (max - min);
		return range + min;
	}
private:
	string name;
	string frname{ "" };
	string lname{" "};
	int iq;
	int score;
public:
	Student(wxString nm);
	string getName();
	int getIQ();
	int getScore();
};