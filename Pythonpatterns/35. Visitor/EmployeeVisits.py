"""Visitor Pattern demonstration
The Employee and Boss objects have an accept method
which is called by the two visitors.
Then thar method calls the visit method of the visitor,
passing it an instance of that Employee or Boss class.
"""
import tkinter as tk
from tkinter import *


# The mediator controls the visual interface
# A mouse click on the list box, fills the two
# fields with the vacation status of that employee
# Clicking on the Visit button runs the two visitors
# on the whole list of employees and puts the totals
# in the two fields
class Mediator():
    def setEmployees(self, emp):
        self.employees = emp  # employee list

    def setFields(self, tot, btot):
        self.total = tot  # references to two fields
        self.btotal = btot

    def vclick(self):
        vac = VacationVisitor()  # create the 2 visitos
        bvac = BVacationVisitor()
        self.clearFields()
        # do the visitations
        for emp in self.employees:
            emp.accept(vac)
            emp.accept(bvac)
        # put the totals in the two fields
        self.total.insert(0, str(vac.getTotalDays()))
        self.btotal.insert(0, str(bvac.getTotalDays()))

    # clear the two fields
    def clearFields(self):
        self.total.delete(0, END)
        self.btotal.delete(0, END)

    # get the list reference
    def setList(self, lb):
        self.list = lb

    # when a list member is clicked,
    # display those vacation properties
    def clickList(self, evt):
        index = self.list.curselection()
        i = index[0]  # induex is a tuple, get the 0th elemnt
        emp = self.employees[i]
        # clear fields and insert values
        self.clearFields()
        self.total.insert(0, str(emp.getVacDays()))
        if isinstance(emp, Boss):
            self.btotal.insert(0, str(emp.getBonusdays()))


# derived button class with an abstract comd method
class DButton(Button):
    def __init__(self, master, **kwargs):
        super().__init__(master, command=self.comd, **kwargs)


# Button launches the vistations can calls the Mediator
class VisitButton(DButton):
    def __init__(self, root, med, **kwargs):
        super().__init__(root, text="Visit", **kwargs)
        self.med = med

    def comd(self):
        self.med.vclick()


# abstract base class
class Visitor():
    def visit(self, emp):
        pass


# base Employee class holds vacation days and name
# and other fields we don't use herer
class Employee():
    def __init__(self, name, salary, vacdays, sickdays):
        self.vacDays = vacdays  # save the days
        self.sickdays = sickdays
        self.salary = salary    #salary
        self.name = name        #and anme

    # return the name
    def getName(self):  return self.name
    # and vacation days
    def getVacDays(self): return self.vacDays
    def getSalary(self): return self.salary
    # accept the Visitor and call ie
    def accept(self, v: Visitor):
        v.visit(self)


# vistor class sums the total vacation days
class VacationVisitor(Visitor):
    def __init__(self):
        self.totaldays = 0

    def visit(self, emp: Employee):
        self.totaldays += emp.getVacDays()

    def getTotalDays(self):
        return self.totaldays


# Boss is like Employee but has bonus vacation days
class Boss(Employee):
    def __init__(self, name, salary, vacdays, sickdays):
        super().__init__(name, salary, vacdays, sickdays)
        self.bonusdays = 0

    def setBonusdays(self, bd):
        self.bonusdays = bd

    def getBonusdays(self):
        return self.bonusdays

    # accept the Visitor and call it
    def accept(self, v: Visitor):
        v.visit(self)


# The Boss vacation visitor gets both the
# vacation and bonus days
class BVacationVisitor(VacationVisitor):
    def __init__(self):
        self.totaldays = 0

    def visit(self, emp: Employee):
        self.totaldays += emp.getVacDays()

    # adds in total days including bonus days
    def visit(self, emp: Boss):
        self.totaldays += emp.getVacDays()
        if isinstance(emp, Boss):
            self.totaldays += emp.getBonusdays()


# builds the UI and initializes the Mediator
class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("350x200")
        root.title("Visitor demo")
        # Listbox
        self.listbox = Listbox(root, width=25, height=8)
        self.listbox.grid(row=0, column=0, rowspan=5)
        # set up entry fields
        self.vac = Entry(root, width=20)
        self.vac.grid(row=0, column=1, sticky=NW, padx=10)
        self.bonus = Entry(root, width=20)
        self.bonus.grid(row=1, column=1, sticky=NW, padx=10)
        # set up Mediator
        self.med = Mediator()
        self.listbox.bind('<<ListboxSelect>>', self.med.clickList)
        self.med.setList(self.listbox)
        self.med.setFields(self.vac, self.bonus)
        # create visit button which tells the Mediator
        self.vbutton = VisitButton(root, self.med)
        self.vbutton.grid(column=1, row=2)
        self.loadList()
        mainloop()

    # Put employees names in list box
    def loadList(self):
        employees = []
        employees.append(Employee("Susan Bear", 55000, 12, 1))
        employees.append(Employee("Adam Gehr", 150000, 9, 0))
        employees.append(Employee("Fred Harris", 50000, 15, 2))
        employees.append(Employee("David Oakley", 57000, 12, 2))
        employees.append(Employee("Larry Thomas", 100000, 20, 6))
        b = Boss("Leslie Susi", 175000, 16, 4)
        b.setBonusdays(12)
        b1 = Boss("Laurence Byerly", 35000, 17, 6)
        b1.setBonusdays(17)
        employees.append(b)
        employees.append(b1)
        # give this list to the Mediator, too
        self.med.setEmployees(employees)
        for emp in employees:
            self.listbox.insert(END, emp.getName())


# ----------------------------
def main():
    Builder().build()


###  Here we go  ####
if __name__ == "__main__":
    main()
