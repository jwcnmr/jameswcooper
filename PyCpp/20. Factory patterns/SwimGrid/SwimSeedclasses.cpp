// SwimSeed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <format>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stringstream;
using std::ifstream;
using std::vector;
using std::format;
*/
#include "SwmHeaders.h"
#include "Swimmer.h"
#include "Seeding.h"
#include "StraightSeeding.h"
#include "CircleSeeding.h"
#include "Event.h"
#include "TimedFinalEvent.h"
#include "PrelimEvent.h"
//------------------------------------

//call the current seeding and print out the result
void doSeeding(Event* event) {
    Seeding* seeding = event->getSeeding();    //factory here
    vector <Swimmer*> swmrs = seeding->getSwimmers();    //do one sort of seeding or the other

    //print swimmer list in seeded order
    for (Swimmer* sw : swmrs) {
        //print(f'{sw.heat:3} {sw.lane:3} {sw.getName():20} {sw.age:3} {sw.seedtime:9}');
        cout << format("{:3} {:2} ", sw->heat(), sw->lane());
        cout << format("{:20} {:3} {:4} {:.2f} \n", sw->getName(), sw->getAge(),
            sw->getClub(), sw->getTime());
    }

}
//-----------------------
int main()     {
    int dist =0;
    bool quit = false;
    while (!quit) {
        Event* event{ NULL };
        cout << "enter '1' or '5' (0 to quit): ";
        cin >> dist;    //read in integer
        if (dist == 5) {
            event = new TimedFinalEvent("500free.txt", 6);
            doSeeding(event);
        }
        else if (dist == 1) {
            event = new PrelimEvent("100free.txt", 6);
            doSeeding(event);
        }
        else if (dist == 0)
            quit = true;
        

    }
        
 }

