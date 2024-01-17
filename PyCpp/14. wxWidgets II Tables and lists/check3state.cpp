// wxWidgets "Checkbox" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/checkbox.h>

#endif


using std::string;

class Builder : public wxApp

{
private:

    wxCheckBox* cred;
    wxCheckBox* cblue;
    wxCheckBox* cgreen;

    wxBoxSizer* btSizer;
    wxStaticText* topLabel;
    wxButton* checkButns;
public:
    bool OnInit();
    wxCheckBox* addButton(wxPanel*, std::string label);
    void OnClick(wxCommandEvent& event);
};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Checking");
    frame->SetBackgroundColour(0xcfcfcf);
    frame->SetSize(120, 200);

    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

    frame->SetSizer(bxs);

    wxPanel* panel = new wxPanel(frame, wxID_ANY);
    bxs->Add(panel);

    btSizer = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(btSizer);

    btSizer->AddSpacer(10);
    topLabel = new wxStaticText(panel, wxID_ANY, "     ");
    btSizer->Add(topLabel, 0, wxALIGN_CENTER_HORIZONTAL, 10);
    btSizer->AddSpacer(10);

    cred = addButton(panel, "Sam");
    cblue = addButton(panel, "Bertha");
    //cgreen = addButton(panel, "George");
    cgreen = new wxCheckBox(panel, wxID_ANY, wxString("George"), wxDefaultPosition,
        wxDefaultSize, wxCHK_3STATE |wxALIGN_RIGHT);
    btSizer->Add(cgreen);
    

    checkButns = new wxButton(panel, wxID_ANY, "Check");
    btSizer->Add(checkButns, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    checkButns->Bind(wxEVT_BUTTON, &Builder::OnClick, this);

    bxs->Show(true);
    frame->Show(true);
    return true;
}

wxCheckBox* Builder::addButton(wxPanel* pnl, string label) {
    //create the button
    wxCheckBox* cbut =
        new wxCheckBox(pnl, wxID_ANY, wxString(label), wxDefaultPosition, 
            wxDefaultSize, wxCHK_3STATE|wxCHK_ALLOW_3RD_STATE_FOR_USER);
    // put it in a horizontal BoxSizer with space to the left
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->AddSpacer(20);
    hbox->Add(cbut);
    btSizer->Add(hbox);
    btSizer->AddSpacer(10); // and add space after the button
    return cbut;
}

void Builder::OnClick(wxCommandEvent& event) {
   
}

