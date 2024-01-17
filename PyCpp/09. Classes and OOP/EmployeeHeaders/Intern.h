<<<<<<< HEAD
//
// Created by James on 8/3/2022.
//

#ifndef EMPLOYEEHEADERS_INTERN1_H
#define EMPLOYEEHEADERS_INTERN1_H
#include "Employee.h"

class Intern : public Employee {
private:
    //cap the salary at 500 no matter what was entered
    void capSalary();

public:
    Intern(int id, string frnm, string lnm, double sal);
};
#endif //EMPLOYEEHEADERS_INTERN1_H
=======
//
// Created by James on 8/3/2022.
//

#ifndef EMPLOYEEHEADERS_INTERN1_H
#define EMPLOYEEHEADERS_INTERN1_H
#include "Employee.h"

class Intern : public Employee {
private:
    //cap the salary at 500 no matter what was entered
    void capSalary();

public:
    Intern(int id, string frnm, string lnm, double sal);
};
#endif //EMPLOYEEHEADERS_INTERN1_H
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
