<<<<<<< HEAD

#pragma once
#include "SwmHeaders.h"
#include "Seeding.h"
#include "Swimmer.h"
class StraightSeeding : public Seeding {
protected:
    //vector<Swimmer*> swimmers;
    int numLanes{ 0 };
    int count{ 0 };
    int numHeats{ 0 };
    vector<int> lanes;
public:
    StraightSeeding(vector <Swimmer*> sw, int nlanes);
    StraightSeeding();
    vector<int> calcLaneOrder();
    Swimmer** sortUpwards();
    void seed();
    Seeding* getSeeding();

};
=======

#pragma once
#include "SwmHeaders.h"
#include "Seeding.h"
#include "Swimmer.h"
class StraightSeeding : public Seeding {
protected:
    //vector<Swimmer*> swimmers;
    int numLanes{ 0 };
    int count{ 0 };
    int numHeats{ 0 };
    vector<int> lanes;
public:
    StraightSeeding(vector <Swimmer*> sw, int nlanes);
    StraightSeeding();
    vector<int> calcLaneOrder();
    Swimmer** sortUpwards();
    void seed();
    Seeding* getSeeding();

};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
