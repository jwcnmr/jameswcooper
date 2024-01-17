<<<<<<< HEAD
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
   

=======
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
   

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
