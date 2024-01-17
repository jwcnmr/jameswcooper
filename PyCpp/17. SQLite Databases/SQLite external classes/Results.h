<<<<<<< HEAD
#pragma once
#include "globaldefs.h"

#include <iostream>

//header for Results class

using std::cout;
using std::endl;

class Results {
private:
    vector<dbMap> rows;
    size_t cursor = 0;
public:
    Results(vector<map<string, string>> crows);
    dbMap getRow();
    string getVal(string name);
    size_t getSize();
    string getCol(int index);
    void setCursor(size_t cval);
};

=======
#pragma once
#include "globaldefs.h"

#include <iostream>

//header for Results class

using std::cout;
using std::endl;

class Results {
private:
    vector<dbMap> rows;
    size_t cursor = 0;
public:
    Results(vector<map<string, string>> crows);
    dbMap getRow();
    string getVal(string name);
    size_t getSize();
    string getCol(int index);
    void setCursor(size_t cval);
};

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
