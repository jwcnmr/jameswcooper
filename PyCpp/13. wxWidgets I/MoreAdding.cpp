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
#include "wx/gbsizer.h"
#include "wx/button.h"
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



/* This abstract class defines a button with a comd method this is called
when it is clicked.  Derived classes need only fill in the come method*/

class DButton: public wxButton {

// The Mediator class actually executes the code for all button clicks
protected:
    Mediator* med;

public:
    DButton(wxPanel* panel, int id, const std::string label, Mediator* med, wxApp* app): 
         wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize)
    {
        this->med = med;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }
  
  //abstract method to be completed in derived classes 
    virtual void comd(wxCommandEvent& event) {}
     
};

// causes the addition
class AddButton : public DButton
{
public:
    AddButton(wxPanel* panel, int id, Mediator* med, wxApp* app) :
        DButton(panel, id, std::string("Add"), med, app)   {}

        void comd(wxCommandEvent& event) {
            this->med->addClicked();
       }
    
};

//clears the entry fields and sum labell
class ClearButton : public DButton
    {
    public:
        ClearButton(wxPanel* panel, int id,
            Mediator* med, wxApp* app) :
            DButton(panel, id, "Clear", med, app) {}

            
            void comd(wxCommandEvent& event) {
                this->med->clearClicked();
            }
        
    };




//----A derived class for blue labels-------
class BlueLabel : public wxStaticText {
public:
    BlueLabel(wxPanel* parent, int id, const wxString& label) :
        wxStaticText(parent, id, label)
    {
        this->SetForegroundColour(wxColour(0, 0, 200));
        wxFont font = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, 
            wxFONTWEIGHT_NORMAL, FALSE, "");
        this->SetFont(font);
    }
};


//----Creates the entry fields, labels and buttons
class Builder : public wxApp
{
private:
    wxTextCtrl* num1{ NULL };    //number field 1
    wxTextCtrl* num2 = NULL;    //number fiels 2
    BlueLabel* sumLbl = NULL;   //label where sum is displayed
    Mediator* med = NULL;
    wxPanel* panel = NULL;
  

public:
    
    void OnAdd(wxCommandEvent& event);      // Add button event
    void OnClear(wxCommandEvent& event);    // clear button event
   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Add numbers");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(320, 320);
       
        panel = new wxPanel(frame, wxID_ANY);
                   
        wxGridBagSizer* fgs = new wxGridBagSizer(10, 10);
        panel->SetSizer(fgs);

        BlueLabel* spacer = new BlueLabel(panel, 2, "   ");
        
        wxStaticText* topTitle = new BlueLabel(panel, 1, wxT("   Add 2 numbers"));
        fgs->Add(topTitle, wxGBPosition(1, 0), wxGBSpan(1, 4), wxALIGN_CENTER_HORIZONTAL);

        //first label and entry field
        BlueLabel* lineLabel = new BlueLabel(panel, 2, "  First num:   ");
    
        
        fgs->Add(lineLabel, wxGBPosition(2, 0));
        this->num1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
       
        fgs->Add(this->num1, wxGBPosition(2, 1), wxGBSpan(1,2));

        //second label and entry field
        BlueLabel* lineLabel2 = new BlueLabel(panel, 2, "  Second num:   ");
       
        fgs->Add(lineLabel2, wxGBPosition(3, 0));
        this->num2 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
        //wxTextCtrl num2 (panel, wxID_ANY, "", wxDefaultPosition, wxSize(50, 30));
        fgs->Add(num2, wxGBPosition(3, 1),wxGBSpan(1, 2));
        med = new Mediator(this->num1, this->num2);
      

        // Add button
        AddButton* addButton = new AddButton(panel, 1, this->med, this );
        fgs->Add(addButton, wxGBPosition(4, 0), wxGBSpan(1, 2), wxALIGN_CENTER_HORIZONTAL);
        
       
        // Clear button
        ClearButton* clearButton = new ClearButton(panel, 3,  this->med, this);
        wxSizerItem* obj = fgs->Add(clearButton, wxGBPosition(4, 2), wxGBSpan(1, 2), wxALIGN_LEFT);
        
       // spacer puts sum label in 2nd column
        wxBoxSizer* filler = new wxBoxSizer(wxHORIZONTAL);
        filler->AddSpacer(20);
        fgs->Add(filler, wxGBPosition(5, 0));

        // sum label
        this->sumLbl = new BlueLabel(panel, 2, "The Sum ");
        fgs->Add(sumLbl, wxGBPosition(5, 1));
        med->setSumlabel(this->sumLbl);
        frame->Show(true);

        return true;
    }

};

Mediator::Mediator(wxTextCtrl* n1, wxTextCtrl* n2) {
    num1 = n1;
    num2 = n2;
}
void Mediator::setSumlabel(wxStaticText* slbl) {
    sumLbl = slbl;
}

void Mediator::addClicked() {
    std::string st1 = this->num1->GetLineText(0).ToStdString();
    std::string st2 = this->num2->GetLineText(0).ToStdString();
   
    float sum = stof(st1) + stof(st2);
    std::string st3 = "Sum is: "+ std::format("{:5g}", sum);
    this->sumLbl->SetLabel(st3);
    
}

void Mediator::clearClicked() {
    num1->SetLabel("");
    num2->SetLabel("");
    sumLbl->SetLabel("Sum is:");
    
}

    

wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::OnAdd(wxCommandEvent& event) {
    med->addClicked();
}

// Clear button click event
void Builder::OnClear(wxCommandEvent& event) {
    med->clearClicked();
}



