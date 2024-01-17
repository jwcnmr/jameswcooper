<<<<<<< HEAD
// wxWidgets "Checkbox" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


using std::string;

class Builder : public wxApp

{
private:

    wxRadioButton* cred{ NULL };
    wxRadioButton* cblue{ NULL };
    wxRadioButton* cgreen{ NULL };

    wxBoxSizer* btSizer{ NULL };
    wxButton* checkButns{ NULL };
    wxPanel* leftPanel{ NULL };
    wxPanel* rightPanel{ NULL };
public:
    bool OnInit();
    wxRadioButton* addButton(wxPanel*, std::string label);
    
    void onClick(wxCommandEvent& event);
    void onClick3(wxCommandEvent& event);

};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Colors");
    frame->SetBackgroundColour(0xcfcfcf);
    frame->SetSize(250, 150);

    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

    frame->SetSizer(bxs);

    leftPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);
    rightPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);
    bxs->Add(leftPanel);
    bxs->Add(rightPanel);


    btSizer = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(btSizer);

    btSizer->AddSpacer(10);

    cred = addButton(leftPanel, "Red");
    cblue = addButton(leftPanel, "Blue");
    cgreen = addButton(leftPanel, "Green");
   

    checkButns = new wxButton(leftPanel, wxID_ANY, "Check");
    btSizer->Add(checkButns, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    //checkButns->Bind(wxEVT_BUTTON, &Builder::OnClick, this);

    bxs->Show(true);
    frame->Show(true);
    return true;
}

wxRadioButton* Builder::addButton(wxPanel* pnl, string label) {
    //create the button
    wxRadioButton* cbut =
        new wxRadioButton(pnl, wxID_ANY, wxString(label));
    // put it in a horizontal BoxSizer with space to the left
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->AddSpacer(20);
    hbox->Add(cbut);
    btSizer->Add(hbox);
    btSizer->AddSpacer(10); // and add space after the button
    
    // use one or the other
    // Bind(wxEVT_RADIOBUTTON, &Builder::onClick, this);
    Bind(wxEVT_RADIOBUTTON, &Builder::onClick3, this);
    return cbut;
}

//scan to find the selected button
void Builder::onClick(wxCommandEvent& event) {
    wxRadioButton* cbut = cred->GetFirstInGroup();  //get first button
    do {
        if (cbut->GetValue()) {
            wxString lbl = cbut->GetLabelText();
            lbl.LowerCase();
            rightPanel->SetBackgroundColour(wxColor(lbl));
        }
        cbut = cbut->GetNextInGroup();  //get next button
    } while (cbut != NULL);             //until done  
    rightPanel->Refresh();
}

//get the button from the event object
void Builder::onClick3(wxCommandEvent& event) {
    //get the object that caused the event
    auto winobj = event.GetEventObject();
    //cast to wxRadioButton*
    wxRadioButton* cbut = (wxRadioButton*)winobj;      
    wxString lbl = cbut->GetLabelText();
    lbl.LowerCase();
    rightPanel->SetBackgroundColour(wxColor(lbl));       
    rightPanel->Refresh();
}
=======
// wxWidgets "Checkbox" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


using std::string;

class Builder : public wxApp

{
private:

    wxRadioButton* cred{ NULL };
    wxRadioButton* cblue{ NULL };
    wxRadioButton* cgreen{ NULL };

    wxBoxSizer* btSizer{ NULL };
    wxButton* checkButns{ NULL };
    wxPanel* leftPanel{ NULL };
    wxPanel* rightPanel{ NULL };
public:
    bool OnInit();
    wxRadioButton* addButton(wxPanel*, std::string label);
    
    void onClick(wxCommandEvent& event);
    void onClick3(wxCommandEvent& event);

};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Colors");
    frame->SetBackgroundColour(0xcfcfcf);
    frame->SetSize(250, 150);

    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

    frame->SetSizer(bxs);

    leftPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);
    rightPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);
    bxs->Add(leftPanel);
    bxs->Add(rightPanel);


    btSizer = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(btSizer);

    btSizer->AddSpacer(10);

    cred = addButton(leftPanel, "Red");
    cblue = addButton(leftPanel, "Blue");
    cgreen = addButton(leftPanel, "Green");
   

    checkButns = new wxButton(leftPanel, wxID_ANY, "Check");
    btSizer->Add(checkButns, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

    //checkButns->Bind(wxEVT_BUTTON, &Builder::OnClick, this);

    bxs->Show(true);
    frame->Show(true);
    return true;
}

wxRadioButton* Builder::addButton(wxPanel* pnl, string label) {
    //create the button
    wxRadioButton* cbut =
        new wxRadioButton(pnl, wxID_ANY, wxString(label));
    // put it in a horizontal BoxSizer with space to the left
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->AddSpacer(20);
    hbox->Add(cbut);
    btSizer->Add(hbox);
    btSizer->AddSpacer(10); // and add space after the button
    
    // use one or the other
    // Bind(wxEVT_RADIOBUTTON, &Builder::onClick, this);
    Bind(wxEVT_RADIOBUTTON, &Builder::onClick3, this);
    return cbut;
}

//scan to find the selected button
void Builder::onClick(wxCommandEvent& event) {
    wxRadioButton* cbut = cred->GetFirstInGroup();  //get first button
    do {
        if (cbut->GetValue()) {
            wxString lbl = cbut->GetLabelText();
            lbl.LowerCase();
            rightPanel->SetBackgroundColour(wxColor(lbl));
        }
        cbut = cbut->GetNextInGroup();  //get next button
    } while (cbut != NULL);             //until done  
    rightPanel->Refresh();
}

//get the button from the event object
void Builder::onClick3(wxCommandEvent& event) {
    //get the object that caused the event
    auto winobj = event.GetEventObject();
    //cast to wxRadioButton*
    wxRadioButton* cbut = (wxRadioButton*)winobj;      
    wxString lbl = cbut->GetLabelText();
    lbl.LowerCase();
    rightPanel->SetBackgroundColour(wxColor(lbl));       
    rightPanel->Refresh();
}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
