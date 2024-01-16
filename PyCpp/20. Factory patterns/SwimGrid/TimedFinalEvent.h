#pragma once
#include "SwmHeaders.h"
#include "Event.h"
#include "StraightSeeding.h"
class TimedFinalEvent : public Event {
    //creates an event that will be straight seeded
public:
    TimedFinalEvent(string filename, int lanes);

    Seeding* getSeeding();
};