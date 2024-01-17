<<<<<<< HEAD
//
// Created by James on 8/3/2022.
//

#ifndef EMPLOYEEHEADERS_EMPLOYEES_H
#define EMPLOYEEHEADERS_EMPLOYEES_H
#include "Employee.h"
#include <vector>
using namespace std;

class Employees {
private:
    vector <Employee *> employees;
public:
    void addEmployee(Employee* emp);
    int getCount();
    Employee* get(int i);
};

#endif //EMPLOYEEHEADERS_EMPLOYEES_H
=======
//
// Created by James on 8/3/2022.
//

#ifndef EMPLOYEEHEADERS_EMPLOYEES_H
#define EMPLOYEEHEADERS_EMPLOYEES_H
#include "Employee.h"
#include <vector>
using namespace std;

class Employees {
private:
    vector <Employee *> employees;
public:
    void addEmployee(Employee* emp);
    int getCount();
    Employee* get(int i);
};

#endif //EMPLOYEEHEADERS_EMPLOYEES_H
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
