
#include "SwmHeaders.h"
#include "CircleSeeding.h"
//Circle seeding distributes the fastest swimmers into the top 3 heats

CircleSeeding::CircleSeeding(vector <Swimmer*>  sw, int numLanes) :StraightSeeding(sw, numLanes) {
    StraightSeeding::seed(); //do straight seeding as default
    seed();                  //then redo the top heats
}
//carry out circle seeding-last 3 or 2 heats have the swimers from fastest to slowest
//through those last heats
void CircleSeeding::seed() {
    if (numHeats >= 2) {
        if (numHeats >= 3) {
            circle = 3;
        }
        else {
            circle = 2;
        }
    }

    int i = 0;
    for (int j = 0; j < numLanes; j++) {
        for (int k = 0; k < circle; k++) {
            swimmers[i]->lane(lanes[j]);
            swimmers[i]->heat(numHeats - k);
            i++;
        }
    }
}

=======
#include "SwmHeaders.h"
#include "CircleSeeding.h"
//Circle seeding distributes the fastest swimmers into the top 3 heats

CircleSeeding::CircleSeeding(vector <Swimmer*>  sw, int numLanes) :StraightSeeding(sw, numLanes) {
    StraightSeeding::seed(); //do straight seeding as default
    seed();                  //then redo the top heats
}
//carry out circle seeding-last 3 or 2 heats have the swimers from fastest to slowest
//through those last heats
void CircleSeeding::seed() {
    if (numHeats >= 2) {
        if (numHeats >= 3) {
            circle = 3;
        }
        else {
            circle = 2;
        }
    }

    int i = 0;
    for (int j = 0; j < numLanes; j++) {
        for (int k = 0; k < circle; k++) {
            swimmers[i]->lane(lanes[j]);
            swimmers[i]->heat(numHeats - k);
            i++;
        }
    }
}
