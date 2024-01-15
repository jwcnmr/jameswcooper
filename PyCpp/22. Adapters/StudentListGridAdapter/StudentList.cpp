#include "StudentList.h"
StudentList::StudentList(wxPanel* panel, wxSize size):
wxListBox(panel, wxID_ANY, wxDefaultPosition, size, 0, NULL, 0L, wxDefaultValidator) {}

void StudentList::append(Student* st) {
	students.push_back(st);	//create vector of student objects
	Append(st->getName());	//display name

}
void StudentList::redraw() {
	Clear();
	for (int i = 0; i < students.size(); i++) {
		Append(students[i]->getName());
	}
}
void StudentList::remove(int index) {
	students.erase(students.begin() + index);
	redraw();
}
Student* StudentList::getSelected() {
	int index = GetSelection();
	Student* std = students[index];
	return std;
}