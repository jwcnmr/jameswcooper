// For compilers that support precompilation, includes "wx/wx.h".

//Frame 3 changes wxApp to Builder and moves OnInit 
/// to below the IMPLEMENT_APP main call
// and introduces the first Sizer

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#include "wx/sizer.h"
#endif

class Builder : public wxApp {
public:
    bool OnInit(); 
};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Hello World");
    frame->SetSize(250, 200);
    wxPanel* panel = new wxPanel(frame);
    
    //create the Box sizer
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(vbox);
    
    //create the text label
    wxStaticText* tx = new wxStaticText(panel, wxID_ANY,
        wxString("Greetings"));
    vbox->AddSpacer(50);
    vbox->Add(tx);    //and add it to the box
    /* vbox->Add(tx, 0,    //not stretchable
        wxALIGN_CENTER, //alignment
        10);            //border width
        */
    
    frame->Show(true);
    return true;
}


