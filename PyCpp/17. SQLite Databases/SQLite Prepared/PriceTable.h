<<<<<<< HEAD
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

=======
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

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
};