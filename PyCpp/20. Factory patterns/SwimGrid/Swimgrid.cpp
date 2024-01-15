// wxWidgets "StateList" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>
#include "wx/listbox.h"
#include "wx/grid.h"
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

const int HEAT = 0;
const int LANE = 1;
const int NAME = 2;
const int CLUB = 3;
const int AGE = 4;
const int TIME = 5;

class Mediator {
protected:

	wxListBox* distListBox;
	
	wxGrid* sGrid;

public:
	Mediator(wxListBox* dl, wxGrid* sl);
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

	wxListBox* stateList{ NULL };
	wxListBox* seedList{ NULL };
	wxGrid* seedGrid{ NULL };
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
	SetSize(575, 450);
	Show(true);

	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);//create left and right panels
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(200, 250), wxRAISED_BORDER);
	wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(500, 400), wxRAISED_BORDER);

	bxs->Add(leftPanel);
	bxs->Add(rightPanel);

	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);

	pnlSzr->AddSpacer(10);

	//put a list box with the event names in the left panel
	wxString choices[2] = { "100 free",  "500 free" };
	stateList = new wxListBox(leftPanel, wxID_ANY,
		wxDefaultPosition, wxSize(150, 160), 2, choices, 0L,
		wxDefaultValidator, wxString(""));
	pnlSzr->Add(stateList);

	//create the grid with 6 columns and 100 rows
	seedGrid = new wxGrid(rightPanel, wxID_ANY,
		wxDefaultPosition, wxSize(500, 400));
	seedGrid->CreateGrid(100, 6);
	seedGrid->SetRowLabelSize(0);	//hide the left numbered column
	//set the column labels
	seedGrid->SetColLabelValue(HEAT, wxString("ht")); 
	seedGrid->SetColLabelValue(LANE, wxString("ln"));
	seedGrid->SetColLabelValue(NAME, wxString("name"));
	seedGrid->SetColLabelValue(CLUB, wxString("club"));
	seedGrid->SetColLabelValue(AGE, wxString("age"));
	seedGrid->SetColLabelValue(TIME, wxString("seed"));

	//set column widths
	seedGrid->SetColSize(HEAT, 20);	//heat
	seedGrid->SetColSize(LANE, 20); //lane
	seedGrid->SetColSize(NAME, 150); //name
	seedGrid->SetColSize(CLUB, 50);	//club
	seedGrid->SetColSize(AGE, 30);	//age
	seedGrid->SetColSize(TIME, 70);	//seedtime

	seedGrid->SetColFormatNumber(HEAT);
	seedGrid->SetColFormatNumber(LANE);
	seedGrid->SetColFormatNumber(AGE);
	
	//add grid to right panel
	wxBoxSizer* rightList = new wxBoxSizer(wxVERTICAL);
	rightPanel->SetSizer(rightList);
	rightList->Add(seedGrid);

	med = new Mediator(stateList, seedGrid);

	//either one of these will work
	//Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);
	stateList->Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);

	leftPanel->Show();
	rightPanel->Show();
	this->Layout();
};

void MyFrame::onClick(wxCommandEvent& ev) {
	med->listClick(ev);
}

//----Mediator methods---------
Mediator::Mediator(wxListBox* dl, wxGrid* sl) {
	this->distListBox = dl;
	this->sGrid = sl;
}

//call the current seeding and display the result
void Mediator::doSeeding(Event* event) {
	Seeding* seeding = event->getSeeding();    //factory here
	vector <Swimmer*> swmrs = seeding->getSwimmers();    //do one sort of seeding or the other
	//seedList->Clear();
	//display swimmer list in seeded order
	sGrid->ClearGrid();
	int i = 0;;
	//fill the grid with the swimmer times and seeds
	for (Swimmer* sw : swmrs) {
		sGrid->SetCellValue(i, HEAT, wxString(std::to_string(sw->heat())));
		sGrid->SetCellValue(i, LANE, wxString(std::to_string(sw->lane())));
		sGrid->SetCellValue(i, NAME, wxString(sw->getName()));
		sGrid->SetCellValue(i, CLUB, wxString(sw->getClub()));
		sGrid->SetCellValue(i, AGE, wxString(std::to_string(sw->heat())));
		sGrid->SetCellValue(i, TIME, wxString(sw->getSeed()));
		//string seedLine = format("{:3} {:2} ", sw->heat(), sw->lane());
		//seedLine += format("{:20} {:3} {:4} {:.2f} ", sw->getName(), sw->getAge(),
		//	sw->getClub(), sw->getTime());
		i++;
	}

}
// left list clicked
void Mediator::listClick(wxCommandEvent& ev) {
	//first get the entry clicked on
	int index = distListBox->GetSelection();
	string filename = distListBox->GetString(index).ToStdString();
	int dist = 0;
	bool quit = false;
	
	Event* event{ NULL };

	if (index == 1) {
		dist = 500;
		event = new TimedFinalEvent("500free.txt", 6);
		doSeeding(event);
	}
	else if (index == 0) {
		dist = 100;
		event = new PrelimEvent("100free.txt", 6);
		doSeeding(event);

	}
	

}

