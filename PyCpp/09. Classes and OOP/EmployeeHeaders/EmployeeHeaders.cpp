#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Employees.h"
#include "TempEmployee.h"
#include "Intern.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

//----Main program starts here----
int main() {
    Employees employees;
    int id = 1;
    Employee* emp1 = new Employee(id++, "Susan", "Sugar", 5000);
    employees.addEmployee(emp1);
    employees.addEmployee(new Employee(id++, "Sarah", "Smythe", 2000));
    employees.addEmployee(new TempEmployee(id++, "Billy", "Bob", 1000));
    employees.addEmployee(new Intern(id++, "Arnold", "Stang", 800));

    // std::cout << emp1->getName() << std::endl;
    for (int i=0; i< employees.getCount(); i++){
        Employee *emp = employees.get(i);
        cout << emp->getId()<<"  "<< emp->getName() << "  " <<
        emp->getSalary() <<" "<<emp->getBenefit()<< endl;
    }
    return 0;
}







