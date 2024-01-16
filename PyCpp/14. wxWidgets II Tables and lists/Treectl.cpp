// Simple addition program
// derived from wxWidgets "Hello World" Program

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
#include "wx/treectrl.h"
#include <format>
#endif


class Mediator {
private:
    wxTextCtrl* num1;
    wxTextCtrl* num2;
    wxStaticText* sumLbl{ NULL };
public:
    Mediator(wxTextCtrl* n1, wxTextCtrl* n2);
    void setSumlabel(wxStaticText* slbl);
    void addClicked();
    void clearClicked();

};
// ---- - The main window frame

class wFrame : public wxFrame
{
public:
   wFrame();

};

//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxPanel* panel = NULL;
    wxTreeCtrl* tree{ NULL };

public:   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Tree example");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(225, 250);
       
        panel = new wxPanel(frame, wxID_ANY);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(sizer);
        tree = new wxTreeCtrl(panel, wxID_ANY, wxDefaultPosition, wxSize(200, 200),
            wxTR_DEFAULT_STYLE, wxDefaultValidator, wxString("state tree"));
        sizer->Add(tree);

        wxTreeItemId rootId = tree->AddRoot("States");
        wxTreeItemId child = tree->AppendItem(rootId, "California");
        wxTreeItemId child1 = tree->AppendItem(child, "CA");
        tree->AppendItem(child1, "Sacramento");

        wxTreeItemId newRoot = tree->AppendItem(rootId,"Kansas");
        wxTreeItemId child2 = tree->AppendItem(newRoot, "KS");
        tree->AppendItem(child2, "Topeka");
        frame->Show();
        return true;
    }
};

   
wxIMPLEMENT_APP(Builder);


