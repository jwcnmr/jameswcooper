#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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

class Employees {
private:
    vector <Employee *> employees;
public:
    void addEmployee(Employee* emp);
    int getCount();
    Employee* get(int i);
};

class TempEmployee : public Employee {
public:
    TempEmployee(int id, string frnm, string lnm, double sal);
};

class Intern : public Employee {
private:
    //cap the salary at 500 no matter what was entered
    void capSalary();

public:
    Intern(int id, string frnm, string lnm, double sal);
};
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

//---Temp Employee methods--
TempEmployee::TempEmployee(int id, string frnm, string lnm, double sal) :
Employee(id, frnm, lnm, sal) {
    benefits = 0;       //temp employees do not get benefits
}

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

