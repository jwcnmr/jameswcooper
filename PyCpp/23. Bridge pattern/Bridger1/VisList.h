#pragma once
#include "Products.h"
//abstract class defining the one method in the VisList class
class VisList {
public:
	virtual void addLines(Products* prod)=0;
};

