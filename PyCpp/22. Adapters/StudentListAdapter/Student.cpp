<<<<<<< HEAD
#include "Student.h"
#include "StrFuncs.h"
Student::Student(wxString nm) {	
	score = Student::randint(25, 35);
	iq = Student::randint(115, 145);
	name = nm;
	//assume there are two names separated by a space
	vector<string> names = Strfuncs::split(name, " ");
	frname = names[0];
	if(names.size() >1)
		lname = names[1];
}
string Student::getName() {
	return name;
}
int Student::getIQ() {
	return iq;
}
int Student::getScore() {
	return score;
=======
#include "Student.h"
#include "StrFuncs.h"
Student::Student(wxString nm) {	
	score = Student::randint(25, 35);
	iq = Student::randint(115, 145);
	name = nm;
	//assume there are two names separated by a space
	vector<string> names = Strfuncs::split(name, " ");
	frname = names[0];
	if(names.size() >1)
		lname = names[1];
}
string Student::getName() {
	return name;
}
int Student::getIQ() {
	return iq;
}
int Student::getScore() {
	return score;
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}