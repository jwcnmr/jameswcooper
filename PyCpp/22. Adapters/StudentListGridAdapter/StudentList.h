#pragma once
#include "baseincludes.h"
#include "Student.h"
using std::vector;
class StudentList :
    public wxListBox
{
private:
    vector<Student*> students;
public:
    ~StudentList() {
        
    }
    StudentList(wxPanel* panel, wxSize size);
    void append(Student* st);
    void redraw();
    void remove(int index);
    Student* getSelected();

};

