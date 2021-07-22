""" Illustrates what classes are for
Using the Employee class and two derived classes
and the Employees class which contains a dictionary
of Employee class instances"""

class Employee():
    def __init__(self, frname, lname, salary):
        self.idnum: int         #place holder
        self.frname = frname    #save name
        self.lname = lname
        self._salary = salary   # and salary
        self.benefits = 1000    # and benefits

    @property
    def salary(self):           # get the salary
        return self._salary

    def setSalary(self, val):   # store the salary
        self._salary = val

# Contains a dictionary of Employees, keyed by ID number
class Employees:
    def __init__(self):
        self.empDict = {}   # create a dictionary for employees
        self.index=101      # starting ID number

    def addEmployee(self, emp):
        emp.idnum = self.index  # set its ID
        self.index += 1         # go on to next ID
        self.empDict.update({emp.idnum: emp}) # add to dictionary

    # find the employee with that ID number
    def find(self, idnum):
        return self.empDict.get(idnum)


# This creates a small group Employees
class HR():
    def __init__(self):
        self.empdata = Employees()
        self.empdata.addEmployee(Employee('Sarah', 'Smythe', 2000))
        self.empdata.addEmployee(Employee('Billy', 'Bob', 1000))
        self.empdata.addEmployee(Employee('Edward', 'Elgar', 2200))

    def listEmployees(self):
        dict = self.empdata.empDict
        for key in dict:
            empl= dict[key] # get the employee instance
            # and print it out
            print (empl.frname, empl.lname, empl.salary)

def main():
   hr = HR()
   hr.listEmployees()
   fred = Employee('Fred', 'Smythe', 1200)


if __name__ == '__main__':
    main()


