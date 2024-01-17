
#pragma once

#include <string>
#include <vector>
#include <map>
#include <mysqlx/xdevapi.h>

using std::string;
using std::vector;
using std::tuple;
using std::map;

//convenient abbreviation for the map
//typedef  map<string, string> dbMap;
typedef  map<string, mysqlx::Value> dbMap;
