<<<<<<< HEAD
// For compilers that support precompilation, includes "wx/wx.h".

//Frame 2 introduces the Panel in which yo can position widgets
//Here we use absolute positioning.
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#endif

class MyApp : public wxApp
{
public:
    bool OnInit() {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Hello World");
        frame->SetSize(250, 200);
        wxPanel* panel = new wxPanel(frame);
        wxStaticText* tx = new wxStaticText(panel, wxID_ANY, 
            wxString("Greetings"), wxPoint(40,60));
       
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);



=======
// For compilers that support precompilation, includes "wx/wx.h".

//Frame 2 introduces the Panel in which yo can position widgets
//Here we use absolute positioning.
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#endif

class MyApp : public wxApp
{
public:
    bool OnInit() {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Hello World");
        frame->SetSize(250, 200);
        wxPanel* panel = new wxPanel(frame);
        wxStaticText* tx = new wxStaticText(panel, wxID_ANY, 
            wxString("Greetings"), wxPoint(40,60));
       
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);



>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
