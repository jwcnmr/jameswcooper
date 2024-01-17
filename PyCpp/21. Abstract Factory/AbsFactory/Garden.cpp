<<<<<<< HEAD
#include <string>
#include "Garden.h"
using std::string;



    Plant::Plant(string pname) {
        plantName = pname;
    }
    string Plant::name() {
        return plantName;
    }

    Garden::Garden(const string gname) {
        name = gname;
    }
    string Garden::getName() {
        return name;
    }


    Plant* Garden::shade() {
        return shadePlant;
    }
    Plant* Garden::sunny() {
        return sunnyPlant;
    }
    Plant* Garden::border() {
        return borderPlant;
    }



    VeggieGarden::VeggieGarden() :Garden("Vegetable") {
        sunnyPlant = new Plant("Corn");
        borderPlant = new Plant("Peas");
        shadePlant = new Plant("Broccoli");
    }



    AnnualGarden::AnnualGarden() :Garden("Annnual") {
        sunnyPlant = new Plant("Marigold");
        borderPlant = new Plant("Alyssum");
        shadePlant = new Plant("Coleus");

    }



    PerennialGarden::PerennialGarden() :Garden("Perennial") {
        sunnyPlant = new Plant("Dicentrum");
        borderPlant = new Plant("Sedum");
        shadePlant = new Plant("Astilbe");
    }

=======
#include <string>
#include "Garden.h"
using std::string;



    Plant::Plant(string pname) {
        plantName = pname;
    }
    string Plant::name() {
        return plantName;
    }

    Garden::Garden(const string gname) {
        name = gname;
    }
    string Garden::getName() {
        return name;
    }


    Plant* Garden::shade() {
        return shadePlant;
    }
    Plant* Garden::sunny() {
        return sunnyPlant;
    }
    Plant* Garden::border() {
        return borderPlant;
    }



    VeggieGarden::VeggieGarden() :Garden("Vegetable") {
        sunnyPlant = new Plant("Corn");
        borderPlant = new Plant("Peas");
        shadePlant = new Plant("Broccoli");
    }



    AnnualGarden::AnnualGarden() :Garden("Annnual") {
        sunnyPlant = new Plant("Marigold");
        borderPlant = new Plant("Alyssum");
        shadePlant = new Plant("Coleus");

    }



    PerennialGarden::PerennialGarden() :Garden("Perennial") {
        sunnyPlant = new Plant("Dicentrum");
        borderPlant = new Plant("Sedum");
        shadePlant = new Plant("Astilbe");
    }

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
