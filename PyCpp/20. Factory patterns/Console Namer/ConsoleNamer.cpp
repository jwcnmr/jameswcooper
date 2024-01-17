<<<<<<< HEAD
// ConsoleNamer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//base namer class
class Namer {
protected:
	string frname{ NULL };  //first name
	string lname{ NULL };   //last name

public:
    string getFrname() {
        return frname;      //get the firat name
    }
    string getLname() {
        return lname;       //get the last name
    }
};

//splits apart names separated by a comma
class LastFirst :  public Namer {
public:
    LastFirst(string nameEntry) {
        int index = nameEntry.find(",");
        if (index > 0) {
            lname = nameEntry.substr(0, index);
            if (index+2 < size(nameEntry))  //prevents error if no 2nd name      
                frname = nameEntry.substr(index+2, size(nameEntry) - (index+2));
        }
    }
};

//splits apart two names separated by a space
class FirstFirst : public Namer {
public:
    FirstFirst(string nameEntry) {
        int index = nameEntry.find(" ");    //find the space
        if (index > 0) {                    //if we find one split there
            frname = nameEntry.substr(0, index);
            lname = nameEntry.substr(index+1, size(nameEntry) - index);
        }
    }
};

//The name factory returns a pointer to a  last-first namer 
// or a first-first namer
class NameFactory {
private:
    string nameString;
public:

    NameFactory(string nm) {
        nameString = nm;        //save the string 
    }
    //get the right child of the Namer class
    Namer* getNamer() {
        //if there is a comma
        int index = nameString.find(",");
        if (index > 0) {
            return new LastFirst(nameString);   //return a LastFirst instance
        }
        //otherwise, return a FirstLast instance
        else {
            return new FirstFirst(nameString);
        }
    }
};

//Program to take in names with spaces or commas 
//and determine which is last name and which is first
int main() {
    bool quit = false;  //quit if it becomes true
    char name[100];     //buffer where the line is read in
    while (!quit) {     //repeat until the word "quit" is entered
        cout << "Enter name: ";
        cin.getline(name, 100); //get the name chars from the keyboard
        string nm(name);        //convert to a string
        if (nm == "quit") {
            quit = true;        //if they enter "quit" set this flag
        }
        else {
            NameFactory nf(nm); //create a name factory
            Namer* nmr = nf.getNamer();     //get the right namer pointer
            //print out the first and last names
            
            cout << format("First: {} Last: {} \n", 
                nmr->getFrname(), nmr->getLname() );
            delete nmr;     //delete pointer to that class
        }
    }
}

=======
// ConsoleNamer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <format>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//base namer class
class Namer {
protected:
	string frname{ NULL };  //first name
	string lname{ NULL };   //last name

public:
    string getFrname() {
        return frname;      //get the firat name
    }
    string getLname() {
        return lname;       //get the last name
    }
};

//splits apart names separated by a comma
class LastFirst :  public Namer {
public:
    LastFirst(string nameEntry) {
        int index = nameEntry.find(",");
        if (index > 0) {
            lname = nameEntry.substr(0, index);
            if (index+2 < size(nameEntry))  //prevents error if no 2nd name      
                frname = nameEntry.substr(index+2, size(nameEntry) - (index+2));
        }
    }
};

//splits apart two names separated by a space
class FirstFirst : public Namer {
public:
    FirstFirst(string nameEntry) {
        int index = nameEntry.find(" ");    //find the space
        if (index > 0) {                    //if we find one split there
            frname = nameEntry.substr(0, index);
            lname = nameEntry.substr(index+1, size(nameEntry) - index);
        }
    }
};

//The name factory returns a pointer to a  last-first namer 
// or a first-first namer
class NameFactory {
private:
    string nameString;
public:

    NameFactory(string nm) {
        nameString = nm;        //save the string 
    }
    //get the right child of the Namer class
    Namer* getNamer() {
        //if there is a comma
        int index = nameString.find(",");
        if (index > 0) {
            return new LastFirst(nameString);   //return a LastFirst instance
        }
        //otherwise, return a FirstLast instance
        else {
            return new FirstFirst(nameString);
        }
    }
};

//Program to take in names with spaces or commas 
//and determine which is last name and which is first
int main() {
    bool quit = false;  //quit if it becomes true
    char name[100];     //buffer where the line is read in
    while (!quit) {     //repeat until the word "quit" is entered
        cout << "Enter name: ";
        cin.getline(name, 100); //get the name chars from the keyboard
        string nm(name);        //convert to a string
        if (nm == "quit") {
            quit = true;        //if they enter "quit" set this flag
        }
        else {
            NameFactory nf(nm); //create a name factory
            Namer* nmr = nf.getNamer();     //get the right namer pointer
            //print out the first and last names
            
            cout << format("First: {} Last: {} \n", 
                nmr->getFrname(), nmr->getLname() );
            delete nmr;     //delete pointer to that class
        }
    }
}

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
