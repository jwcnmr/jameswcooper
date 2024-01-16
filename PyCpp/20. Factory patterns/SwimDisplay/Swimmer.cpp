#include "Swimmer.h"

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
    return _heat;           //get the heat number
}
void Swimmer::heat(int h) {
    _heat = h;              //store the heat number
}
int Swimmer::lane() {
    return _lane;           //get the lane number
}
void Swimmer::lane(int ln) {
    _lane = ln;             //store the lane number
}
