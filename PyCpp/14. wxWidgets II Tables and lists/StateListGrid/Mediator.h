#pragma once
#include "BlueLabel.h"
#include "wx/grid.h"
#include <string>
#include "States.h"
/* communicates between visual controls*/
class Mediator {
protected:

	//	wxListBox* stateListBox {NULL};
	wxGrid* stateGrid{ NULL };
	BlueLabel* lbName{ NULL };
	BlueLabel* lbAbbrev{ NULL };
	BlueLabel* lbDate{ NULL };
	BlueLabel* lbCapital{ NULL };
	States* stateList{ NULL };


public:
	Mediator(wxGrid* sl);

	void setStateList(States* slist);
	void saveState(wxGridEvent& ev);
	void rangeClick(wxCommandEvent& ev);
	void saveStates();

};
