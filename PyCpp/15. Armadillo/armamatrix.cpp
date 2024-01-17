<<<<<<< HEAD
// Simple matrix program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>
#include <armadillo>


//using namespace std;
using namespace arma;
using std::cout;
using std::endl;
using std::to_string;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/button.h"
#include "wx/grid.h"
#include <format>
#endif


class Mediator {
private:
    wxGrid* numGrid;
    wxStaticText* sumLbl{ NULL };
    mat A;
public:
    Mediator(wxGrid* grid);
    
    void loadClicked();
    void transposeClicked();
    void loadGrid(mat A);

};

/* This abstract class defines a button with a comd method this is called
when it is clicked.  Derived classes need only fill in the come method*/

class DButton: public wxButton {

// The Mediator class actually executed the code for all button clicks
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

// causes the loading of the data
class LoadButton : public DButton
{
public:
    LoadButton(wxPanel* panel, int id, Mediator* med, wxApp* app) :
        DButton(panel, id, std::string("Load"), med, app)
    {}
        void comd() {
            this->med->loadClicked();
       }
    
};

//creates and displays the transposed matrix
class TransposeButton : public DButton
    {
    public:
        TransposeButton(wxPanel* panel, int id,
            Mediator* med, wxApp* app) :
            DButton(panel, id, "Transpose", med, app) {}
            
            void comd() {
                this->med->transposeClicked();
            } 
    };




//----Creates the numeric grid and buttons
class Builder : public wxApp
{
private:
    
    Mediator* med = NULL;
    wxPanel* panel = NULL;
    wxGrid* numberGrid;

public:
    
    void OnLoad(wxCommandEvent& event);      // Load button event
    void OnTrans(wxCommandEvent& event);    // Transpose button event
   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Display matrix");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(450, 250);
       
        panel = new wxPanel(frame, wxID_ANY);
                   
        wxBoxSizer* fgs = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(fgs);

     
        //create the grid, 5 x 5
        numberGrid = new wxGrid(panel, wxID_ANY,
            wxDefaultPosition, wxSize(450, 150));
        numberGrid->CreateGrid(5, 5);
       
        numberGrid->SetRowLabelSize(30);
        fgs->Add(numberGrid); 
        med = new Mediator(numberGrid);
           
        wxBoxSizer* hs = new wxBoxSizer(wxHORIZONTAL);
        hs->AddSpacer(150);

        // Load button
        LoadButton* addButton = new LoadButton(panel, 1, this->med, this );
        hs->Add(addButton, wxALIGN_CENTER_HORIZONTAL);
        
        addButton->Bind(wxEVT_BUTTON, &Builder::OnLoad, this);

        // Transpose button
        TransposeButton* transButton = new TransposeButton(panel, 3,  this->med, this);
        wxSizerItem* obj = hs->Add(transButton);
        
        transButton->Bind(wxEVT_BUTTON, &Builder::OnTrans, this);
        fgs->Add(hs);     
        frame->Show(true);
        
        return true;
    }

};

Mediator::Mediator(wxGrid* grid) {
    numGrid = grid;
    A.set_size(5, 5); // change the size (data is not preserved)
    A.fill(0.0);     // set all elements to zero
    loadGrid(A);
}

//create the matrix
void Mediator::loadClicked() {
    //create a 5x5 matrix
    A.set_size(5, 5);
    A.fill(fill::randu);
    loadGrid(A);
}

void Mediator::transposeClicked() {
    mat B = A.t();  //compute transpose
    loadGrid(B);    //and load it
}

// and copy it into the wxWidgets grid:
void Mediator::loadGrid(mat C) {
    for (int i = 0; i < C.n_rows; i++) {
        for (int j = 0; j < C.n_cols; j++) {
            numGrid->SetCellValue(i, j, to_string(C(i, j)));
        }
    }
}
    

wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::OnLoad(wxCommandEvent& event) {
    med->loadClicked();
}

// Clear button click event
void Builder::OnTrans(wxCommandEvent& event) {
    med->transposeClicked();
}



=======
// Simple matrix program
// derived from wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".


#include <wx/wxprec.h>
#include <iostream>
#include <armadillo>


//using namespace std;
using namespace arma;
using std::cout;
using std::endl;
using std::to_string;


#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <string.h>
#include "wx/app.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/button.h"
#include "wx/grid.h"
#include <format>
#endif


class Mediator {
private:
    wxGrid* numGrid;
    wxStaticText* sumLbl{ NULL };
    mat A;
public:
    Mediator(wxGrid* grid);
    
    void loadClicked();
    void transposeClicked();
    void loadGrid(mat A);

};

/* This abstract class defines a button with a comd method this is called
when it is clicked.  Derived classes need only fill in the come method*/

class DButton: public wxButton {

// The Mediator class actually executed the code for all button clicks
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

// causes the loading of the data
class LoadButton : public DButton
{
public:
    LoadButton(wxPanel* panel, int id, Mediator* med, wxApp* app) :
        DButton(panel, id, std::string("Load"), med, app)
    {}
        void comd() {
            this->med->loadClicked();
       }
    
};

//creates and displays the transposed matrix
class TransposeButton : public DButton
    {
    public:
        TransposeButton(wxPanel* panel, int id,
            Mediator* med, wxApp* app) :
            DButton(panel, id, "Transpose", med, app) {}
            
            void comd() {
                this->med->transposeClicked();
            } 
    };




//----Creates the numeric grid and buttons
class Builder : public wxApp
{
private:
    
    Mediator* med = NULL;
    wxPanel* panel = NULL;
    wxGrid* numberGrid;

public:
    
    void OnLoad(wxCommandEvent& event);      // Load button event
    void OnTrans(wxCommandEvent& event);    // Transpose button event
   
    bool OnInit()                           // places the widgets in a layout
    {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Display matrix");
        frame->SetBackgroundColour(0xcfcfcf);
        frame->SetSize(450, 250);
       
        panel = new wxPanel(frame, wxID_ANY);
                   
        wxBoxSizer* fgs = new wxBoxSizer(wxVERTICAL);
        panel->SetSizer(fgs);

     
        //create the grid, 5 x 5
        numberGrid = new wxGrid(panel, wxID_ANY,
            wxDefaultPosition, wxSize(450, 150));
        numberGrid->CreateGrid(5, 5);
       
        numberGrid->SetRowLabelSize(30);
        fgs->Add(numberGrid); 
        med = new Mediator(numberGrid);
           
        wxBoxSizer* hs = new wxBoxSizer(wxHORIZONTAL);
        hs->AddSpacer(150);

        // Load button
        LoadButton* addButton = new LoadButton(panel, 1, this->med, this );
        hs->Add(addButton, wxALIGN_CENTER_HORIZONTAL);
        
        addButton->Bind(wxEVT_BUTTON, &Builder::OnLoad, this);

        // Transpose button
        TransposeButton* transButton = new TransposeButton(panel, 3,  this->med, this);
        wxSizerItem* obj = hs->Add(transButton);
        
        transButton->Bind(wxEVT_BUTTON, &Builder::OnTrans, this);
        fgs->Add(hs);     
        frame->Show(true);
        
        return true;
    }

};

Mediator::Mediator(wxGrid* grid) {
    numGrid = grid;
    A.set_size(5, 5); // change the size (data is not preserved)
    A.fill(0.0);     // set all elements to zero
    loadGrid(A);
}

//create the matrix
void Mediator::loadClicked() {
    //create a 5x5 matrix
    A.set_size(5, 5);
    A.fill(fill::randu);
    loadGrid(A);
}

void Mediator::transposeClicked() {
    mat B = A.t();  //compute transpose
    loadGrid(B);    //and load it
}

// and copy it into the wxWidgets grid:
void Mediator::loadGrid(mat C) {
    for (int i = 0; i < C.n_rows; i++) {
        for (int j = 0; j < C.n_cols; j++) {
            numGrid->SetCellValue(i, j, to_string(C(i, j)));
        }
    }
}
    

wxIMPLEMENT_APP(Builder);

// This is the Add button click event
void Builder::OnLoad(wxCommandEvent& event) {
    med->loadClicked();
}

// Clear button click event
void Builder::OnTrans(wxCommandEvent& event) {
    med->transposeClicked();
}



>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
