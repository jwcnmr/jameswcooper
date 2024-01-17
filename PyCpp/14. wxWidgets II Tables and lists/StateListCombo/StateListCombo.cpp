<<<<<<< HEAD
// wxWidgets "StateList" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string>
#include <wx/combobox.h>

#include "StrFuncs.h"
#include "BlueLabel.h"
#include "State.h"
#include "States.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


/* communicates between visual controls*/
class Mediator {
protected:

	wxComboBox* stateListBox {NULL};
	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	States* stateList{ NULL };


public:
	Mediator(wxComboBox* sl);
	void listClick(wxCommandEvent& ev, int idBase);
	void setLabels(BlueLabel* name, BlueLabel* abbrev, BlueLabel* date, BlueLabel* capital);
	void setStateList(States* slist);

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

	void onClick(wxCommandEvent& ev);


private:

	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	wxComboBox* stateList{ NULL };
	wxBoxSizer* pnlSzr{ NULL };

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
	SetBackgroundColour(0xcfcfcf);
	SetSize(320, 250);
	Show(true);

	//cfreat two panels
	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(200, 150), wxRAISED_BORDER);
	wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(100, 150), wxRAISED_BORDER);

	bxs->Add(leftPanel);
	bxs->Add(rightPanel);


	// Put list box in left panel
	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);
	pnlSzr->AddSpacer(10);

	stateList = new wxComboBox(leftPanel, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY, wxDefaultValidator, wxString(""));
	pnlSzr->Add(stateList);
	med = new Mediator(stateList);

	// Put labels in right panel
	wxBoxSizer* rightList = new wxBoxSizer(wxVERTICAL);
	rightPanel->SetSizer(rightList);

	lbName = new BlueLabel(rightPanel, wxID_ANY, "name");
	rightList->Add(lbName);
	rightList->AddSpacer(5);

	lbAbbrev = new BlueLabel(rightPanel, wxID_ANY, "abbrev");
	rightList->Add(lbAbbrev);
	rightList->AddSpacer(5);

	lbDate = new BlueLabel(rightPanel, wxID_ANY, "date");
	rightList->Add(lbDate);
	rightList->AddSpacer(5);

	lbCapital = new BlueLabel(rightPanel, wxID_ANY, "capital");
	rightList->Add(lbCapital);

	//read in states
	States* sList = new States("States.txt");
	//StateList* sList = new StateList("StateList/StateList/States.txt");
	med->setStateList(sList);
	med->setLabels(lbName, lbAbbrev, lbDate, lbCapital);

	// create a vector list of State objects
	// and then insert the names of the states in the combobox
	std::vector<State*> states = sList->getStates();
	for (int i = 0; i < states.size(); i++) {
		stateList->Append(wxString(states[i]->getName()));

	}

	//connect item click to the onClick method
	Bind(wxEVT_COMBOBOX, &MyFrame::onClick, this);

	leftPanel->Show();
	this->Layout();
};

//click event tells Mediator to load labels with state details
void MyFrame::onClick(wxCommandEvent& ev) {
	med->listClick(ev, idBase);
}

//Mediator constructor gets copy of listbos
Mediator::Mediator(wxComboBox* lb) {
	this->stateListBox = lb;
}

// give the Mediator the 4 label pointers
void Mediator::setLabels(BlueLabel* name, BlueLabel* abbrev, BlueLabel* date, BlueLabel* capital) {
	lbName = name;
	lbAbbrev = abbrev;
	lbDate = date;
	lbCapital = capital;
}

// and give it the States object with the list of States
void Mediator::setStateList(States* slist) {
	stateList = slist;
}

// Mediator loads the labels when a listbox item is selected
void Mediator::listClick(wxCommandEvent& ev, int idBase) {
	int index = stateListBox->GetSelection();
	State* state = stateList->getState(index);
	lbName->SetLabelText(state->getName());
	lbAbbrev->SetLabelText(state->getAbbrev());
	lbDate->SetLabelText(state->getDate());
	lbCapital->SetLabelText(state->getCapital());
}

=======
// wxWidgets "StateList" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string>
#include <wx/combobox.h>

#include "StrFuncs.h"
#include "BlueLabel.h"
#include "State.h"
#include "States.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


/* communicates between visual controls*/
class Mediator {
protected:

	wxComboBox* stateListBox {NULL};
	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	States* stateList{ NULL };


public:
	Mediator(wxComboBox* sl);
	void listClick(wxCommandEvent& ev, int idBase);
	void setLabels(BlueLabel* name, BlueLabel* abbrev, BlueLabel* date, BlueLabel* capital);
	void setStateList(States* slist);

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

	void onClick(wxCommandEvent& ev);


private:

	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	wxComboBox* stateList{ NULL };
	wxBoxSizer* pnlSzr{ NULL };

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
	SetBackgroundColour(0xcfcfcf);
	SetSize(320, 250);
	Show(true);

	//cfreat two panels
	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(200, 150), wxRAISED_BORDER);
	wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(100, 150), wxRAISED_BORDER);

	bxs->Add(leftPanel);
	bxs->Add(rightPanel);


	// Put list box in left panel
	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);
	pnlSzr->AddSpacer(10);

	stateList = new wxComboBox(leftPanel, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY, wxDefaultValidator, wxString(""));
	pnlSzr->Add(stateList);
	med = new Mediator(stateList);

	// Put labels in right panel
	wxBoxSizer* rightList = new wxBoxSizer(wxVERTICAL);
	rightPanel->SetSizer(rightList);

	lbName = new BlueLabel(rightPanel, wxID_ANY, "name");
	rightList->Add(lbName);
	rightList->AddSpacer(5);

	lbAbbrev = new BlueLabel(rightPanel, wxID_ANY, "abbrev");
	rightList->Add(lbAbbrev);
	rightList->AddSpacer(5);

	lbDate = new BlueLabel(rightPanel, wxID_ANY, "date");
	rightList->Add(lbDate);
	rightList->AddSpacer(5);

	lbCapital = new BlueLabel(rightPanel, wxID_ANY, "capital");
	rightList->Add(lbCapital);

	//read in states
	States* sList = new States("States.txt");
	//StateList* sList = new StateList("StateList/StateList/States.txt");
	med->setStateList(sList);
	med->setLabels(lbName, lbAbbrev, lbDate, lbCapital);

	// create a vector list of State objects
	// and then insert the names of the states in the combobox
	std::vector<State*> states = sList->getStates();
	for (int i = 0; i < states.size(); i++) {
		stateList->Append(wxString(states[i]->getName()));

	}

	//connect item click to the onClick method
	Bind(wxEVT_COMBOBOX, &MyFrame::onClick, this);

	leftPanel->Show();
	this->Layout();
};

//click event tells Mediator to load labels with state details
void MyFrame::onClick(wxCommandEvent& ev) {
	med->listClick(ev, idBase);
}

//Mediator constructor gets copy of listbos
Mediator::Mediator(wxComboBox* lb) {
	this->stateListBox = lb;
}

// give the Mediator the 4 label pointers
void Mediator::setLabels(BlueLabel* name, BlueLabel* abbrev, BlueLabel* date, BlueLabel* capital) {
	lbName = name;
	lbAbbrev = abbrev;
	lbDate = date;
	lbCapital = capital;
}

// and give it the States object with the list of States
void Mediator::setStateList(States* slist) {
	stateList = slist;
}

// Mediator loads the labels when a listbox item is selected
void Mediator::listClick(wxCommandEvent& ev, int idBase) {
	int index = stateListBox->GetSelection();
	State* state = stateList->getState(index);
	lbName->SetLabelText(state->getName());
	lbAbbrev->SetLabelText(state->getAbbrev());
	lbDate->SetLabelText(state->getDate());
	lbCapital->SetLabelText(state->getCapital());
}

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
