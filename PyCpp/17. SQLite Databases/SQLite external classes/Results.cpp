#include "globaldefs.h"
#include "Results.h"

//the Results class holds the vector of maps from the last query
//and provides various ways to access them

    //copy from the Query static vector
Results::Results(vector<map<string, string>> crows) {
    for (int i = 0; i < crows.size(); i++) {
        rows.push_back(crows[i]);
    }
}
//get one row as a map
dbMap Results::getRow() {
    return rows[cursor++];
}
//get the value of the named column in the current row
string Results::getVal(string name) {
    return rows[cursor][name];
}
//get the size of the result
size_t Results::getSize() {
    return rows.size();
}
void Results::setCursor(size_t cval) {
    cursor = cval;
}
//get the value of the map entry by index
string Results::getCol(int index) {
    if (cursor < rows.size()) {
        dbMap map = rows[cursor];
        auto it = map.begin();
        std::advance(it, index);
        return it->second;
    }
    else
        return "";
}

