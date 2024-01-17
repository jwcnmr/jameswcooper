<<<<<<< HEAD
// SwimSeed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

//------------------------------------
class Swimmer {
private:
    string frname;
    string lname;
    int age;
    string club;
    string seedtime;    //time with colon in string form
    float time = 0.0;   //time as float for sorting
    int _lane = 0;
    int _heat = 0;
public:   

    string removeColon();   //remove colon in seed time to make float
    Swimmer(string dataline);
    Swimmer();
    string getName();   //Swimmer name
    string getClub();   //Swimmer club
    int getAge();       //swimmer age
    float getTime();    //get the floating value of seed time
    string getSeed();   //get the seed time string

    int heat();         //get the heat number
    void heat(int h);   //set the heat number
    int lane();         //get the lane number
    void lane(int ln);  //set the lane number
};
//------------------
class Seeding {
protected:
    vector<Swimmer*> swimmers;
public:
    virtual vector <Swimmer*> getSwimmers() {
        return swimmers;

    }
};
//------------------------------------
class StraightSeeding : public Seeding {
protected:
    //vector<Swimmer*> swimmers;
    int numLanes{ 0 };
    int count{ 0 };
    int numHeats{ 0 };
    vector<int> lanes;
public:
    StraightSeeding(vector <Swimmer*> sw, int nlanes);
    StraightSeeding();
    vector<int> calcLaneOrder();
    Swimmer** sortUpwards();
    void seed();
    Seeding* getSeeding();

};
//---------------
class CircleSeeding :public StraightSeeding {
private:
    int circle = 0;
public:
    CircleSeeding(vector <Swimmer*>  sw, int nlanes) ;
    void seed();
};


//------------------
class Event {
protected:
    int numLanes;
    vector <Swimmer*> swimmers;
public:
    Event(string filename, int lanes) {
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
    virtual Seeding* getSeeding()=0;
};

//------------------
class TimedFinalEvent: public Event {
    //creates an event that will be straight seeded
public:
    TimedFinalEvent(string filename, int lanes) : Event(filename, lanes) {

    }
            
    Seeding* getSeeding() {
        return new StraightSeeding(swimmers, numLanes);
    }
};
//-----------------------
class PrelimEvent :public Event {
public:
    //creates a preliminary event which is circle seeded
    PrelimEvent(string filename, int lanes) :Event(filename, lanes) {}

    Seeding* getSeeding() {
        return new CircleSeeding(swimmers, numLanes);
    }
};

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

//-------------------------
//-----//Circle seeding distributes the fastest swimmers into the top 3 heats

    CircleSeeding::CircleSeeding(vector <Swimmer*>  sw, int numLanes):StraightSeeding(sw, numLanes)  {
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

//------------------------------
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
                    Swimmer* swtemp = swmrs[i];
                    swmrs[i] = swmrs[j];
                    swmrs[j] = swtemp;
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

//-----------------------------------
    string Swimmer::removeColon() {
        size_t index = seedtime.find(":");
        if (index > 0) {
            string left = seedtime.substr(0, index);
            string right = seedtime.substr(index + 1, size(seedtime) - index - 1);
            return left + right;
        }
        else
            return seedtime;
    }

    Swimmer::Swimmer(string dataline) {
        stringstream ss(dataline);
        string temp;
        ss >> temp; //discard seed number column
        ss >> frname;
        ss >> lname;

        ss >> temp;
        age = stoi(temp);
        ss >> club;
        ss >> seedtime;
        time = stof(removeColon());

    }
    Swimmer::Swimmer() {
        frname = "";
        lname = "";
        age = 10;
        club = "";
        seedtime = "100:00";
        time = 100;
    }
    string Swimmer::getName() {
        return frname + " " + lname;
    }
    string Swimmer::getClub() {
        return club;
    }
    int Swimmer::getAge() {
        return age;

    }
    float Swimmer::getTime() {
        return time;
    }
    string Swimmer::getSeed() {
        return seedtime;
    }
    int Swimmer::heat() {
        return _heat;
    }
    void Swimmer::heat(int h) {
        _heat = h;
    }
    int Swimmer::lane() {
        return _lane;
    }
    void Swimmer::lane(int ln) {
        _lane = ln;
    }






=======
// SwimSeed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

//------------------------------------
class Swimmer {
private:
    string frname;
    string lname;
    int age;
    string club;
    string seedtime;    //time with colon in string form
    float time = 0.0;   //time as float for sorting
    int _lane = 0;
    int _heat = 0;
public:   

    string removeColon();   //remove colon in seed time to make float
    Swimmer(string dataline);
    Swimmer();
    string getName();   //Swimmer name
    string getClub();   //Swimmer club
    int getAge();       //swimmer age
    float getTime();    //get the floating value of seed time
    string getSeed();   //get the seed time string

    int heat();         //get the heat number
    void heat(int h);   //set the heat number
    int lane();         //get the lane number
    void lane(int ln);  //set the lane number
};
//------------------
class Seeding {
protected:
    vector<Swimmer*> swimmers;
public:
    virtual vector <Swimmer*> getSwimmers() {
        return swimmers;

    }
};
//------------------------------------
class StraightSeeding : public Seeding {
protected:
    //vector<Swimmer*> swimmers;
    int numLanes{ 0 };
    int count{ 0 };
    int numHeats{ 0 };
    vector<int> lanes;
public:
    StraightSeeding(vector <Swimmer*> sw, int nlanes);
    StraightSeeding();
    vector<int> calcLaneOrder();
    Swimmer** sortUpwards();
    void seed();
    Seeding* getSeeding();

};
//---------------
class CircleSeeding :public StraightSeeding {
private:
    int circle = 0;
public:
    CircleSeeding(vector <Swimmer*>  sw, int nlanes) ;
    void seed();
};


//------------------
class Event {
protected:
    int numLanes;
    vector <Swimmer*> swimmers;
public:
    Event(string filename, int lanes) {
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
    virtual Seeding* getSeeding()=0;
};

//------------------
class TimedFinalEvent: public Event {
    //creates an event that will be straight seeded
public:
    TimedFinalEvent(string filename, int lanes) : Event(filename, lanes) {

    }
            
    Seeding* getSeeding() {
        return new StraightSeeding(swimmers, numLanes);
    }
};
//-----------------------
class PrelimEvent :public Event {
public:
    //creates a preliminary event which is circle seeded
    PrelimEvent(string filename, int lanes) :Event(filename, lanes) {}

    Seeding* getSeeding() {
        return new CircleSeeding(swimmers, numLanes);
    }
};

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

//-------------------------
//-----//Circle seeding distributes the fastest swimmers into the top 3 heats

    CircleSeeding::CircleSeeding(vector <Swimmer*>  sw, int numLanes):StraightSeeding(sw, numLanes)  {
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

//------------------------------
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
                    Swimmer* swtemp = swmrs[i];
                    swmrs[i] = swmrs[j];
                    swmrs[j] = swtemp;
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

//-----------------------------------
    string Swimmer::removeColon() {
        size_t index = seedtime.find(":");
        if (index > 0) {
            string left = seedtime.substr(0, index);
            string right = seedtime.substr(index + 1, size(seedtime) - index - 1);
            return left + right;
        }
        else
            return seedtime;
    }

    Swimmer::Swimmer(string dataline) {
        stringstream ss(dataline);
        string temp;
        ss >> temp; //discard seed number column
        ss >> frname;
        ss >> lname;

        ss >> temp;
        age = stoi(temp);
        ss >> club;
        ss >> seedtime;
        time = stof(removeColon());

    }
    Swimmer::Swimmer() {
        frname = "";
        lname = "";
        age = 10;
        club = "";
        seedtime = "100:00";
        time = 100;
    }
    string Swimmer::getName() {
        return frname + " " + lname;
    }
    string Swimmer::getClub() {
        return club;
    }
    int Swimmer::getAge() {
        return age;

    }
    float Swimmer::getTime() {
        return time;
    }
    string Swimmer::getSeed() {
        return seedtime;
    }
    int Swimmer::heat() {
        return _heat;
    }
    void Swimmer::heat(int h) {
        _heat = h;
    }
    int Swimmer::lane() {
        return _lane;
    }
    void Swimmer::lane(int ln) {
        _lane = ln;
    }






>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
