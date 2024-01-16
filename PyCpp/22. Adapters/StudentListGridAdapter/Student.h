#pragma once
#include <random>
#include "baseincludes.h"
class Student {
	//static random numbeer generator
	static int randint(int min, int max) {
		int value = rand(); // rand in 0 to 1.0
		int range = value % (max - min); //range
		return range + min;	//add min 
	}
private:
	string name;
	string frname{ "" };
	string lname{" "};
	int iq;
	int score;
public:
	Student(wxString nm);
	string getName();	//get full name
	int getIQ();		//get IQ		
	int getScore();		//get test score 	
	string getFrname(); //get first name
	string getLname();	//get last name
};