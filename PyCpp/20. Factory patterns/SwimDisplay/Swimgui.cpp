// wxWidgets SwimGUI Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>
#include "wx/listbox.h"
#include <iostream>
#include <fstream>
#include "SwmHeaders.h"
#include "Seeding.h"
#include "Event.h"
#include "TimedFinalEvent.h"
#include "PrelimEvent.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


//String functions
using std::string;
using std::ifstream;
using std::vector;
using std::cout;


class Mediator {
protected:

	wxListBox* distListBox;	
	wxListBox* seedList;

public:
	Mediator(wxListBox* dl, wxListBox* sl);
	void listClick(wxCommandEvent& ev);
	void doSeeding(Event* event);
};


class Builder : public wxApp {
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
	MyFrame();
	void onClick(wxCommandEvent& ev);

private:
	
	wxListBox* distList{ NULL };
	wxListBox* seedList{ NULL };
	wxBoxSizer* pnlSzr{ NULL };
	wxBoxSizer* seedSzr{ NULL };

	Mediator* med{ NULL };
	int idBase = 0;
};


wxIMPLEMENT_APP(Builder);

bool Builder::OnInit() {
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame()
	: wxFrame(NULL, wxID_ANY, "Swim seeding") {
	SetBackgroundColour(0xcfcfcf);
	SetSize(550, 250);
	Show(true);

	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);
	SetSizer(bxs);
	bxs->Show(true);

	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(200, 250), wxRAISED_BORDER);
	wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(350, 250), wxRAISED_BORDER);

	bxs->Add(leftPanel);
	bxs->Add(rightPanel);

	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);

	pnlSzr->AddSpacer(10);

	wxString choices[2] = { "100 free", "500 free" };
	distList = new wxListBox(leftPanel, wxID_ANY,
		wxDefaultPosition, wxSize(150, 160), 2, choices, 0L,
		wxDefaultValidator, wxString(""));
	pnlSzr->Add(distList);

	seedList = new wxListBox(rightPanel, wxID_ANY,
		wxDefaultPosition, wxSize(350, 160), 0, NULL, 0L,
		wxDefaultValidator, wxString(""));
	seedList->SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,false, wxT("Courier New")));
		

	wxBoxSizer* rightList = new wxBoxSizer(wxVERTICAL);
	rightPanel->SetSizer(rightList);
	rightList->Add(seedList);

	med = new Mediator(distList, seedList);

	//either one of these will work
	//Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);
	distList->Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);

	leftPanel->Show();
	this->Layout();
};

void MyFrame::onClick(wxCommandEvent& ev) {
	med->listClick(ev);
}

//----Mediator methods---------
Mediator::Mediator(wxListBox* dl, wxListBox* sl) {
	this->distListBox = dl;
	this->seedList = sl;
}

//call the current seeding and display the result
void Mediator::doSeeding(Event* event) {
	Seeding* seeding = event->getSeeding();    //factory here
	vector <Swimmer*> swmrs = seeding->getSwimmers();    //do one sort of seeding or the other
	seedList->Clear();
	//display swimmer list in seeded order
	for (Swimmer* sw : swmrs) {	
		string seedLine = format("{:3} {:2} ", sw->heat(), sw->lane());
		seedLine += format("{:20} {:3} {:4} {:.2f} ", sw->getName(), sw->getAge(),
			sw->getClub(), sw->getTime());
		seedList->Append(wxString(seedLine));
	}

}

void Mediator::listClick(wxCommandEvent& ev) {
	//first get the entry clicked on
	int index = distListBox->GetSelection();
	string filename = distListBox->GetString(index).ToStdString();
	int dist = 0;
	bool quit = false;
	//while (!quit) {
		Event* event{ NULL };
		
		if (index==1) {
			event = new TimedFinalEvent("500free.txt", 6);
			doSeeding(event);
		}
		else if (index==0) {
			event = new PrelimEvent("100free.txt", 6);
			doSeeding(event);
				


	}


	

	
}

