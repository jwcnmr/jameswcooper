// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#endif

//create the app
class MyApp : public wxApp
{
public:
    bool OnInit() {         //called to start the UI
        wxFrame* frame =    //create the frame
            new wxFrame(NULL, wxID_ANY, "Hello World");
        
        frame->SetSize(250, 200);   //set a size
        frame->Show(true);          //and show it
        return true;
    }  
};

//launch the app
wxIMPLEMENT_APP(MyApp);



