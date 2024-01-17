<<<<<<< HEAD
//
// Created by James on 8/3/2022.
//
#include "Employee.h"
//---Employee methods---
Employee::Employee(int id, string frnm, string lnm, double sal, double benefits ) {
    frname = frnm;
    lname = lnm;
    idNum = id;
    salary = sal;
    this->benefits = benefits;
}
double Employee::getSalary() {return salary; }
string Employee::getName() {return frname + " " + lname; }
int Employee::getId() {return idNum; }
double Employee::getBenefit() {return benefits;}
=======
//
// Created by James on 8/3/2022.
//
#include "Employee.h"
//---Employee methods---
Employee::Employee(int id, string frnm, string lnm, double sal, double benefits ) {
    frname = frnm;
    lname = lnm;
    idNum = id;
    salary = sal;
    this->benefits = benefits;
}
double Employee::getSalary() {return salary; }
string Employee::getName() {return frname + " " + lname; }
int Employee::getId() {return idNum; }
double Employee::getBenefit() {return benefits;}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
