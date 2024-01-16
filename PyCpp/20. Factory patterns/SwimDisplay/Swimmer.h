#pragma once
#include "SwmHeaders.h"
class Swimmer {
private:
    string frname;      //first name
    string lname;       //last name
    int age;            //age
    string club;        //club symbol
    string seedtime;    //time with colon in string form
    float time = 0.0;   //time as float for sorting
    int _lane = 0;      //private lane value
    int _heat = 0;      //prinvate heat value

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

