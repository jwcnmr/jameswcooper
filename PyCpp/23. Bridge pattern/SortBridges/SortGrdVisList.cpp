#include "baseincludes.h"
#include "Product.h"
#include "Products.h"
#include "SortGrdVisList.h"
using std::swap;

//This is a Grid display which also has the VisList interface "addLines"
//This version sorts the data by increasing count
GrdVisList::GrdVisList(wxPanel* p, wxSize sz) : 
	wxGrid( p, wxID_ANY, wxDefaultPosition, sz) {
	CreateGrid(0, 2);
	SetColSize(0, 140);	//set column sizes
	SetColSize(1, 80);
	
	SetRowLabelSize(0);		//hide row label
	SetColLabelSize(0);		//hide column labels
}
//convert comma space number into integer
int GrdVisList::getInteger(string s) {
	string digits = "";
	
	for (int i = 0; i < s.length(); i++) {	
		char x = s[i];
		if (isdigit(s[i]) ){
			digits += s[i];
		}	
	}
	return atoi(digits.c_str());
}
void GrdVisList::addLines(Products* prods) {
	vector<Product*> products = prods->getProducts();
	//sort the products by name
	vector <Product*> sortProd;
	//copy list
	for (Product* p : products) {
		sortProd.push_back(p);
	}
	//sort list
	for (int i = 0; i < sortProd.size(); i++) {
		for (int j = i; j < sortProd.size(); j++) {
			if (getInteger(sortProd[i]->getCount()) > getInteger(sortProd[j]->getCount())) {
				swap(sortProd[i], sortProd[j]);
			}
		}
	}

	for (Product* p : sortProd) {
		AppendRows(1);						//append one row
		int rownum = GetNumberRows() - 1;	//here is where to move it
		SetCellAlignment(rownum, 1, wxALIGN_RIGHT, wxALIGN_CENTER);
		//insert the two values in columns 0 and 1
		SetCellValue(rownum, 0, wxString(p->getName()));	//first
		SetCellValue(rownum, 1, wxString(p->getCount()));	//last
	}
}

