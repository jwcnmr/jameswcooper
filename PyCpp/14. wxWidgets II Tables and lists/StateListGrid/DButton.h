#pragma once
#include <wx/wxprec.h>

#include "wx/grid.h"
#include "Mediator.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class DButton : public wxButton {

    // The Mediator class actually executes the code for all button clicks
protected:
    Mediator* med;

public:
    DButton(wxPanel* panel, int id, const std::string label, Mediator* med);

    //abstract method to be completed in derived classes 
    virtual void comd(wxCommandEvent& event) = 0;

};