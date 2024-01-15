#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    int idNum;
    string frname, lname;
    double salary;
    double benefits ;
public:
    Employee(int id, string frnm, string lnm, double sal, double benefits = 1000) {
        frname = frnm;
        lname = lnm;
        idNum = id;
        salary = sal;
        this->benefits = benefits;
    }
    double getSalary() {return salary; }
    string getName() {return frname + " " + lname; }
    int getId() {return idNum; }
};

class Employees {
private:
    vector <unique_ptr<Employee>> employees;
public:
    //add a pointer to an Employee class to the map
    void addEmployee(unique_ptr<Employee> emp) {
        employees.push_back(std::move(emp));
    }

    int getCount() {
        return employees.size();
    }
    //get the pointer to the i-th Employee
    //and return the actual Employee instance
    Employee get(int i) {
        Employee emp = *employees[i];
        return emp;
    }
};

class TempEmployee : public Employee {
public:
    TempEmployee(int id, string frnm, string lnm, double sal) :
    Employee(id, frnm, lnm, sal) {
        benefits = 0;
    }
};

class Intern : public Employee {
private:
    void capSalary() {
        if (salary > 500) {
            salary = 500;
        }
    }

public:
    Intern(int id, string frnm, string lnm, double sal) :
    Employee(id, frnm, lnm, sal) {
        benefits = 0;
        capSalary();
    }
};

int main() {
    Employees employees;
    int id = 1;
    //Employee* emp1 = new Employee(id++, "Susan", "Sugar", 5000);
    unique_ptr <Employee> emp1 = make_unique <Employee>(id++, "Susan", "Sugar", 5000);
    employees.addEmployee(std::move(emp1));
    employees.addEmployee(make_unique<Employee>(id++, "Sarah", "Smythe", 2000));
    employees.addEmployee(make_unique<TempEmployee>(id++, "Billy", "Bob", 1000));
    employees.addEmployee(make_unique<Intern>(id++, "Arnold", "Stang", 800));


    for (int i=0; i< employees.getCount(); i++){
        Employee emp = employees.get(i);
        cout << emp.getId()<<"  "<< emp.getName() << "  " << emp.getSalary() << endl;
    }
    return 0;
}
