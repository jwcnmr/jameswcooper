// wxWidgets "Radio buttons" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class Mediator {
protected:
   
    wxPanel* rightPanel;
    wxRadioButton* cred{NULL};
   
public:
    Mediator(wxPanel* rp, wxRadioButton* cbut);
    void radClick(wxCommandEvent& ev, int idBase);
   
};


class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
   
    void onClick(wxCommandEvent& ev);
   
    wxRadioButton* addRadio(wxPanel*, std::string label, wxSizer* psizer);
    

private:
    wxRadioButton* cbut{NULL};
    wxRadioButton* cred{ NULL };
    wxRadioButton* cblue{ NULL };
    wxRadioButton* cgreen{ NULL };
    wxBoxSizer* pnlSzr{ NULL };
    Mediator* med{ NULL };
    int idBase=0;
};


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
   
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Radio Buttons") {
    SetBackgroundColour(0xcfcfcf);
    SetSize(250, 150);
    Show(true);
  
    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(bxs);
    bxs->Show(true);
    wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);
    wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(125, 150), wxRAISED_BORDER);

    bxs->Add(leftPanel);
    bxs->Add(rightPanel);

    pnlSzr = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(pnlSzr);
    wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);
    filler0->AddSpacer(10);
    pnlSzr->Add(filler0);

    cred = addRadio(leftPanel, "Red", pnlSzr);
    
    cblue = addRadio(leftPanel, "Blue", pnlSzr);
    cgreen = addRadio(leftPanel, "Green", pnlSzr);
    med = new Mediator(rightPanel, cred);

    //cred->SetValue(true);
    leftPanel->Show();
    this->Layout();
};


void MyFrame::onClick(wxCommandEvent& ev) {
        med->radClick(ev, idBase);
}


Mediator::Mediator(wxPanel* rp,wxRadioButton* cbut) {
        this->rightPanel = rp;  
        cred = cbut;
}
void Mediator::radClick(wxCommandEvent& ev, int idBase) {  
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

wxRadioButton* MyFrame::addRadio(wxPanel* p, std::string label, wxSizer* pnlSzr) {
    cbut = new wxRadioButton(p, wxID_ANY, wxString(label),
        wxDefaultPosition, wxDefaultSize, wxEXPAND, wxDefaultValidator, wxString(label));
    pnlSzr->Add(cbut, wxID_ANY, wxALL, 5);
    Bind(wxEVT_RADIOBUTTON, &MyFrame::onClick, this);
    
    return cbut;
}

