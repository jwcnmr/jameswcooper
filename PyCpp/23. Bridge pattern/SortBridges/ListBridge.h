#pragma once
#include "Bridger.h"
#include "VisList.h"
#include "Products.h"
//General bridge between data and any VisList class
class ListBridge :public Bridger {
private:
	VisList* visList;
public:
	ListBridge(VisList* vl);
	void addData(Products* prod);
};