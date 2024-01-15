#pragma once
#include "SwmHeaders.h"
#include "Swimmer.h"
class Seeding {
protected:
    vector<Swimmer*> swimmers;
public:
    virtual void seed() = 0;
    vector <Swimmer*> getSwimmers();
};
