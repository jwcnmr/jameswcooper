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
    /*
    Cell(Cell &c) {
        data = nullptr;
        next = nullptr;
        prev = nullptr;
    }*/
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

//iterator to move forward through the linked list
class fwdIter{
protected:
    Cell* cell;

public:
    fwdIter(Cell* c)  {
        cell = c;       //save the starting cell
    }
    bool hasMore() {
        return cell != NULL; //no more if NULL
    }
    Cell* getNext() {
        auto retCell = cell;    //save this cell
        cell = cell->getNext(); //get the next one (or NULL)
        return retCell;         //return current cell
    }
};
//iterator to move backward from end of list
class revIter:public fwdIter {
public:
    revIter(Cell* c) :fwdIter(c){

    }
    Cell* getNext() {
        auto retCell = cell;
        cell = cell->getPrev();
        return retCell;
    }
};

//constructs the linked list
class LinkedList{
private:
    Cell* head;     //start of list
    Cell* tail;     //last member of list
public:
    LinkedList(Cell* ecell){
        head = ecell;
        tail = ecell;
    }
    //add cell to end of list
    void addCell (Cell* ecell) {
        tail->addNext(ecell);
        auto oldtail = tail;
        tail =  ecell;
        ecell->addPrev(oldtail);
    }
    Cell* getHead() {
        return head;
    }
    Cell* getTail() {
        return tail;
    }
    fwdIter* getFwdIter() {
        return new fwdIter(head);
    }
    revIter* getRevIter() {
        return new revIter(tail);
    }
    //insert cell after cleft
    void insertCell(Cell* cleft, Cell* cnew) {
        Cell* cright = cleft->getNext();  //cell to right of cleft
        cleft->setNext(cnew);   //set pointer to new cell
        cnew->setNext(cright);  //set right pointer in cnew
        cright->setPrev(cnew);  //set prev pointer in cright
        cnew->setPrev(cleft);   //set prev pointer in cnew
    }
};

//print out the list forward and backward
void printLinks(LinkedList* links) {
    fwdIter* fwd = links->getFwdIter();
    while (fwd->hasMore()) {
        Cell* cell = fwd->getNext();
        Employee* emp = cell->getData();
        cout << emp->getName() << endl;
    }
    revIter* rev = links->getRevIter();
    cout <<endl;
    while (rev->hasMore()) {
        Cell* cell = rev->getNext();
        Employee* emp = cell->getData();
        cout << emp->getName() << endl;
    }
    cout << endl;

}
int main() {
    int id = 1;
    //create new Employee pointer
    Employee* emp1 = new Employee(id++, "Susan", "Sugar", 5000);
    //create a new Cell
    Cell* cell1 = new Cell(emp1);
    //create the linked list with one cell in it.
    LinkedList* links =  new LinkedList(cell1);

    //create remaining Employees and Cells in a single statement
    links->addCell(new Cell(new Employee(id++, "Sarah", "Smythe", 2000)));
    links->addCell(new Cell(new Employee(id++, "Billy", "Bob", 1000)));
    links->addCell(new Cell(new Employee(id++, "Arnold", "Stang", 800)));

    printLinks(links);
    // insert a cell:
    //    first create the employee
    Employee* emp2 = new Employee(id++, "Bonnie", "Ocean", 6000);
    Cell* cell2 = new Cell(emp2);  //and the cell
    links->insertCell(cell1, cell2);  //insert cell2 after cell1
    printLinks(links);

    //illustrates copy constructor
    Cell c = *cell2;        //get a cell from above
    Cell newCell = Cell(c); //use copy constructor
    Employee* cdat = newCell.getData();
    cout << newCell.getData()->getName()<<endl;

    return 0;
}
