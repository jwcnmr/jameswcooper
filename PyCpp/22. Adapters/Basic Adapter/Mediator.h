#pragma once

#include "baseincludes.h"
#include "DButton.h"
class RestoreButton;  //resolves forward references
class MoveButton;
class ClearButton;

// The Mediator mediates listbox and button click events
class Mediator {
private:

    wxListBox* listbox;
    wxListBox* advListBox;
    wxFrame* frame;
    MoveButton* moveButton;
    RestoreButton* restoreButton;
    ClearButton* clearButton;
    vector<wxString> names;

public:
    Mediator(wxFrame* gframe, wxListBox* studlist, wxListBox* advlist);
    void onListClick(wxCommandEvent& event);
    void advListClick(wxCommandEvent& event);
    void moveClick();
    void restoreClick();
    void clearClick();
    void reset();
    void setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clrb);

};
