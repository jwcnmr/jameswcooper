#pragma once
#include "Table.h"
#include "Query.h"
#include <string>
using std::to_string;

typedef  std::tuple<int, int, float> pricetuple;

class PriceTable :
    public Table {
public:
    PriceTable(sqltDatabase sqldb);
    int addRow(pricetuple ptuple);

};