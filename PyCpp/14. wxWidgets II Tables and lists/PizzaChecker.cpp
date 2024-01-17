<<<<<<< HEAD
// Simple pizza ordering program
// illustrates checkboxes
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
#include "wx/checkbox.h"
#include <vector>
#include <format>
#endif
using std::vector;
using std::string;


//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxPanel* leftPanel{NULL};
    wxPanel* rightPanel{NULL};
    wxBoxSizer* fSizer{ NULL };
    wxBoxSizer* leftSizer{NULL};
    wxBoxSizer* rightSizer{NULL};
    vector<wxCheckBox*> checks;
    wxCheckBox* cb {NULL};
    wxListBox* orderList{NULL};

public:
    
    void OnClick(wxCommandEvent& event);    // Add button event
    void OnClear(wxCommandEvent& event);    // clear button event
    wxCheckBox* addCheckBox(string label, wxSizer* leftChecks);
   
    bool OnInit()                           // places the widgets in a layout
    {
        const int width = 300;
        const int height = 250;
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Order pizza");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(width, height);
       
                        
        fSizer = new wxBoxSizer(wxHORIZONTAL);
        frame->SetSizer(fSizer);
        leftPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width/2, height));
        rightPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width / 2, height));
        fSizer->Add(leftPanel);
        fSizer->Add(rightPanel);
        
        leftSizer = new wxBoxSizer(wxVERTICAL);
        leftPanel->SetSizer(leftSizer);
        leftSizer->AddSpacer(20);
        addCheckBox("Pepperoni", leftSizer);
        addCheckBox("Sausage", leftSizer);
        addCheckBox("Mushroom", leftSizer);
        addCheckBox("Onion", leftSizer);
        addCheckBox("Red peppers", leftSizer);
        wxCheckBox* pine = addCheckBox("Pineapple", leftSizer);
        pine->Disable();
        Bind(wxEVT_COMMAND_CHECKBOX_CLICKED, &Builder::OnClick, this);

        rightSizer = new wxBoxSizer(wxVERTICAL);
        rightPanel->SetSizer(rightSizer);
        rightSizer->AddSpacer(20);
        orderList = new wxListBox(rightPanel, wxID_ANY,
            wxDefaultPosition, wxSize(width/2, height/2));
        rightSizer->Add(orderList);
       
       
             
        // Clear button
        wxButton* clearButton = new wxButton(rightPanel, wxID_ANY, "Clear");   
        rightSizer->Add(clearButton);
        clearButton->Bind(wxEVT_BUTTON, &Builder::OnClear, this);       
        frame->Show(true);
        return true;
    }

};
   

wxIMPLEMENT_APP(Builder);


// Clear button click event
//clears the listbox and unchecks all the checkboxes
void Builder::OnClear(wxCommandEvent& event) {
    orderList->Clear();
    for (int i = 0; i < checks.size(); i++) {
        cb = checks.at(i);
        cb->SetValue(false);
    }
}
//fills list with currently checked items
void Builder::OnClick(wxCommandEvent& event) {
    wxCheckBox* cb1;
    orderList->Clear();     //clear the listbof
    //and re-fill it from the checkboxes
    for (int i = 0; i < checks.size(); i++) {
        cb1 = checks.at(i);
        if (cb1->IsChecked()) {
            wxString label = cb1->GetLabel();
            orderList->InsertItems(1, &label, 0);
        }
    }
}
//Adds a checkbox to the left panel's sizer
wxCheckBox* Builder::addCheckBox(string label, wxSizer* leftChecks) {
    wxCheckBox* cb1 = new wxCheckBox(leftPanel, wxID_ANY, wxString(label));
    leftChecks->Add(cb1);
    leftChecks->AddSpacer(5);
    checks.push_back(cb1);      //and to the vector list
    return cb1;
};


=======
// Simple pizza ordering program
// illustrates checkboxes
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
#include "wx/checkbox.h"
#include <vector>
#include <format>
#endif
using std::vector;
using std::string;


//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxPanel* leftPanel{NULL};
    wxPanel* rightPanel{NULL};
    wxBoxSizer* fSizer{ NULL };
    wxBoxSizer* leftSizer{NULL};
    wxBoxSizer* rightSizer{NULL};
    vector<wxCheckBox*> checks;
    wxCheckBox* cb {NULL};
    wxListBox* orderList{NULL};

public:
    
    void OnClick(wxCommandEvent& event);    // Add button event
    void OnClear(wxCommandEvent& event);    // clear button event
    wxCheckBox* addCheckBox(string label, wxSizer* leftChecks);
   
    bool OnInit()                           // places the widgets in a layout
    {
        const int width = 300;
        const int height = 250;
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Order pizza");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(width, height);
       
                        
        fSizer = new wxBoxSizer(wxHORIZONTAL);
        frame->SetSizer(fSizer);
        leftPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width/2, height));
        rightPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width / 2, height));
        fSizer->Add(leftPanel);
        fSizer->Add(rightPanel);
        
        leftSizer = new wxBoxSizer(wxVERTICAL);
        leftPanel->SetSizer(leftSizer);
        leftSizer->AddSpacer(20);
        addCheckBox("Pepperoni", leftSizer);
        addCheckBox("Sausage", leftSizer);
        addCheckBox("Mushroom", leftSizer);
        addCheckBox("Onion", leftSizer);
        addCheckBox("Red peppers", leftSizer);
        wxCheckBox* pine = addCheckBox("Pineapple", leftSizer);
        pine->Disable();
        Bind(wxEVT_COMMAND_CHECKBOX_CLICKED, &Builder::OnClick, this);

        rightSizer = new wxBoxSizer(wxVERTICAL);
        rightPanel->SetSizer(rightSizer);
        rightSizer->AddSpacer(20);
        orderList = new wxListBox(rightPanel, wxID_ANY,
            wxDefaultPosition, wxSize(width/2, height/2));
        rightSizer->Add(orderList);
       
       
             
        // Clear button
        wxButton* clearButton = new wxButton(rightPanel, wxID_ANY, "Clear");   
        rightSizer->Add(clearButton);
        clearButton->Bind(wxEVT_BUTTON, &Builder::OnClear, this);       
        frame->Show(true);
        return true;
    }

};
   

wxIMPLEMENT_APP(Builder);


// Clear button click event
//clears the listbox and unchecks all the checkboxes
void Builder::OnClear(wxCommandEvent& event) {
    orderList->Clear();
    for (int i = 0; i < checks.size(); i++) {
        cb = checks.at(i);
        cb->SetValue(false);
    }
}
//fills list with currently checked items
void Builder::OnClick(wxCommandEvent& event) {
    wxCheckBox* cb1;
    orderList->Clear();     //clear the listbof
    //and re-fill it from the checkboxes
    for (int i = 0; i < checks.size(); i++) {
        cb1 = checks.at(i);
        if (cb1->IsChecked()) {
            wxString label = cb1->GetLabel();
            orderList->InsertItems(1, &label, 0);
        }
    }
}
//Adds a checkbox to the left panel's sizer
wxCheckBox* Builder::addCheckBox(string label, wxSizer* leftChecks) {
    wxCheckBox* cb1 = new wxCheckBox(leftPanel, wxID_ANY, wxString(label));
    leftChecks->Add(cb1);
    leftChecks->AddSpacer(5);
    checks.push_back(cb1);      //and to the vector list
    return cb1;
};


>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
