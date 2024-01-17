<<<<<<< HEAD
//
// Created by James on 8/3/2022.
//
#include "Employees.h"
#include "Employee.h"
//---Employees methods---
void Employees::addEmployee(Employee* emp) {
    employees.push_back(emp);
}
//get the size of the vector
int Employees::getCount() {
    return employees.size();
}
//get the pointer to the i-th Employee
Employee* Employees::get(int i) {
    return employees[i];
}

=======
//
// Created by James on 8/3/2022.
//
#include "Employees.h"
#include "Employee.h"
//---Employees methods---
void Employees::addEmployee(Employee* emp) {
    employees.push_back(emp);
}
//get the size of the vector
int Employees::getCount() {
    return employees.size();
}
//get the pointer to the i-th Employee
Employee* Employees::get(int i) {
    return employees[i];
}

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
