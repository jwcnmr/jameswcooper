<<<<<<< HEAD
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
