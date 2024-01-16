#pragma once
#include "baseincludes.h"
#include "Mediator.h"
class Mediator;  //forward reference resolved
class DButton : public wxButton {

// The Mediator class actually executes the code for all button clicks
protected:
    Mediator* med;

public:
    DButton(wxPanel* panel, int id, const std::string label, Mediator* med) ;   

    //abstract method to be completed in derived classes 
    virtual void comd(wxCommandEvent& event) = 0;
};

//clicks on each button go to the Mediator 
//which moves a name to the right listbox
class MoveButton :public DButton {
public:
    MoveButton(wxPanel* panel, Mediator* med);
    void comd(wxCommandEvent& event);
};

class RestoreButton :public DButton {
public:
    RestoreButton(wxPanel* panel, Mediator* med);
    void comd(wxCommandEvent& event);
};

class ClearButton :public DButton {
public:
    ClearButton(wxPanel* panel, Mediator* med);
    void comd(wxCommandEvent& event);
};