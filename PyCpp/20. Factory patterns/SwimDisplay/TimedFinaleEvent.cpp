<<<<<<< HEAD
#include "SwmHeaders.h"
#include "Event.h"
#include "Seeding.h"
#include"TimedFinalEvent.h"


TimedFinalEvent::TimedFinalEvent(string filename, int lanes) 
    : Event(filename, lanes){
    }

    Seeding* TimedFinalEvent::getSeeding() {
        return new StraightSeeding(swimmers, numLanes);
    }
=======
#include "SwmHeaders.h"
#include "Event.h"
#include "Seeding.h"
#include"TimedFinalEvent.h"


TimedFinalEvent::TimedFinalEvent(string filename, int lanes) 
    : Event(filename, lanes){
    }

    Seeding* TimedFinalEvent::getSeeding() {
        return new StraightSeeding(swimmers, numLanes);
    }
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
