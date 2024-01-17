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

