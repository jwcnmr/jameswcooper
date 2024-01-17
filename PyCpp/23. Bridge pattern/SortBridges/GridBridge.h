<<<<<<< HEAD
#pragma once
#include "Bridger.h"
#include "VisList.h"
#include "Products.h"
//General bridge between data and any VisList class
class GridBridge :public Bridger {
private:
	VisList* visList;
public:
	GridBridge(VisList* vl);
	void addData(Products* prod);
};

=======
#pragma once
#include "Bridger.h"
#include "VisList.h"
#include "Products.h"
//General bridge between data and any VisList class
class GridBridge :public Bridger {
private:
	VisList* visList;
public:
	GridBridge(VisList* vl);
	void addData(Products* prod);
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
