// For compilers that support precompilation, includes "wx/wx.h".

//Example of ListBox, showing both Single and Multiple selection

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/button.h"
#include "wx/listbox.h"
#include "wx/checklst.h"
#include "BlueLabel.h"
#include <string>
#endif

using std::string;

class Builder : public wxApp {
private:
    BlueLabel* title;
    wxListBox* lbox;
    wxButton* butn;
   

public:
    bool OnInit();
    void OnClick(wxCommandEvent& event);

};

wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Name list");
    frame->SetSize(250, 250);
    wxPanel* panel = new wxPanel(frame);

    //create the Box sizer
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(vbox);

    //create the text label
    title = new BlueLabel(panel, wxID_ANY, "            ");

    vbox->AddSpacer(20);
    vbox->Add(title, 0, wxALIGN_CENTER, 10);
    wxString choices[2] = { "Anne", "Betty" };
    // comment ont either the single or the multiple versions
    lbox = new wxListBox(panel, wxID_ANY,
   // lbox =  new wxCheckListBox(panel, wxID_ANY,
       // wxDefaultPosition, wxSize(150, 100), 0, NULL, wxLB_SINGLE);
       wxDefaultPosition, wxSize(150, 100), 2, choices, wxLB_MULTIPLE);
    //   wxDefaultPosition, wxSize(150, 100));
    vbox->Add(lbox, 0, wxALIGN_CENTER, 10);
    lbox->Append(wxT("Fred"));
    lbox->Append(wxT("Sally"));
    lbox->Append(wxT("Sam"));
    lbox->Append(wxT("Bridget"));
    butn = new wxButton(panel, wxID_ANY, "Get");
    vbox->AddSpacer(10);
    vbox->Add(butn, 0, wxALIGN_CENTER, 10);
    vbox->AddSpacer(10);
   

    //Now add in button click event
    butn->Bind(wxEVT_BUTTON, &Builder::OnClick, this);

    frame->Show(true);
    return true;
}
void Builder::OnClick(wxCommandEvent& event) {

    //This will work with the multiple and the single versions
    wxArrayInt selections;  //create the empty array
    int count = lbox->GetSelections(selections); //load it
    string text = "";   //append all selections here
    for (int i = 0; i < count; i++) {
        int index = selections.Item(i);
        text += lbox->GetString(index) + " ";
    }
    title->SetLabel(text);      // set all the text into the label
    //This will work only with the single version
    // get the index and fetch that line
   // int index = lbox->GetSelection();
    //if (index >=0)
    //    title->SetLabel(lbox->GetString(index));
}

