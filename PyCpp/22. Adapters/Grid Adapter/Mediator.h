<<<<<<< HEAD
#pragma once

#include "baseincludes.h"
#include "DButton.h"
#include "GridAdapter.h"
class RestoreButton;  //resolves forward references
class MoveButton;
class ClearButton;

// The Mediator mediates listbox and button click events
class Mediator {
private:

    wxListBox* listbox;
    GridAdapter* advListBox;
    wxFrame* frame;
    MoveButton* moveButton;
    RestoreButton* restoreButton;
    ClearButton* clearButton;
    vector<wxString> names;
    int getGridrow();
    int gridRow;

public:
    Mediator(wxFrame* gframe, wxListBox* studlist, GridAdapter* advlist);
    void onListClick(wxCommandEvent& event);
    void advListClick(wxGridEvent& event);
    void moveClick();
    void restoreClick();
    void clearClick();
    void reset();
    void setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clrb);

};
=======
#pragma once

#include "baseincludes.h"
#include "DButton.h"
#include "GridAdapter.h"
class RestoreButton;  //resolves forward references
class MoveButton;
class ClearButton;

// The Mediator mediates listbox and button click events
class Mediator {
private:

    wxListBox* listbox;
    GridAdapter* advListBox;
    wxFrame* frame;
    MoveButton* moveButton;
    RestoreButton* restoreButton;
    ClearButton* clearButton;
    vector<wxString> names;
    int getGridrow();
    int gridRow;

public:
    Mediator(wxFrame* gframe, wxListBox* studlist, GridAdapter* advlist);
    void onListClick(wxCommandEvent& event);
    void advListClick(wxGridEvent& event);
    void moveClick();
    void restoreClick();
    void clearClick();
    void reset();
    void setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clrb);

};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
