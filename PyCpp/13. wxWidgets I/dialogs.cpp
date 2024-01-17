<<<<<<< HEAD
// Simple addition program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>


//using namespace std;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"

#endif


//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxButton* btInfo;
    wxButton* btError;
    wxButton* btQuestion;
    wxButton* btAlert;
    wxPanel* panel = NULL;

public:
    void msgInfo(wxCommandEvent& event);
    void msgError(wxCommandEvent& event);
    void msgQuestion(wxCommandEvent& event);
    void msgAlert(wxCommandEvent& event);
       
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Dialogs");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(120, 220);
        
        panel = new wxPanel(frame);
        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(vbox);
        vbox->AddSpacer(20);
        btInfo = new wxButton(panel, wxID_ANY, "Info");
        vbox->Add(btInfo, 0, wxALIGN_CENTER, 20);
        vbox->AddSpacer(20);
        btError = new wxButton(panel, wxID_ANY, "Error");
        vbox->Add(btError, 0, wxALIGN_CENTER, 20); 
        vbox->AddSpacer(20);
        btQuestion = new wxButton(panel, wxID_ANY, "Question");
        vbox->Add(btQuestion, 0, wxALIGN_CENTER, 20);
        vbox->AddSpacer(20);
        btAlert = new wxButton(panel, wxID_ANY, "Alert");
        vbox->Add(btAlert, 0, wxALIGN_CENTER, 20);

        btInfo->Bind(wxEVT_BUTTON, &Builder::msgInfo, this);
        btError->Bind(wxEVT_BUTTON, &Builder::msgError, this);
        btQuestion->Bind(wxEVT_BUTTON, &Builder::msgQuestion, this);
        btAlert->Bind(wxEVT_BUTTON, &Builder::msgAlert, this);

        frame->Show(true);
        vbox->Show(true);
        return true;
    }

};




    

wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::msgInfo(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Program is running"), wxT("Info"), wxOK|wxICON_INFORMATION );
    dlg->ShowModal();
}
void Builder::msgError(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Error reading file"), wxT("Error"), wxOK | wxICON_ERROR);
    dlg->ShowModal();
}
void Builder::msgQuestion(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Do you want to quit?"), wxT("Question"),
        wxYES_NO | wxNO_DEFAULT | wxICON_AUTH_NEEDED);
    dlg->ShowModal();
}
void Builder::msgAlert(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Division by zero!"), wxT("Exclamation"),
        wxOK | wxICON_EXCLAMATION);
    dlg->ShowModal();
}




=======
// Simple addition program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>


//using namespace std;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"

#endif


//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxButton* btInfo;
    wxButton* btError;
    wxButton* btQuestion;
    wxButton* btAlert;
    wxPanel* panel = NULL;

public:
    void msgInfo(wxCommandEvent& event);
    void msgError(wxCommandEvent& event);
    void msgQuestion(wxCommandEvent& event);
    void msgAlert(wxCommandEvent& event);
       
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Dialogs");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(120, 220);
        
        panel = new wxPanel(frame);
        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(vbox);
        vbox->AddSpacer(20);
        btInfo = new wxButton(panel, wxID_ANY, "Info");
        vbox->Add(btInfo, 0, wxALIGN_CENTER, 20);
        vbox->AddSpacer(20);
        btError = new wxButton(panel, wxID_ANY, "Error");
        vbox->Add(btError, 0, wxALIGN_CENTER, 20); 
        vbox->AddSpacer(20);
        btQuestion = new wxButton(panel, wxID_ANY, "Question");
        vbox->Add(btQuestion, 0, wxALIGN_CENTER, 20);
        vbox->AddSpacer(20);
        btAlert = new wxButton(panel, wxID_ANY, "Alert");
        vbox->Add(btAlert, 0, wxALIGN_CENTER, 20);

        btInfo->Bind(wxEVT_BUTTON, &Builder::msgInfo, this);
        btError->Bind(wxEVT_BUTTON, &Builder::msgError, this);
        btQuestion->Bind(wxEVT_BUTTON, &Builder::msgQuestion, this);
        btAlert->Bind(wxEVT_BUTTON, &Builder::msgAlert, this);

        frame->Show(true);
        vbox->Show(true);
        return true;
    }

};




    

wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::msgInfo(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Program is running"), wxT("Info"), wxOK|wxICON_INFORMATION );
    dlg->ShowModal();
}
void Builder::msgError(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Error reading file"), wxT("Error"), wxOK | wxICON_ERROR);
    dlg->ShowModal();
}
void Builder::msgQuestion(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Do you want to quit?"), wxT("Question"),
        wxYES_NO | wxNO_DEFAULT | wxICON_AUTH_NEEDED);
    dlg->ShowModal();
}
void Builder::msgAlert(wxCommandEvent& event) {
    wxMessageDialog* dlg = new wxMessageDialog(NULL,
        wxT("Division by zero!"), wxT("Exclamation"),
        wxOK | wxICON_EXCLAMATION);
    dlg->ShowModal();
}




>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
