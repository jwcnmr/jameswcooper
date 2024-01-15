
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>

#endif
#include <string>
#include "wx/app.h"
#include "wx/sizer.h"

#include "wx/button.h"

#include "DButton.h"


   DButton::DButton(wxPanel* panel, int id, const std::string label, Mediator* med) :
        wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize)
    {
        this->med = med;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }

    //abstract method to be completed in derived classes 
    // void comd(wxCommandEvent& event) {}


