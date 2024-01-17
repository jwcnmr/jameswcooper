<<<<<<< HEAD
#pragma once
#include "SwmHeaders.h"
#include "Event.h"
#include "StraightSeeding.h"
class TimedFinalEvent : public Event {
    //creates an event that will be straight seeded
public:
    TimedFinalEvent(string filename, int lanes);

    Seeding* getSeeding();
=======
#pragma once
#include "SwmHeaders.h"
#include "Event.h"
#include "StraightSeeding.h"
class TimedFinalEvent : public Event {
    //creates an event that will be straight seeded
public:
    TimedFinalEvent(string filename, int lanes);

    Seeding* getSeeding();
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
};