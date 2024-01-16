#pragma once
#include "Products.h"
#include "VisList.h"
#include "baseincludes.h"

//a listbox that holds a list of products, derived from VisList and ListBox
class LbVisList:public VisList,public wxListBox
{
public:
	LbVisList(wxPanel* p, wxSize sz);
	void addLines(Products* prods);
};

