#include "LbVisList.h"
#include "Product.h"
#include "Products.h"
#include "baseincludes.h"
//a VisList for a ListBox
//derived from wxListBox 
LbVisList::LbVisList(wxPanel* p, wxSize sz): wxListBox(p, wxID_ANY, wxDefaultPosition, sz, 0,
	NULL, 0L, wxDefaultValidator) {
}
//add lines from the Products vector
void LbVisList::addLines(Products* prods) {
	vector<Product*> products = prods->getProducts();
	for (Product* p : products) {
		Append(wxString(p->getName()));
	}
}