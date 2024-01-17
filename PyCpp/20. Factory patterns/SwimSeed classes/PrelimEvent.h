<<<<<<< HEAD
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

=======
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

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
