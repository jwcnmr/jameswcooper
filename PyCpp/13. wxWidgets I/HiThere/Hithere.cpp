<<<<<<< HEAD
// For compilers that support precompilation, includes "wx/wx.h".

//Frame 3 changes wxApp to Builder and moves OnInit 
/// to below the IMPLEMENT_APP main call
// and introduces the first Sizer

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/button.h"
#include "BlueLabel.h"
#include <string>
#endif

using std::string;

class Builder : public wxApp {
private:
    BlueLabel* title;
    wxTextCtrl* name;
    wxButton* butn;
    BlueLabel* greeting;

public:
    bool OnInit();
    void OnClick(wxCommandEvent& event);
   
};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Say hi to me");
    frame->SetSize(250, 200);
    wxPanel* panel = new wxPanel(frame);

    //create the Box sizer
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(vbox);

    //create the text label
    title = new BlueLabel(panel, wxID_ANY, "Enter your name");
   
    vbox->AddSpacer(20);
    vbox->Add(title, 0, wxALIGN_CENTER, 10);
    name = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(name, 0, wxALIGN_CENTER, 10);
    butn = new wxButton(panel, wxID_ANY, "Say hi");
    vbox->AddSpacer(10);
    vbox->Add(butn, 0, wxALIGN_CENTER, 10);
    vbox->AddSpacer(10);
    greeting = new BlueLabel(panel, wxID_ANY, "               ");
    vbox->Add(greeting, 0, wxALIGN_CENTER , 10);

    //Now add in button click event
    butn->Bind(wxEVT_BUTTON, &Builder::OnClick, this);


    
    frame->Show(true);
    return true;
}
void Builder::OnClick(wxCommandEvent& event) {
    //get the text and convert it to a string
    string text = name->GetLineText(0).ToStdString();
    string grtext = "Hi " + text;   //prepend "Hi"
    if (text == "Jim") grtext += " boy!";
    greeting->SetLabelText(grtext); //put result in greeting
}


=======
// For compilers that support precompilation, includes "wx/wx.h".

//Frame 3 changes wxApp to Builder and moves OnInit 
/// to below the IMPLEMENT_APP main call
// and introduces the first Sizer

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/button.h"
#include "BlueLabel.h"
#include <string>
#endif

using std::string;

class Builder : public wxApp {
private:
    BlueLabel* title;
    wxTextCtrl* name;
    wxButton* butn;
    BlueLabel* greeting;

public:
    bool OnInit();
    void OnClick(wxCommandEvent& event);
   
};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Say hi to me");
    frame->SetSize(250, 200);
    wxPanel* panel = new wxPanel(frame);

    //create the Box sizer
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(vbox);

    //create the text label
    title = new BlueLabel(panel, wxID_ANY, "Enter your name");
   
    vbox->AddSpacer(20);
    vbox->Add(title, 0, wxALIGN_CENTER, 10);
    name = new wxTextCtrl(panel, wxID_ANY);
    vbox->Add(name, 0, wxALIGN_CENTER, 10);
    butn = new wxButton(panel, wxID_ANY, "Say hi");
    vbox->AddSpacer(10);
    vbox->Add(butn, 0, wxALIGN_CENTER, 10);
    vbox->AddSpacer(10);
    greeting = new BlueLabel(panel, wxID_ANY, "               ");
    vbox->Add(greeting, 0, wxALIGN_CENTER , 10);

    //Now add in button click event
    butn->Bind(wxEVT_BUTTON, &Builder::OnClick, this);


    
    frame->Show(true);
    return true;
}
void Builder::OnClick(wxCommandEvent& event) {
    //get the text and convert it to a string
    string text = name->GetLineText(0).ToStdString();
    string grtext = "Hi " + text;   //prepend "Hi"
    if (text == "Jim") grtext += " boy!";
    greeting->SetLabelText(grtext); //put result in greeting
}


>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
