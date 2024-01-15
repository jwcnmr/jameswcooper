// Simple addition program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/button.h"
#include <format>
#include "BlueLabel.h"
#endif
using std::format;
using std::string;


//----Creates the entry fields, labels and buttons

class Builder : public wxApp {
private:
    wxTextCtrl* num1{ NULL };    //number field 1
    wxTextCtrl* num2 = NULL;    //number fiels 2
    BlueLabel* sumLbl = NULL;   //label where sum is displayed
    wxPanel* panel = NULL;


public:
    void addClicked(wxCommandEvent& event);      // Add button event
    void clearClicked(wxCommandEvent& event);    // clear button event
    bool OnInit();
};

/* This abstract class defines a button with a comd method this is called
when it is clicked.  Derived classes need only fill in the comd method*/

class DButton : public wxButton {
protected:
    Builder* bld;

public:
    DButton(wxPanel* panel, int id, const std::string label, Builder* bld, wxApp* app) :
        wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize) 
    {
        this->bld = bld;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }

    //abstract method to be completed in derived classes 
    virtual void comd(wxCommandEvent& event) {}

};

// causes the addition
class AddButton : public DButton {
public:
    AddButton(wxPanel* panel, int id, Builder* bld, wxApp* app) :
        DButton(panel, id, std::string("Add"), bld, app) {}

    void comd(wxCommandEvent& event) {
        bld->addClicked(event);
    }
};

//clears the entry fields and sum labell
class ClearButton : public DButton {
public:
    ClearButton(wxPanel* panel, int id,
        Builder* bld, wxApp* app) :
        DButton(panel, id, "Clear", bld, app) {}

    void comd(wxCommandEvent& event) {
        bld->clearClicked(event);
    }
};


wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::addClicked(wxCommandEvent& event) {
    string st1 = num1->GetLineText(0).ToStdString();
    string st2 = num2->GetLineText(0).ToStdString();

    double sum = stod(st1) + stod(st2);
    string st3 = "Sum is: " + format("{:5g}", sum);
    sumLbl->SetLabel(st3);
}

// Clear button click event
void Builder::clearClicked(wxCommandEvent& event) {
    num1->SetLabel("");
    num2->SetLabel("");
    sumLbl->SetLabel("Sum is:");
}

bool Builder:: OnInit()  {                         // places the widgets in a layout

    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Add numbers");
    frame->SetBackgroundColour(0xcfcfcf);
    frame->SetSize(320, 275);

    panel = new wxPanel(frame, wxID_ANY);

    wxGridBagSizer* gbs = new wxGridBagSizer(10, 10);
    panel->SetSizer(gbs);

    BlueLabel* topTitle = 
        new BlueLabel(panel, wxID_ANY, wxT("Add 2 numbers"));
    gbs->Add(topTitle, wxGBPosition(1, 1), 
        wxGBSpan(1, 3));

    //first label and entry field
    BlueLabel* lineLabel = new BlueLabel(panel, wxID_ANY, "  First num:   ");
    gbs->Add(lineLabel, wxGBPosition(2, 0));
    
    num1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
    gbs->Add(this->num1, wxGBPosition(2, 1), wxGBSpan(1, 2));

    //second label and entry field
    BlueLabel* lineLabel2 = new BlueLabel(panel, wxID_ANY, "  Second num:   ");
    gbs->Add(lineLabel2, wxGBPosition(3, 0));
    
    num2 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
    gbs->Add(num2, wxGBPosition(3, 1), wxGBSpan(1, 2));

    // Add button
    AddButton* addButton = new AddButton(panel, wxID_ANY, this, this);
    gbs->Add(addButton, wxGBPosition(4, 0), 
        wxGBSpan(1, 2), wxALIGN_CENTER_HORIZONTAL);


    // Clear button
    ClearButton* clearButton = new ClearButton(panel, wxID_ANY, this, this);
    wxSizerItem* obj = gbs->Add(clearButton, wxGBPosition(4, 2), 
        wxGBSpan(1, 2), wxALIGN_LEFT);

        
    // sum label
    this->sumLbl = new BlueLabel(panel, wxID_ANY, "The Sum ");
    gbs->Add(sumLbl, wxGBPosition(5, 1));

    frame->Show(true);

    return true;
}




