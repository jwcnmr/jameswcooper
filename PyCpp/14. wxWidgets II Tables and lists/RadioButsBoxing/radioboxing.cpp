// wxWidgets "Checkbox" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "BlueLabel.h"

using std::string;

class Builder : public wxApp

{
private:

    wxRadioButton* cred;
    wxRadioButton* cblue;
    wxRadioButton* cgreen;
    wxRadioBox* rbox;

    wxBoxSizer* leftChecks;
    BlueLabel* topLabel;
    wxButton* checkButns;
public:
    bool OnInit();
    wxRadioButton* addCheck(wxPanel*, std::string label);
    void OnClick(wxCommandEvent& event);
};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Checking");
    frame->SetBackgroundColour(0xefefef);
    frame->SetSize(120, 200);

    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

    frame->SetSizer(bxs);

    wxPanel* leftPanel = new wxPanel(frame, wxID_ANY);
    bxs->Add(leftPanel);

    leftChecks = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(leftChecks);
    leftChecks->AddSpacer(10);
    topLabel = new BlueLabel(leftPanel, wxID_ANY, "     ");
    leftChecks->Add(topLabel, 0, wxALIGN_CENTER_HORIZONTAL, 10);
  
    
    wxArrayString strings;
    strings.Add(wxT("Red"));
    strings.Add(wxT("Green"));
    strings.Add(wxT("Blue"));
   

    rbox = new wxRadioBox(leftPanel, wxID_ANY, wxT("Colors"), 
       wxDefaultPosition,wxDefaultSize, strings, 3, wxRA_SPECIFY_ROWS);
       
    leftChecks->Add(rbox, 0, wxALIGN_CENTER_HORIZONTAL, 10);

    checkButns = new wxButton(leftPanel, wxID_ANY, "Check");
    leftChecks->Add(checkButns, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    checkButns->Bind(wxEVT_BUTTON, &Builder::OnClick, this);

    bxs->Show(true);
    frame->Show(true);
    return true;
}

void Builder::OnClick(wxCommandEvent& event) {
    wxString cbut = rbox->GetStringSelection();
    topLabel->SetLabelText(cbut);
}

