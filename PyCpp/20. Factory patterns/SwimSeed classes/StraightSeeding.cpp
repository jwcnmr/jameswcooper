#include "SwmHeaders.h"
#include "Swimmer.h"
#include "StraightSeeding.h"
#include "CircleSeeding.h"
using std::swap;

StraightSeeding::StraightSeeding(vector <Swimmer*> sw, int nlanes) :Seeding() {
    numLanes = nlanes;
    swimmers = sw;
    count = sw.size();
    calcLaneOrder();
    seed();

}
StraightSeeding::StraightSeeding() {
    numLanes = 6;
    count = 0;
}
//compute the lane order from the middle outwards
vector<int> StraightSeeding::calcLaneOrder() {
    int mid = numLanes / 2;
    if (numLanes % 2 != 0) {
        mid = mid + 1;
    }
    //start in middle lane
    int incr = 1;
    int ln = mid;

    for (int i = 0; i < numLanes; i++) {
        lanes.push_back(ln);
        ln = mid + incr;
        incr = -incr;
        if (incr > 0) {
            incr++;
        }
    }
    return lanes;
}
//-----------------------
//sort the array of swimmers in ascending time order
Swimmer** StraightSeeding::sortUpwards() {
    Swimmer** swmrs = new Swimmer * [swimmers.size()];
    int i = 0;
    for (Swimmer* swmr : swimmers) {
        swmrs[i++] = swmr;  //copy to array for sorting
    }

    for (int i = 0; i < swimmers.size(); i++) {
        for (int j = i; j < swimmers.size(); j++) {
            if (swmrs[i]->getTime() > swmrs[j]->getTime()) {
                swap(swmrs[i], swmrs[j]);
            }
        }
    }
    return swmrs;
}

//carry out straight seeding fastest kids in last heat
void StraightSeeding::seed() {
    //loads the swmrs array and sorts it
    Swimmer** asw = sortUpwards();  // number in last heat
    int lastHeat = count % numLanes;
    if (lastHeat < 3)
        lastHeat = 3; // last heat must have 3 or more

    int lastLanes = count - lastHeat;
    numHeats = count / numLanes;

    if (lastLanes > 0) {
        numHeats += 1; //compute total number of heats
    }
    int heats = numHeats;

    // place heat and lane in each swimmer's object
    int j = 0;
    // load from fastest to slowest
    // so we start with last heat and work downwards
    for (int i = 0; i < lastLanes; i++) {
        Swimmer* sw = asw[i];  // get each swimmer
        sw->lane(lanes[j]); // copy in lane
        j += 1;
        sw->heat(heats); // and heat
        if (j >= numLanes) {
            heats -= 1; // next heat
            j = 0;
        }
    }
    // Add in last partial heat
    if (j < numLanes) {
        heats -= 1;
        j = 0;
    }
    for (int i = lastLanes - 1; i < count; i++) {
        Swimmer* sw = asw[i];
        sw->lane(lanes[j]);
        j += 1;
        sw->heat(heats);
    }
    // copy from array back into list
    swimmers.clear();
    for (int i = 0; i < count; i++)
        swimmers.push_back(asw[i]);
}

Seeding* StraightSeeding::getSeeding() {
    return new CircleSeeding(swimmers, numLanes);
}

