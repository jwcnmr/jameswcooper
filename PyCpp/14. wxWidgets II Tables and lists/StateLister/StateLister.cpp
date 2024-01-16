// wxWidgets "StateList" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <string.h>
#include "wx/listbox.h"
#include <iostream>
#include <fstream>
#include "State.h"
#include "Strfuncs.h"
#include "BlueLabel.h"


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


//String functions
using std::string;
using std::ifstream;
using std::vector;
using std::cout;

//reads and keeps the State list
class StateList {
private:
	vector<State*> states;

public:
	//read in the States file and store eachState in a vector
	StateList(string fileName) {

		ifstream myfile(fileName);
		string line;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				states.push_back(new State(line));
			}
			myfile.close();
		}
		else cout << "Unable to open file";
	}
	//get the whole vector
	vector<State*> getStates() {
		return states;
	}
	//get a single state
	State* getState(int index) {
		return states[index];
	}
};



class Mediator {
protected:

	wxListBox* stateListBox;
	BlueLabel* lbName;
	BlueLabel* lbAbbrev;
	BlueLabel* lbDate;
	BlueLabel* lbCapital;
	StateList* stateList;


public:
	Mediator(wxListBox* sl);
	void listClick(wxCommandEvent& ev);
	void setLabels(BlueLabel* name, BlueLabel* abbrev, BlueLabel* date, BlueLabel* capital);
	void setStateList(StateList* slist);
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
	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	wxListBox* stateList{ NULL };
	wxBoxSizer* pnlSzr{ NULL };

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
	: wxFrame(NULL, wxID_ANY, "State List") {
	SetBackgroundColour(0xcfcfcf);
	SetSize(320, 250);
	Show(true);

	wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);

	SetSizer(bxs);
	bxs->Show(true);
	wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(200, 250), wxRAISED_BORDER);
	wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
		wxSize(100, 250), wxRAISED_BORDER);

	bxs->Add(leftPanel);
	bxs->Add(rightPanel);

	pnlSzr = new wxBoxSizer(wxVERTICAL);
	leftPanel->SetSizer(pnlSzr);
	wxBoxSizer* filler0 = new wxBoxSizer(wxVERTICAL);
	
	pnlSzr->AddSpacer(10);

	stateList = new wxListBox(leftPanel, wxID_ANY, 
		wxDefaultPosition, wxSize(150, 160), 0, NULL, 0L, 
		wxDefaultValidator, wxString(""));
	pnlSzr->Add(stateList);
	med = new Mediator(stateList);

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
	StateList* sList = new StateList("States.txt");
	med->setStateList(sList);
	med->setLabels(lbName, lbAbbrev, lbDate, lbCapital);

	
	//either one of these will work
	//Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);
	stateList->Bind(wxEVT_LISTBOX, &MyFrame::onClick, this);

	leftPanel->Show();
	this->Layout();
};

void MyFrame::onClick(wxCommandEvent& ev) {
	med->listClick(ev);
}

//----Mediator methods---------
Mediator::Mediator(wxListBox* lb) {
	this->stateListBox = lb;
}

void Mediator::setLabels(BlueLabel* name, BlueLabel* abbrev, 
	BlueLabel* date, BlueLabel* capital) {
	//copy addresses of labels into the Mediator
	lbName = name;
	lbAbbrev = abbrev;
	lbDate = date;
	lbCapital = capital;
}

void Mediator::setStateList(StateList* slist) {
	stateList = slist;  

	//get the vector and load the listbox
	vector<State*> states = stateList->getStates();
	for (int i = 0; i < states.size(); i++) {
		stateListBox->Append(wxString(states[i]->getName()));
	}
}

void Mediator::listClick(wxCommandEvent& ev) {
	//first get the entry clicked on
	int index = stateListBox->GetSelection(); 
	
	//then get the state object at that index
	State* state = stateList->getState(index);
	
	//load the labels with that State's data
	lbName->SetLabelText(state->getName());
	lbAbbrev->SetLabelText(state->getAbbrev());
	lbDate->SetLabelText(state->getDate());
	lbCapital->SetLabelText(state->getCapital());
}

