
#include "SwmHeaders.h"
#include "Event.h"
#include "TimedFinalEvent.h"
#include "CircleSeeding.h"
#include "PrelimEvent.h"

    //creates a preliminary event which is circle seeded
    PrelimEvent::PrelimEvent(string filename, int lanes) :Event(filename, lanes) {}

    Seeding* PrelimEvent::getSeeding() {
        return new CircleSeeding(swimmers, numLanes);
    }
