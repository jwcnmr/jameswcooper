<<<<<<< HEAD
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
=======
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
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
