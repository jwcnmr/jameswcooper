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
