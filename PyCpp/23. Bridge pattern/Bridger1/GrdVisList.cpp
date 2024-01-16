#include "baseincludes.h"
#include "Product.h"
#include "Products.h"
#include "GrdVisList.h"

//This is a Grid display which also has the VisList interface "addLines"
GrdVisList::GrdVisList(wxPanel* p, wxSize sz) : 
	wxGrid( p, wxID_ANY, wxDefaultPosition, sz) {
	CreateGrid(0, 2);
	SetColSize(0, 140);	//set column sizes
	SetColSize(1, 80);
	
	SetRowLabelSize(0);		//hide row label
	SetColLabelSize(0);		//hide column labels
}

void GrdVisList::addLines(Products* prods) {
	vector<Product*> products = prods->getProducts();
	for (Product* p : products) {
		AppendRows(1);						//append one row
		int rownum = GetNumberRows() - 1;	//here is where to move it
		SetCellAlignment(rownum, 1, wxALIGN_RIGHT, wxALIGN_CENTER);
		//insert the two values in columns 0 and 1
		SetCellValue(rownum, 0, wxString(p->getName()));	//first
		SetCellValue(rownum, 1, wxString(p->getCount()));	//last
	}
}

