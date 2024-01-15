#pragma once
#include "VisList.h"
#include "Products.h"
#include "baseincludes.h"

//A VisList view of a Grid

class GrdVisList :public VisList, public wxGrid
{
public:
	GrdVisList(wxPanel* p, wxSize sz);
	void addLines(Products* prods);
};

