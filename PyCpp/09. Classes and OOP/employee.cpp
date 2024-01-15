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
    int getBenefit() {return benefits;}
};

class Employees {
private:
    //contains an array of pointers to Employee objects
    vector <Employee *> employees;
public:
    //add a pointer to an Employee class to the vector
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }
    //get the size of the vector
    int getCount() {
        return employees.size();
    }
    //get the pointer to the i-th Employee
    Employee* get(int i) {
        return employees[i];
    }
    //destructor releases memory
    ~Employees() {
        for (Employee* emp:employees) {
            delete emp;
        }
    }
};

class TempEmployee : public Employee {
public:
    TempEmployee(int id, string frnm, string lnm, double sal) :
            Employee(id, frnm, lnm, sal) {
        benefits = 0;       //temp employees do not get benefits
    }
};

class Intern : public Employee {
private:
    //cap the salary at 500 no matter what was entered
    void capSalary() {
        if (salary > 500) {
            salary = 500;
        }
    }

public:
    Intern(int id, string frnm, string lnm, double sal) :
            Employee(id, frnm, lnm, sal) {
        benefits = 0;       // no benefits either
        capSalary();        //cap the salary
    }
};

//illustrates different variable naming convention
class Employee2 {
private:
    int idNum{0};
    string m_frname{NULL}, m_lname{NULL};
    double m_salary{0.0};
    double m_benefits{1000};
public:
    Employee2(int id, string frname, string lname, double salary,
              double benefits=1000) :
              idNum{id}, m_frname{frname}, m_lname{lname},
              m_salary{salary}, m_benefits{benefits} {
    }

    //return the current salary
    double getSalary() {
        return m_salary;
    }

    //return the name
    string getName() {
        return m_frname + " " + m_lname;
    }
};


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
        cout << emp->getId()<<"  "<< emp->getName() << "  " << emp->getSalary() <<" "<<emp->getBenefit()<< endl;
    }
    return 0;
}
