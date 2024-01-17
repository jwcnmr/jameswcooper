<<<<<<< HEAD
#include "SortLbVisList.h"
#include "Product.h"
#include "Products.h"
#include "baseincludes.h"
using std::swap;

//a sorted VisList for a ListBox
//derived from wxListBox and sorted by name
LbVisList::LbVisList(wxPanel* p, wxSize sz): wxListBox(p, wxID_ANY, wxDefaultPosition, sz, 0,
	NULL, 0L, wxDefaultValidator) {
}
//add lines from the Products vector
void LbVisList::addLines(Products* prods) {
	vector<Product*> products = prods->getProducts();
	//sort the products by name
	vector <Product*> sortProd;
	//sort list by name
	//copy list
	for (Product* p : products) {
		sortProd.push_back(p);
	}
	//sort list by name
	for (int i = 0; i < sortProd.size(); i++) {
		for (int j = i; j < sortProd.size(); j++) {
			if (sortProd[i]->getName() > sortProd[j]->getName()) {
				swap(sortProd[i], sortProd[j]);
			}
		}
	}
	//now load the list with the sorted results
	for (Product* p : sortProd) {
		Append(wxString(p->getName()));
	}
=======
#include "SortLbVisList.h"
#include "Product.h"
#include "Products.h"
#include "baseincludes.h"
using std::swap;

//a sorted VisList for a ListBox
//derived from wxListBox and sorted by name
LbVisList::LbVisList(wxPanel* p, wxSize sz): wxListBox(p, wxID_ANY, wxDefaultPosition, sz, 0,
	NULL, 0L, wxDefaultValidator) {
}
//add lines from the Products vector
void LbVisList::addLines(Products* prods) {
	vector<Product*> products = prods->getProducts();
	//sort the products by name
	vector <Product*> sortProd;
	//sort list by name
	//copy list
	for (Product* p : products) {
		sortProd.push_back(p);
	}
	//sort list by name
	for (int i = 0; i < sortProd.size(); i++) {
		for (int j = i; j < sortProd.size(); j++) {
			if (sortProd[i]->getName() > sortProd[j]->getName()) {
				swap(sortProd[i], sortProd[j]);
			}
		}
	}
	//now load the list with the sorted results
	for (Product* p : sortProd) {
		Append(wxString(p->getName()));
	}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}