<<<<<<< HEAD
// Simple addition program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>


//using namespace std;
using std::string;

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/button.h"

#endif

//base namer class
class Namer {
protected:
    string frname{ NULL };  //first name
    string lname{ NULL };   //last name

public:
    string getFrname() {
        return frname;      //get the firat name
    }
    string getLname() {
        return lname;       //get the last name
    }
};

//splits apart names separated by a comma
class LastFirst : public Namer {
public:
    LastFirst(string nameEntry) {
        int index = nameEntry.find(",");
        if (index > 0) {
            lname = nameEntry.substr(0, index);
            if (index + 2 < size(nameEntry))  //prevents error if no 2nd name      
                frname = nameEntry.substr(index + 2, size(nameEntry) - (index + 2));
        }
    }
};

//splits apart two names separated by a space
class FirstFirst : public Namer {
public:
    FirstFirst(string nameEntry) {
        int index = nameEntry.find(" ");    //find the space
        if (index > 0) {                    //if we find one split there
            frname = nameEntry.substr(0, index);
            lname = nameEntry.substr(index + 1, size(nameEntry) - index);
        }
    }
};

//The name factory returns a pointer to a  last-first namer 
// or a first-first namer
class NameFactory {
private:
    string nameString;
public:

    NameFactory(string nm) {
        nameString = nm;        //save the string 
    }
    //get the right child of the Namer class
    Namer* getNamer() {
        //if there is a comma
        int index = nameString.find(",");
        if (index > 0) {
            return new LastFirst(nameString);   //return a LastFirst instance
        }
        //otherwise, return a FirstLast instance
        else {
            return new FirstFirst(nameString);
        }
    }
};


class Mediator {
private:
    wxTextCtrl* nmEntry;
    wxTextCtrl* name1;
    wxTextCtrl* name2;
    wxStaticText* sumLbl{ NULL };
public:
    Mediator(wxTextCtrl* nEntry, wxTextCtrl* n1, wxTextCtrl* n2);
    void setSumlabel(wxStaticText* slbl);
    void calcClicked();
    void clearClicked();

};


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
    void comd(wxCommandEvent& event) { }
     
};

// causes the addition
class CalcButton : public DButton
{
public:
    CalcButton(wxPanel* panel, int id, Mediator* med, wxApp* app) :
        DButton(panel, id, std::string("Calc"), med, app)
    {}
        void comd() {
            this->med->calcClicked();
       }
    
};

//clears the entry field and results
class ClearButton : public DButton
    {
    public:
        ClearButton(wxPanel* panel, int id,
            Mediator* med, wxApp* app) :
            DButton(panel, id, "Clear", med, app) {}

            
            void comd() {
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
    wxTextCtrl* nameEntry{ NULL };//name Entry
    wxTextCtrl* name1{ NULL };    //name field 1
    wxTextCtrl* name2 = NULL;    //name field 2
 
    Mediator* med = NULL;
    wxPanel* panel = NULL;

public:
    
    void OnCalc(wxCommandEvent& event);      // Add button event
    void OnClear(wxCommandEvent& event);     // clear button event
   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame =    //create the frame
            new wxFrame(NULL, wxID_ANY, "Namer demo");

        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(300, 320);
        
        panel = new wxPanel(frame, wxID_ANY);
                   
        wxGridBagSizer* fgs = new wxGridBagSizer(10, 10);
        panel->SetSizer(fgs);

        BlueLabel* spacer = new BlueLabel(panel, 2, "   ");
        
        wxStaticText* topTitle = new BlueLabel(panel, 1, wxT("   Enter name string"));
        fgs->Add(topTitle, wxGBPosition(1, 0), wxGBSpan(1, 4), wxALIGN_LEFT);
      
        wxBoxSizer* filler = new wxBoxSizer(wxHORIZONTAL);
        filler->AddSpacer(20);
        fgs->Add(filler, wxGBPosition(2, 0), wxGBSpan(1, 2));

        this->nameEntry= new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
        filler->Add(this->nameEntry);
        
        //first label and entry field
        BlueLabel* lineLabel = new BlueLabel(panel, 2, "  First name:   ");
     
        fgs->Add(lineLabel, wxGBPosition(3, 0));
        this->name1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
       
        fgs->Add(this->name1, wxGBPosition(3, 1), wxGBSpan(1,2));

        //second label and entry field
        BlueLabel* lineLabel2 = new BlueLabel(panel, 2, "  Last name:   ");
        fgs->Add(lineLabel2, wxGBPosition(4, 0));
        this->name2 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
      
        fgs->Add(name2, wxGBPosition(4, 1),wxGBSpan(1, 2));
        med = new Mediator(this->nameEntry, this->name1, this->name2);

        wxBoxSizer* filler2 = new wxBoxSizer(wxHORIZONTAL);
        // Calc button
        CalcButton* addButton = new CalcButton(panel, 1, this->med, this );
        filler2->AddSpacer(30);
        filler2->Add(addButton);
        
        addButton->Bind(wxEVT_BUTTON, &Builder::OnCalc, this);

        // Clear button
        filler2->AddSpacer(30);
        ClearButton* clearButton = new ClearButton(panel, 3,  this->med, this);
        filler2->Add(clearButton);
        fgs->Add(filler2, wxGBPosition(5, 0), wxGBSpan(1, 4));
        
        clearButton->Bind(wxEVT_BUTTON, &Builder::OnClear, this);
        frame->Show(true);
        
        return true;
    }

};

Mediator::Mediator(wxTextCtrl* nmEnt, wxTextCtrl* n1, wxTextCtrl* n2) {
    nmEntry = nmEnt;
    name1 = n1;
    name2 = n2;
}
void Mediator::setSumlabel(wxStaticText* slbl) {
    sumLbl = slbl;
}

void Mediator::calcClicked() {
    string st1 = this->nmEntry->GetLineText(0).ToStdString();
    
    NameFactory nf(st1);            //create a name factory
    Namer* nmr = nf.getNamer();     //get the right namer pointer
   
    //display the first and last names
    name1->SetLabel(nmr->getFrname());
    name2->SetLabel(nmr->getLname());
    delete nmr;     //delete pointer to that class
    
}

void Mediator::clearClicked() {
    nmEntry->SetLabel("");
    name1->SetLabel("");
    name2->SetLabel("");
}

    

wxIMPLEMENT_APP(Builder);

// This is the Calc button click event
void Builder::OnCalc(wxCommandEvent& event) {
    med->calcClicked();
}

// Clear button click event
void Builder::OnClear(wxCommandEvent& event) {
    med->clearClicked();
}



=======
// Simple addition program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>


//using namespace std;
using std::string;

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/button.h"

#endif

//base namer class
class Namer {
protected:
    string frname{ NULL };  //first name
    string lname{ NULL };   //last name

public:
    string getFrname() {
        return frname;      //get the firat name
    }
    string getLname() {
        return lname;       //get the last name
    }
};

//splits apart names separated by a comma
class LastFirst : public Namer {
public:
    LastFirst(string nameEntry) {
        int index = nameEntry.find(",");
        if (index > 0) {
            lname = nameEntry.substr(0, index);
            if (index + 2 < size(nameEntry))  //prevents error if no 2nd name      
                frname = nameEntry.substr(index + 2, size(nameEntry) - (index + 2));
        }
    }
};

//splits apart two names separated by a space
class FirstFirst : public Namer {
public:
    FirstFirst(string nameEntry) {
        int index = nameEntry.find(" ");    //find the space
        if (index > 0) {                    //if we find one split there
            frname = nameEntry.substr(0, index);
            lname = nameEntry.substr(index + 1, size(nameEntry) - index);
        }
    }
};

//The name factory returns a pointer to a  last-first namer 
// or a first-first namer
class NameFactory {
private:
    string nameString;
public:

    NameFactory(string nm) {
        nameString = nm;        //save the string 
    }
    //get the right child of the Namer class
    Namer* getNamer() {
        //if there is a comma
        int index = nameString.find(",");
        if (index > 0) {
            return new LastFirst(nameString);   //return a LastFirst instance
        }
        //otherwise, return a FirstLast instance
        else {
            return new FirstFirst(nameString);
        }
    }
};


class Mediator {
private:
    wxTextCtrl* nmEntry;
    wxTextCtrl* name1;
    wxTextCtrl* name2;
    wxStaticText* sumLbl{ NULL };
public:
    Mediator(wxTextCtrl* nEntry, wxTextCtrl* n1, wxTextCtrl* n2);
    void setSumlabel(wxStaticText* slbl);
    void calcClicked();
    void clearClicked();

};


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
    void comd(wxCommandEvent& event) { }
     
};

// causes the addition
class CalcButton : public DButton
{
public:
    CalcButton(wxPanel* panel, int id, Mediator* med, wxApp* app) :
        DButton(panel, id, std::string("Calc"), med, app)
    {}
        void comd() {
            this->med->calcClicked();
       }
    
};

//clears the entry field and results
class ClearButton : public DButton
    {
    public:
        ClearButton(wxPanel* panel, int id,
            Mediator* med, wxApp* app) :
            DButton(panel, id, "Clear", med, app) {}

            
            void comd() {
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
    wxTextCtrl* nameEntry{ NULL };//name Entry
    wxTextCtrl* name1{ NULL };    //name field 1
    wxTextCtrl* name2 = NULL;    //name field 2
 
    Mediator* med = NULL;
    wxPanel* panel = NULL;

public:
    
    void OnCalc(wxCommandEvent& event);      // Add button event
    void OnClear(wxCommandEvent& event);     // clear button event
   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame =    //create the frame
            new wxFrame(NULL, wxID_ANY, "Namer demo");

        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(300, 320);
        
        panel = new wxPanel(frame, wxID_ANY);
                   
        wxGridBagSizer* fgs = new wxGridBagSizer(10, 10);
        panel->SetSizer(fgs);

        BlueLabel* spacer = new BlueLabel(panel, 2, "   ");
        
        wxStaticText* topTitle = new BlueLabel(panel, 1, wxT("   Enter name string"));
        fgs->Add(topTitle, wxGBPosition(1, 0), wxGBSpan(1, 4), wxALIGN_LEFT);
      
        wxBoxSizer* filler = new wxBoxSizer(wxHORIZONTAL);
        filler->AddSpacer(20);
        fgs->Add(filler, wxGBPosition(2, 0), wxGBSpan(1, 2));

        this->nameEntry= new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(200, 30));
        filler->Add(this->nameEntry);
        
        //first label and entry field
        BlueLabel* lineLabel = new BlueLabel(panel, 2, "  First name:   ");
     
        fgs->Add(lineLabel, wxGBPosition(3, 0));
        this->name1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
       
        fgs->Add(this->name1, wxGBPosition(3, 1), wxGBSpan(1,2));

        //second label and entry field
        BlueLabel* lineLabel2 = new BlueLabel(panel, 2, "  Last name:   ");
        fgs->Add(lineLabel2, wxGBPosition(4, 0));
        this->name2 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 30));
      
        fgs->Add(name2, wxGBPosition(4, 1),wxGBSpan(1, 2));
        med = new Mediator(this->nameEntry, this->name1, this->name2);

        wxBoxSizer* filler2 = new wxBoxSizer(wxHORIZONTAL);
        // Calc button
        CalcButton* addButton = new CalcButton(panel, 1, this->med, this );
        filler2->AddSpacer(30);
        filler2->Add(addButton);
        
        addButton->Bind(wxEVT_BUTTON, &Builder::OnCalc, this);

        // Clear button
        filler2->AddSpacer(30);
        ClearButton* clearButton = new ClearButton(panel, 3,  this->med, this);
        filler2->Add(clearButton);
        fgs->Add(filler2, wxGBPosition(5, 0), wxGBSpan(1, 4));
        
        clearButton->Bind(wxEVT_BUTTON, &Builder::OnClear, this);
        frame->Show(true);
        
        return true;
    }

};

Mediator::Mediator(wxTextCtrl* nmEnt, wxTextCtrl* n1, wxTextCtrl* n2) {
    nmEntry = nmEnt;
    name1 = n1;
    name2 = n2;
}
void Mediator::setSumlabel(wxStaticText* slbl) {
    sumLbl = slbl;
}

void Mediator::calcClicked() {
    string st1 = this->nmEntry->GetLineText(0).ToStdString();
    
    NameFactory nf(st1);            //create a name factory
    Namer* nmr = nf.getNamer();     //get the right namer pointer
   
    //display the first and last names
    name1->SetLabel(nmr->getFrname());
    name2->SetLabel(nmr->getLname());
    delete nmr;     //delete pointer to that class
    
}

void Mediator::clearClicked() {
    nmEntry->SetLabel("");
    name1->SetLabel("");
    name2->SetLabel("");
}

    

wxIMPLEMENT_APP(Builder);

// This is the Calc button click event
void Builder::OnCalc(wxCommandEvent& event) {
    med->calcClicked();
}

// Clear button click event
void Builder::OnClear(wxCommandEvent& event) {
    med->clearClicked();
}



>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
