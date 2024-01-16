#pragma once
#include "SwmHeaders.h"
#include "Swimmer.h"
#include "Seeding.h"
class Event {
protected:
    int numLanes;
    vector <Swimmer*> swimmers;
public:
    Event(string filename, int lanes); 
    Event();
    virtual Seeding* getSeeding() = 0;
};
