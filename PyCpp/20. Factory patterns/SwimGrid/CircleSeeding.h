<<<<<<< HEAD
#pragma once
#include "StraightSeeding.h"
class CircleSeeding :public StraightSeeding {
private:
    int circle = 0;
public:
    CircleSeeding(vector <Swimmer*>  sw, int nlanes);
    void seed();
=======
#pragma once
#include "StraightSeeding.h"
class CircleSeeding :public StraightSeeding {
private:
    int circle = 0;
public:
    CircleSeeding(vector <Swimmer*>  sw, int nlanes);
    void seed();
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
};