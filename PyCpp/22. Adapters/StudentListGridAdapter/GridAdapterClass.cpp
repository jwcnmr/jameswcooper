<<<<<<< HEAD
#include "GridAdapterClass.h"
#include "baseincludes.h"
#include "wx/window.h"
#include "wx/windowid.h"


GridAdapterClass::GridAdapterClass(wxWindow* parent, wxWindowID id, const wxPoint& pos , const wxSize& size):
	wxGrid( parent, id, wxDefaultPosition, size)
{
	CreateGrid(0, 4);
	SetColSize(0, 40);	//set column sizes
	SetColSize(1, 60);
	SetColSize(2, 20);
	SetColSize(3, 20);

	SetColFormatNumber(2);	//these two are numbers
	SetColFormatNumber(3);
	SetRowLabelSize(0);		//hide row label
	SetColLabelSize(0);		//hide column labels
	SetSelectionMode(wxGrid::wxGridSelectRows); //select whole row

}
//saves the currently clicked row
void GridAdapterClass::onClick(wxGridEvent& event) {
	curRow = event.GetRow();	//save the current row
}
//clear the grid and remove the empty rows
void GridAdapterClass::Clear() {
	ClearGrid();
	//remove the empty cells
	if (GetNumberRows() > 0) {
		DeleteRows(0, GetNumberRows());
	}
}
//find the currently selectd row
int GridAdapterClass::GetSelection() {
	int found = -1; 	int row = 0;
	//loop through cells in first row
	while (found < 0 && (row < GetNumberRows())) {
		if (IsInSelection(row, 0)) {
			found = row;	//save that row
		}
		row++;	//otherwise keep looking
	}
	if (found >= 0) {
		curRow = found;	//save current row here
	}
	return curRow;
}

void GridAdapterClass::setCurrentRow(int row) {
	curRow = row;
}
//This append adds a student to the vector and then adds it to the grid
void GridAdapterClass::append(Student* st) {
	students.push_back(st);	//create vector of student objects
	Append(st);
}

//This Append loads a row of the grid
void GridAdapterClass::Append(Student* st) {
	AppendRows(1);		//append one row
	DeselectRow(0);		//deselect that row
	int rownum = GetNumberRows() - 1;	//here is where to move it
	SetCellValue(rownum, 0, wxString(st->getFrname()));	//first
	SetCellValue(rownum, 1, wxString(st->getLname()));	//last

	//last 2 cells are numbers-- show scores
	SetCellValue(rownum, 2, wxString(std::to_string(st->getIQ())));
	SetCellValue(rownum, 3, wxString(std::to_string(st->getScore())));
}
void GridAdapterClass::redraw() {
	Clear();
	for (int i = 0; i < students.size(); i++) {
		Append(students[i]);
	}
	Refresh();
}
//Delete current row
void GridAdapterClass::Delete() {
	if (curRow >= 0) {
		DeselectRow(curRow); //unselect row before deletion
		DeleteRows(curRow, 1);
		remove(curRow);		//delee from vector
	}
}

Student* GridAdapterClass::getSelected() {
	int index = GetSelection();
	Student* std = students[index];
	return std;
}


void GridAdapterClass::reset() {
	Clear();
	students.clear();
}
//remove student from vector
void GridAdapterClass::remove(int index) {
	students.erase(students.begin() + index);
	redraw();
=======
#include "GridAdapterClass.h"
#include "baseincludes.h"
#include "wx/window.h"
#include "wx/windowid.h"


GridAdapterClass::GridAdapterClass(wxWindow* parent, wxWindowID id, const wxPoint& pos , const wxSize& size):
	wxGrid( parent, id, wxDefaultPosition, size)
{
	CreateGrid(0, 4);
	SetColSize(0, 40);	//set column sizes
	SetColSize(1, 60);
	SetColSize(2, 20);
	SetColSize(3, 20);

	SetColFormatNumber(2);	//these two are numbers
	SetColFormatNumber(3);
	SetRowLabelSize(0);		//hide row label
	SetColLabelSize(0);		//hide column labels
	SetSelectionMode(wxGrid::wxGridSelectRows); //select whole row

}
//saves the currently clicked row
void GridAdapterClass::onClick(wxGridEvent& event) {
	curRow = event.GetRow();	//save the current row
}
//clear the grid and remove the empty rows
void GridAdapterClass::Clear() {
	ClearGrid();
	//remove the empty cells
	if (GetNumberRows() > 0) {
		DeleteRows(0, GetNumberRows());
	}
}
//find the currently selectd row
int GridAdapterClass::GetSelection() {
	int found = -1; 	int row = 0;
	//loop through cells in first row
	while (found < 0 && (row < GetNumberRows())) {
		if (IsInSelection(row, 0)) {
			found = row;	//save that row
		}
		row++;	//otherwise keep looking
	}
	if (found >= 0) {
		curRow = found;	//save current row here
	}
	return curRow;
}

void GridAdapterClass::setCurrentRow(int row) {
	curRow = row;
}
//This append adds a student to the vector and then adds it to the grid
void GridAdapterClass::append(Student* st) {
	students.push_back(st);	//create vector of student objects
	Append(st);
}

//This Append loads a row of the grid
void GridAdapterClass::Append(Student* st) {
	AppendRows(1);		//append one row
	DeselectRow(0);		//deselect that row
	int rownum = GetNumberRows() - 1;	//here is where to move it
	SetCellValue(rownum, 0, wxString(st->getFrname()));	//first
	SetCellValue(rownum, 1, wxString(st->getLname()));	//last

	//last 2 cells are numbers-- show scores
	SetCellValue(rownum, 2, wxString(std::to_string(st->getIQ())));
	SetCellValue(rownum, 3, wxString(std::to_string(st->getScore())));
}
void GridAdapterClass::redraw() {
	Clear();
	for (int i = 0; i < students.size(); i++) {
		Append(students[i]);
	}
	Refresh();
}
//Delete current row
void GridAdapterClass::Delete() {
	if (curRow >= 0) {
		DeselectRow(curRow); //unselect row before deletion
		DeleteRows(curRow, 1);
		remove(curRow);		//delee from vector
	}
}

Student* GridAdapterClass::getSelected() {
	int index = GetSelection();
	Student* std = students[index];
	return std;
}


void GridAdapterClass::reset() {
	Clear();
	students.clear();
}
//remove student from vector
void GridAdapterClass::remove(int index) {
	students.erase(students.begin() + index);
	redraw();
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}