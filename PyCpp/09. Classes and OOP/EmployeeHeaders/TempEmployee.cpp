//
// Created by James on 8/3/2022.
//
#include "Employee.h"
#include "TempEmployee.h"

#include <string>
using namespace std;

//---Temp Employee methods--
TempEmployee::TempEmployee(int id, string frnm, string lnm, double sal) :
Employee(id, frnm, lnm, sal) {
    benefits = 0;       //temp employees do not get benefits
}
