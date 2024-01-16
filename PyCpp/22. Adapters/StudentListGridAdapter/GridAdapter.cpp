#include "GridAdapter.h"
#include "StrFuncs.h"
#include "baseincludes.h"


GridAdapter::GridAdapter(wxGrid* grd) {
	grid = grd;
	grid->CreateGrid(0, 4);
	grid->SetColSize(0, 40);	//set column sizes
	grid->SetColSize(1, 60);
	grid->SetColSize(2, 20);
	grid->SetColSize(3, 20);

	grid->SetColFormatNumber(2);	//these two are numbers
	grid->SetColFormatNumber(3);
	grid->SetRowLabelSize(0);		//hide row label
	grid->SetColLabelSize(0);		//hide column labels
	grid->SetSelectionMode(wxGrid::wxGridSelectRows); //select whole row

}
//saves the currently clicked row
void GridAdapter::onClick(wxGridEvent& event) {
	curRow = event.GetRow();	//save the current row
}
//clear the grid and remove the empty rows
void GridAdapter::Clear() {
	grid->ClearGrid();
	//remove the empty cells
	if (grid->GetNumberRows() > 0) {
		grid->DeleteRows(0, grid->GetNumberRows());
	}
}
int GridAdapter::GetSelection() {
	int found = -1;
	int row = 0;
	while (found < 0 && (row < grid->GetNumberRows()) ) {
	if (grid->IsInSelection(row, 0)) {
			found = row;
		}
		row++;
	}
	if (found >= 0) {
		curRow = found;
		grid->SelectRow(curRow);
		
	}
	return curRow;
}

void GridAdapter::setCurrentRow(int row) {
	curRow = row;
}
//This append adds a student to the vector and then adds it to the grid
void GridAdapter::append(Student* st) {
	students.push_back(st);	//create vector of student objects
	Append(st);
}

//This Append loads a row of the grid
void GridAdapter::Append(Student* st) {
	grid->AppendRows(1);		//append one row
	grid->DeselectRow(0);		//deselect that row
	int rownum = grid->GetNumberRows() - 1;	//here is where to move it
	grid->SetCellValue(rownum, 0, wxString(st->getFrname()));	//first
	grid->SetCellValue(rownum, 1, wxString(st->getLname()));	//last
	
	//last 2 cells are numbers-- show scores
	grid->SetCellValue(rownum, 2, wxString(std::to_string(st->getIQ())));
	grid->SetCellValue(rownum, 3, wxString(std::to_string(st->getScore())));
}
void GridAdapter::redraw() {
	Clear();
	for (int i = 0; i < students.size(); i++) {
		Append(students[i]);
	}
	Refresh();
}
void GridAdapter::Delete() {
	if (curRow >= 0) {
		grid->DeselectRow(curRow); //unselect row before deletion
		grid->DeleteRows(curRow, 1);
		remove(curRow);
	}
}

Student* GridAdapter::getSelected() {
	int index = GetSelection();
	Student* std = students[index];
	return std;
}

void GridAdapter::Refresh() {
	grid->Refresh();
}
void GridAdapter::reset() {
	Clear();
	students.clear(); 
}
void GridAdapter::remove(int index) {
	students.erase(students.begin() + index);
	redraw();
}