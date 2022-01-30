"""Illustrates how len function works polymorphically"""
from dataclasses import dataclass
@dataclass
class Employee:
    frname: str
    lname: str
    salary: int
    height: int

    def compensation(self):
        return self.salary
    def __len__(self):
        return self.height

name = 'Snuffy Smith'
mylist = [1,4,6,4,8,7]
myset= {'apples', 'oranges', 'grapes'}
mytuple = (23,42, 76, 143)

print(len(name), len(mylist), len(myset), len(mytuple))
emp =Employee('Snuffy', 'Smith', 1200, 67)
print (emp.frname, len(emp))