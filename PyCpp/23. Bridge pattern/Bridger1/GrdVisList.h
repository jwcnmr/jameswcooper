<<<<<<< HEAD
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

=======
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

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
