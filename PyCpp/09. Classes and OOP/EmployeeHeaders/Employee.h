//
// Created by James on 8/3/2022.
//

#ifndef EMPLOYEEHEADERS_EMPLOYEE_H
#define EMPLOYEEHEADERS_EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
    int idNum;
    string frname, lname;
    double salary;
    double benefits ;
public:
    Employee(int id, string frnm, string lnm, double sal, double benefits=1000);
    double getSalary();
    string getName();
    int getId();
    double getBenefit();
};

#endif //EMPLOYEEHEADERS_EMPLOYEE_H
