#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

//same emplpoyee class as before
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
    double getBenefit() {return benefits;}
};

// a Cell contains the employee pointer,
// and a pointer to the the next and previous cells in the list
class Cell {
private:
    Employee* data;
    Cell* next{NULL};
    Cell* prev{NULL};
public:
    //constructor uses Employee pointer
    Cell(Employee* emp):data{emp}{}
    Employee* getData() {return data;}  //return employee

    //destructor
    ~Cell() {
        delete data;
    }
    //copy constructor
    Cell(const Cell &cnew) {
        data = NULL;
        next = NULL;
        prev = NULL;
    }
    //add a cell to the end of the chain
    void addNext(Cell* ecell) {
        next = ecell;
    }
    void addPrev(Cell* ecell) {
        prev = ecell;
    }
    Cell* getNext() {   //get pointer to next cell
        return next;
    }
    Cell* getPrev() {   //get pointer ot previous cell
        return prev;
    }
    void setNext(Cell* c) { //change the next pointer
        next = c;
    }
    void setPrev(Cell* c)    { //change the previous pointer
        prev = c;
    }
};

string names(Cell c) {
    string nm =  "no data";
    Employee* emp =  c.getData();
    if (emp != NULL) {
        Employee e = *emp;
        nm = e.getName();
        }
    return nm;
}

int main() {
    int id = 1;
    //create new Employee pointer
    Employee* emp1 = new Employee(id++, "Susan", "Sugar", 5000);
    //create a new Cell
    Cell* cell1 = new Cell(emp1);
    cout << names(*cell1) <<endl;  //get the name

    return 0;
}
