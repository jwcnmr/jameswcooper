<<<<<<< HEAD
#include "Mediator.h"
#include "State.h"
#include "States.h"
#include <wx/wxprec.h>
#include "wx/grid.h"

#include <iostream>
#include <fstream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

//Mediator constructor gets copy of grid
Mediator::Mediator(wxGrid* sl) {
	stateGrid = sl;
}


// and give it the States object with the list of States
void Mediator::setStateList(States* slist) {
	stateList = slist;
}

//Save data for selected state
void Mediator::saveState(wxGridEvent& gev) {
	int row = gev.GetRow();
	int col = gev.GetCol();
	//get the changed cell text
	string gtext = stateGrid->GetCellValue(row, col).ToStdString();
	State* state = stateList->getState(row);

	//convert column number to a property
	//and save it back into the state vector
	switch (col) {
		case 0: state->setName(gtext); break;
		case 1: state->setAbbrev(gtext); break;
		case 2: state->setCapital(gtext); break;
		case 3: state->setDate(gtext); break;
	}
}
void Mediator::rangeClick(wxCommandEvent& ev) {
	std::vector <wxString> tokens;  //strings saved here
	//go through all the rows
	for (int i = 0; i < stateGrid->GetNumberRows(); ++i) {
		if (stateGrid->IsInSelection(i, 0)) {
			//go through each column in that row
			for (int c = 0; c < stateGrid->GetNumberCols(); c++) {
				if (stateGrid->IsInSelection(i, c)) {
					tokens.push_back(stateGrid->GetCellValue(i, c));
				}
			}
		}
	}
	//now create a Message Dialog with the result
	string message = "";
	for (int i = 0; i < tokens.size(); i++) {
		message += tokens[i] + ", ";
	}
	wxMessageDialog* dial = new wxMessageDialog(NULL,
		wxString(message), wxT("Cells selected"), wxOK);
	dial->ShowModal();
}

void Mediator::saveStates() {
	//save all the states to a new file
	ofstream stFile("states1.txt");
	vector<State*> stateVector = stateList->getStates();
	for (auto iter(stateVector.begin()); 
		iter != stateVector.end(); ++iter) {
		State* st = *iter;
		//get comma sep string
		string output = st->getLineString(); 
		stFile << output << endl;	//and writ it
	}
	stFile.close();
}


=======
#include "Mediator.h"
#include "State.h"
#include "States.h"
#include <wx/wxprec.h>
#include "wx/grid.h"

#include <iostream>
#include <fstream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

//Mediator constructor gets copy of grid
Mediator::Mediator(wxGrid* sl) {
	stateGrid = sl;
}


// and give it the States object with the list of States
void Mediator::setStateList(States* slist) {
	stateList = slist;
}

//Save data for selected state
void Mediator::saveState(wxGridEvent& gev) {
	int row = gev.GetRow();
	int col = gev.GetCol();
	//get the changed cell text
	string gtext = stateGrid->GetCellValue(row, col).ToStdString();
	State* state = stateList->getState(row);

	//convert column number to a property
	//and save it back into the state vector
	switch (col) {
		case 0: state->setName(gtext); break;
		case 1: state->setAbbrev(gtext); break;
		case 2: state->setCapital(gtext); break;
		case 3: state->setDate(gtext); break;
	}
}
void Mediator::rangeClick(wxCommandEvent& ev) {
	std::vector <wxString> tokens;  //strings saved here
	//go through all the rows
	for (int i = 0; i < stateGrid->GetNumberRows(); ++i) {
		if (stateGrid->IsInSelection(i, 0)) {
			//go through each column in that row
			for (int c = 0; c < stateGrid->GetNumberCols(); c++) {
				if (stateGrid->IsInSelection(i, c)) {
					tokens.push_back(stateGrid->GetCellValue(i, c));
				}
			}
		}
	}
	//now create a Message Dialog with the result
	string message = "";
	for (int i = 0; i < tokens.size(); i++) {
		message += tokens[i] + ", ";
	}
	wxMessageDialog* dial = new wxMessageDialog(NULL,
		wxString(message), wxT("Cells selected"), wxOK);
	dial->ShowModal();
}

void Mediator::saveStates() {
	//save all the states to a new file
	ofstream stFile("states1.txt");
	vector<State*> stateVector = stateList->getStates();
	for (auto iter(stateVector.begin()); 
		iter != stateVector.end(); ++iter) {
		State* st = *iter;
		//get comma sep string
		string output = st->getLineString(); 
		stFile << output << endl;	//and writ it
	}
	stFile.close();
}


>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
