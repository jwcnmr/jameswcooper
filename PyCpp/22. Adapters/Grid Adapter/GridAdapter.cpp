<<<<<<< HEAD
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
//int GridAdapter::GetSelection() {
//	return curRow;
//}

void GridAdapter::setCurrentRow(int row) {
	curRow = row;
}
void GridAdapter::Append(wxString wname) {
	grid->AppendRows(1);		//append one row
	grid->DeselectRow(0);		//deselect that row
	int rownum = grid->GetNumberRows() - 1;	//here is where to move it
	string name = wname.ToStdString();		//separate at space
	vector<string> names = Strfuncs::split(name, " ");
	grid->SetCellValue(rownum, 0, wxString(names[0]));	//first
	grid->SetCellValue(rownum, 1, wxString(names[1]));	//last
	//get lengths of first and last name
	//last 2 cells are numbers
	grid->SetCellValue(rownum, 2, wxString(std::to_string(names[0].size())));
	grid->SetCellValue(rownum, 3, wxString(std::to_string(names[1].size())));
}

void GridAdapter::Delete() {
	if (curRow >= 0) {
		grid->DeselectRow(curRow); //unselect row before deletion
		grid->DeleteRows(curRow, 1);
	}
}
wxString GridAdapter::GetString(int index) {
	wxString frname = grid->GetCellValue(index, 0);
	wxString lname = grid->GetCellValue(index, 1);
	return frname + " " + lname;
}

void GridAdapter::Refresh() {
	grid->Refresh();
=======
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
//int GridAdapter::GetSelection() {
//	return curRow;
//}

void GridAdapter::setCurrentRow(int row) {
	curRow = row;
}
void GridAdapter::Append(wxString wname) {
	grid->AppendRows(1);		//append one row
	grid->DeselectRow(0);		//deselect that row
	int rownum = grid->GetNumberRows() - 1;	//here is where to move it
	string name = wname.ToStdString();		//separate at space
	vector<string> names = Strfuncs::split(name, " ");
	grid->SetCellValue(rownum, 0, wxString(names[0]));	//first
	grid->SetCellValue(rownum, 1, wxString(names[1]));	//last
	//get lengths of first and last name
	//last 2 cells are numbers
	grid->SetCellValue(rownum, 2, wxString(std::to_string(names[0].size())));
	grid->SetCellValue(rownum, 3, wxString(std::to_string(names[1].size())));
}

void GridAdapter::Delete() {
	if (curRow >= 0) {
		grid->DeselectRow(curRow); //unselect row before deletion
		grid->DeleteRows(curRow, 1);
	}
}
wxString GridAdapter::GetString(int index) {
	wxString frname = grid->GetCellValue(index, 0);
	wxString lname = grid->GetCellValue(index, 1);
	return frname + " " + lname;
}

void GridAdapter::Refresh() {
	grid->Refresh();
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}