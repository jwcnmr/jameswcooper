"""Illustrtaes polymorphism in derived classes
Here the compensation method returns different data
in the two classes """

from dataclasses import dataclass
@dataclass
class Employee:
    frname: str
    lname: str
    salary: int

    def compensation(self):
        return self.salary

class TopEmployee(Employee):
    def __init__(self, frname, lname, salary):
        super().__init__(frname, lname, salary)
        self.stockOptions = 0

    def setOptions (self, stockval):
        self.stockOptions = stockval

    def compensation(self):
        return self.salary +  self.stockOptions

emp = Employee('Snuffy', 'Smith', 11000)
topEmp = TopEmployee('James', 'Bond', 100000)
topEmp.setOptions(5000)
print(emp.frname, emp.compensation())
print (topEmp.frname, topEmp.compensation())
