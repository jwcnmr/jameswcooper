<<<<<<< HEAD
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "BlueLabel.h"

//----A derived class for blue labels-------

	BlueLabel::BlueLabel(wxPanel* parent, int id, const wxString& label) :
		wxStaticText(parent, id, label) 	{
		//this->SetForegroundColour(wxColour(0, 0, 200));
		SetForegroundColour("blue");
		wxFont font = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL, FALSE, "");
		this->SetFont(font);
	}
=======
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "BlueLabel.h"

//----A derived class for blue labels-------

	BlueLabel::BlueLabel(wxPanel* parent, int id, const wxString& label) :
		wxStaticText(parent, id, label) 	{
		//this->SetForegroundColour(wxColour(0, 0, 200));
		SetForegroundColour("blue");
		wxFont font = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL, FALSE, "");
		this->SetFont(font);
	}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
