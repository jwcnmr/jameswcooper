#include "SwmHeaders.h"
#include "Event.h"
#include "Swimmer.h"
#include "Seeding.h"

Event::Event() {

    }
Event::Event(string filename, int lanes) {
    numLanes = lanes;
    ifstream txtFile(filename);    //open the file

    if (txtFile.is_open()) {            //if it is open
        string line;
        while (getline(txtFile, line)) { //line at a time
            Swimmer* swmr = new Swimmer(line);
            swimmers.push_back(swmr);
        }
        txtFile.close();
    }
}
   

