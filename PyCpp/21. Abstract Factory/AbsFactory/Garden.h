#pragma once

using std::string;
#include <string>

class Plant {
private:
    string plantName;
public:

    Plant(string pname);
    string name();
};

class Garden {
protected:
    Plant* sunnyPlant;
    Plant* shadePlant;
    Plant* borderPlant;
    string name;

public:
    Garden(const string gname);
    string getName();

    Plant* shade();
    Plant* sunny();
    Plant* border();
};

class VeggieGarden :public Garden {
public:
    VeggieGarden();

};
class AnnualGarden :public Garden {
public:
    AnnualGarden();

};
class PerennialGarden :public Garden {
public:
    PerennialGarden();
};
