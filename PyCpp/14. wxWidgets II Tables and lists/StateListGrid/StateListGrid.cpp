<<<<<<< HEAD
// wxWidgets "StateGrid" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string>

#include "wx/grid.h"


#include "StrFuncs.h"
#include "BlueLabel.h"
#include "State.h"
#include "States.h"
#include "Mediator.h"
#include "DButton.h"


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
using std::string;
using std::vector;



// causes the addition
class SelectButton : public DButton
{
public:
	SelectButton(wxPanel* panel, int id, Mediator* med) :
		DButton(panel, id, std::string("Show select"), med) {}

	void comd(wxCommandEvent& event) {
		med->rangeClick(event);
	}

};

//clears the entry fields and sum labell
class SaveButton : public DButton
{
public:
	SaveButton(wxPanel* panel, int id,
		Mediator* med) :
		DButton(panel, id, "Save", med) {}


	void comd(wxCommandEvent& event) {
		med->saveStates();
	}

};


/* Construct the UI*/
class BuildApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();

	void saveClick(wxGridEvent& ev);
	

private:

	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	
	wxGrid* stateGrid{ NULL };
	wxBoxSizer* pnlSzr{ NULL };
	wxBoxSizer* butnSzr{ NULL };
	SelectButton* selectButn{ NULL };
	SaveButton* saveButn{ NULL };

	Mediator* med{ NULL };
	int idBase = 0;
};


wxIMPLEMENT_APP(BuildApp);

bool BuildApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);

	return true;
}

/* constructs actual UI */
MyFrame::MyFrame()
	: wxFrame(NULL, wxID_ANY, "State List")
{
	SetBackgroundColour(0xdfdfdf);
	SetSize(325, 350);
	Show(true);

	//create a panel
	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(400, 300), wxRAISED_BORDER);

	bxs->Add(leftPanel);

	// Put grid in left panel
	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	pnlSzr->AddSpacer(10);

	//create the gris, 50 x 4
	stateGrid = new wxGrid(leftPanel, wxID_ANY, 
		wxDefaultPosition, wxSize(400, 225));
	stateGrid->CreateGrid(50, 4);
	stateGrid->SetColSize(1, 40);	//set column sizes
	stateGrid->SetColSize(3, 60);
	stateGrid->SetRowLabelSize(30);
	pnlSzr->Add(stateGrid);
	med = new Mediator(stateGrid);
	
	butnSzr = new wxBoxSizer(wxHORIZONTAL);
	pnlSzr->Add(butnSzr, wxALIGN_CENTER);
	butnSzr->AddSpacer(55);
	selectButn = new SelectButton(leftPanel, wxID_ANY, med);
	butnSzr->Add(selectButn,0, wxALIGN_CENTER);
	 
	butnSzr->AddSpacer(10);
	saveButn = new SaveButton(leftPanel, wxID_ANY, med);
	butnSzr->Add(saveButn, 0, wxALIGN_CENTER);

	// create a vector list of State objects
	States* sList = new States("States.txt");
	med->setStateList(sList);

	// and then insert the values for the states into the grid
	vector<State*> states = sList->getStates();
	for (int i = 0; i < states.size(); i++) {
		stateGrid->SetCellValue(i, 0, wxString(states[i]->getName()));
		stateGrid->SetCellValue(i, 1, wxString(states[i]->getAbbrev()));
		stateGrid->SetCellValue(i, 2, wxString(states[i]->getCapital()));
		stateGrid->SetCellValue(i, 3, wxString(states[i]->getDate()));
	}

	//connect item click to the onClick method
	Bind(wxEVT_GRID_CELL_CHANGED, &MyFrame::saveClick, this);
	

	leftPanel->Show();
	this->Layout();
}

//click event tells Mediator to save a state back to the vector
void MyFrame::saveClick(wxGridEvent& ev) {
	med->saveState(ev);
}

=======
// wxWidgets "StateGrid" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string>

#include "wx/grid.h"


#include "StrFuncs.h"
#include "BlueLabel.h"
#include "State.h"
#include "States.h"
#include "Mediator.h"
#include "DButton.h"


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
using std::string;
using std::vector;



// causes the addition
class SelectButton : public DButton
{
public:
	SelectButton(wxPanel* panel, int id, Mediator* med) :
		DButton(panel, id, std::string("Show select"), med) {}

	void comd(wxCommandEvent& event) {
		med->rangeClick(event);
	}

};

//clears the entry fields and sum labell
class SaveButton : public DButton
{
public:
	SaveButton(wxPanel* panel, int id,
		Mediator* med) :
		DButton(panel, id, "Save", med) {}


	void comd(wxCommandEvent& event) {
		med->saveStates();
	}

};


/* Construct the UI*/
class BuildApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();

	void saveClick(wxGridEvent& ev);
	

private:

	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	
	wxGrid* stateGrid{ NULL };
	wxBoxSizer* pnlSzr{ NULL };
	wxBoxSizer* butnSzr{ NULL };
	SelectButton* selectButn{ NULL };
	SaveButton* saveButn{ NULL };

	Mediator* med{ NULL };
	int idBase = 0;
};


wxIMPLEMENT_APP(BuildApp);

bool BuildApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);

	return true;
}

/* constructs actual UI */
MyFrame::MyFrame()
	: wxFrame(NULL, wxID_ANY, "State List")
{
	SetBackgroundColour(0xdfdfdf);
	SetSize(325, 350);
	Show(true);

	//create a panel
	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(400, 300), wxRAISED_BORDER);

	bxs->Add(leftPanel);

	// Put grid in left panel
	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	pnlSzr->AddSpacer(10);

	//create the gris, 50 x 4
	stateGrid = new wxGrid(leftPanel, wxID_ANY, 
		wxDefaultPosition, wxSize(400, 225));
	stateGrid->CreateGrid(50, 4);
	stateGrid->SetColSize(1, 40);	//set column sizes
	stateGrid->SetColSize(3, 60);
	stateGrid->SetRowLabelSize(30);
	pnlSzr->Add(stateGrid);
	med = new Mediator(stateGrid);
	
	butnSzr = new wxBoxSizer(wxHORIZONTAL);
	pnlSzr->Add(butnSzr, wxALIGN_CENTER);
	butnSzr->AddSpacer(55);
	selectButn = new SelectButton(leftPanel, wxID_ANY, med);
	butnSzr->Add(selectButn,0, wxALIGN_CENTER);
	 
	butnSzr->AddSpacer(10);
	saveButn = new SaveButton(leftPanel, wxID_ANY, med);
	butnSzr->Add(saveButn, 0, wxALIGN_CENTER);

	// create a vector list of State objects
	States* sList = new States("States.txt");
	med->setStateList(sList);

	// and then insert the values for the states into the grid
	vector<State*> states = sList->getStates();
	for (int i = 0; i < states.size(); i++) {
		stateGrid->SetCellValue(i, 0, wxString(states[i]->getName()));
		stateGrid->SetCellValue(i, 1, wxString(states[i]->getAbbrev()));
		stateGrid->SetCellValue(i, 2, wxString(states[i]->getCapital()));
		stateGrid->SetCellValue(i, 3, wxString(states[i]->getDate()));
	}

	//connect item click to the onClick method
	Bind(wxEVT_GRID_CELL_CHANGED, &MyFrame::saveClick, this);
	

	leftPanel->Show();
	this->Layout();
}

//click event tells Mediator to save a state back to the vector
void MyFrame::saveClick(wxGridEvent& ev) {
	med->saveState(ev);
}

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
