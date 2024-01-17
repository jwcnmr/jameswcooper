<<<<<<< HEAD
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
    StudentList(wxPanel* panel, wxSize size);
    void append(Student* st);
    void redraw();
    void remove(int index);
    Student* getSelected();
};

=======
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
    StudentList(wxPanel* panel, wxSize size);
    void append(Student* st);
    void redraw();
    void remove(int index);
    Student* getSelected();
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
