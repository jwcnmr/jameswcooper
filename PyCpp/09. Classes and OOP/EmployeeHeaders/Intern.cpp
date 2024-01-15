//
// Created by James on 8/3/2022.
//
//
// Created by James on 8/3/2022.
//

#include "Intern.h"
#include <string>
using namespace std;

//----Intern methods-----
//cap the salary at 500 no matter what was entered
void Intern::capSalary() {
    if (salary > 500) {
        salary = 500;
    }
}

Intern::Intern(int id, string frnm, string lnm, double sal) :
Employee(id, frnm, lnm, sal) {
    benefits = 0;       // no benefits either
    capSalary();        //cap the salary
}
