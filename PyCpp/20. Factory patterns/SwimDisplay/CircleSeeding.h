#pragma once
#include "StraightSeeding.h"
class CircleSeeding :public StraightSeeding {
private:
    int circle = 0;
public:
    CircleSeeding(vector <Swimmer*>  sw, int nlanes);
    void seed();
};