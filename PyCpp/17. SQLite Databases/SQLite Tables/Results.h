#pragma once
#include "globaldefs.h"

#include <iostream>

//header for Results class

using std::cout;
using std::endl;

class Results {
protected:
    vector<dbMap> rows;
    size_t cursor = 0;
public:
    Results(vector<dbMap> crows);
    dbMap getRow();
    string getVal(string name);
    size_t getSize();
    string getCol(int index);
    void setCursor(size_t cval);
    vector<dbMap> getRows();
};

