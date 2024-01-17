<<<<<<< HEAD
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

=======
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

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
};