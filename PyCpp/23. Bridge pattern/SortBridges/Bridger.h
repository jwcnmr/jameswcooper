#pragma once
#include "Products.h"
//abstract Bridge class

class Bridger {
	//add data to the other side of the bridge
	virtual void addData(Products* prod) = 0;
};

