#pragma once
#include "msqTable.h"
#include "Query.h"
#include <string>
using std::to_string;

typedef  std::tuple<int, int, float> pricetuple;

class PriceTable :
    public msqTable {
public:
    PriceTable(msqDatabase* msqdb);
    int addRow(pricetuple ptuple);

};