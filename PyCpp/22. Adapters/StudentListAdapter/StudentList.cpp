#include "StudentList.h"
StudentList::StudentList(wxPanel* panel, wxSize size):
    wxListBox(panel, wxID_ANY, wxDefaultPosition, size, 0, 
		NULL, 0L, wxDefaultValidator) {}

//append a new Student to vector
//and add a string to the list box
void StudentList::append(Student* st) {
	students.push_back(st);	//create vector of student objects
	Append(st->getName());	//display name
}
//redraw the listbox after any change
void StudentList::redraw() {
	Clear();
	for (int i = 0; i < students.size(); i++) {
		Append(students[i]->getName());
	}
}
//remove a student from the vector and the list
void StudentList::remove(int index) {
	students.erase(students.begin() + index);
	redraw(); 
}
//return the student currently selected
Student* StudentList::getSelected() {
	int index = GetSelection();		//index of selection
	Student* std = students[index]; //get that Student 
	return std;
}