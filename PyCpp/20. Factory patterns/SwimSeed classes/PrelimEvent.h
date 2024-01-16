#pragma once
#include "Event.h"
#include "Seeding.h"
#include "CircleSeeding.h"
//-----------------------
class PrelimEvent :public Event {
public:
    //creates a preliminary event which is circle seeded
    PrelimEvent(string filename, int lanes); 

    Seeding* getSeeding();
};

