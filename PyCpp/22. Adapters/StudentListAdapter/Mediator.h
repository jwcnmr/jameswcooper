#pragma once

#include "baseincludes.h"
#include "DButton.h"
#include "Student.h"
#include "StudentList.h"
class RestoreButton;  //resolves forward references
class MoveButton;
class ClearButton;

// The Mediator mediates listbox and button click events
class Mediator {
private:

    StudentList* listbox;
    StudentList* advListBox;
    wxFrame* frame;
    MoveButton* moveButton;
    RestoreButton* restoreButton;
    ClearButton* clearButton;
    vector<Student*> students;
    vector <Student*> advStudents;

public:
    Mediator(wxFrame* gframe, StudentList* studlist, StudentList* advlist);
    void onListClick(wxCommandEvent& event);
    void advListClick(wxCommandEvent& event);
    void moveClick();
    void restoreClick();
    void clearClick();
    void reset();
    void redraw();
    void setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clrb);

};
