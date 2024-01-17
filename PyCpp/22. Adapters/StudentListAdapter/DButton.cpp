<<<<<<< HEAD
#include "DButton.h"

// abstract base command button class
//binds clicks to the comd method
    DButton::DButton(wxPanel* panel, int id, const std::string label, Mediator* med) :
        wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize)
    {
        this->med = med;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }

    //command method to be completed in derived classes 
    void DButton::comd(wxCommandEvent& event) {};


//clicks on each button go to the Mediator 
// which sets a flag to make that plant name visible

    MoveButton::MoveButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Move--->", med) {
    }
    void MoveButton::comd(wxCommandEvent& event) {
        med->moveClick();
    }


    RestoreButton::RestoreButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "<---Restore", med) {

    }
    void RestoreButton::comd(wxCommandEvent& event) {
        med->restoreClick();
    }


    ClearButton::ClearButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Clear", med) {
        
    }
    void ClearButton::comd(wxCommandEvent& event) {
        med->clearClick();
    }

=======
#include "DButton.h"

// abstract base command button class
//binds clicks to the comd method
    DButton::DButton(wxPanel* panel, int id, const std::string label, Mediator* med) :
        wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize)
    {
        this->med = med;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }

    //command method to be completed in derived classes 
    void DButton::comd(wxCommandEvent& event) {};


//clicks on each button go to the Mediator 
// which sets a flag to make that plant name visible

    MoveButton::MoveButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Move--->", med) {
    }
    void MoveButton::comd(wxCommandEvent& event) {
        med->moveClick();
    }


    RestoreButton::RestoreButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "<---Restore", med) {

    }
    void RestoreButton::comd(wxCommandEvent& event) {
        med->restoreClick();
    }


    ClearButton::ClearButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Clear", med) {
        
    }
    void ClearButton::comd(wxCommandEvent& event) {
        med->clearClick();
    }

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
