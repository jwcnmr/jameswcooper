""" Program to create an Boss -- Employee tree fpr a small company
And display it in a Treeview"""


import tkinter as tk
from tkinter import *
from tkinter.ttk import *
from random import *

class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

    def comd(self):pass

#click here to compute salaries under selected employee
class SalaryButton(DButton):
    def __init__(self,  master, boss, entry, **kwargs):
        super().__init__(master, text="Salaries")
        self.boss = boss
        self.entry = entry

    def comd(self):
        curitem = Tree.tree.focus() #get selected item
        dict= Tree.tree.item(curitem)
        name= dict["text"]          #get name

        #search for match
        if name == self.boss.name:
            print(name, self.boss.name)
            newEmp = self.boss
        else:
            newEmp = self.boss.getChild(name)
        sum = newEmp.getSalaries()

        # put salary sum in entry field
        self.entry.delete(0, "end")
        self.entry.insert(0, str(sum))

# Employee is the base class
class Employee():
    def __init__(self, name, salary:int):
        self.name = name
        self.salary = salary
        self.isleaf = True

    def getSalaries(self):  return self.salary
    def getSubordinates(self): return None


# Boss is derived from Employee. Only Bosses can have subordinates
class Boss(Employee):
    def __init__(self, name, salary:int):
        super().__init__(name, salary)
        self.subordinates = []
        self.isleaf = False

    def getSubordinates(self):  return self.subordinates
    def add(self, e:Employee): self.subordinates.append(e)

    # called recursively as it walks down the tree
    def getSalaries(self):
        self.sum = self.salary
        for e in self.subordinates:
            self.sum = self.sum + e.getSalaries()
        return self.sum

    # Create the Treeview for the Employee structure
    def makeTree(self, tree:Treeview):
        self.index=0
        self.tree = tree
        bossnode = self.tree.insert("", "end", id="Boss", text="CEO")
        self.index=1
        Tree.tree=self.tree
        self.addNodes(bossnode, self)

# builds Treeview recursively, walking down the tre
    def addNodes(self, pnode, emp:Employee ):
        if not emp.isleaf:      #Bosses are not Leaves
            empList = emp.subordinates
            if empList != None: # must be a Boss
               for newEmp in empList:
                    newnode = Tree.tree.insert(pnode,
                            Tree.index,
                            text = newEmp.name)
                    self.addNodes(newnode, newEmp)

    #finds child node with matching name
    def getChild(self, name:str):
        if self.name == name :
            return self
        else:
            found = False
            index = 0
            newEmp = None
            while not found and index < len(self.subordinates) :
                newEmp = self.subordinates[index]
                found = newEmp.name == name

                if not found :
                    if not newEmp.isleaf:
                        newEmp = newEmp.getChild(name)
                    else:
                        newEmp = None
                found = newEmp != None
                index += 1

            if found:
                return newEmp
            else:
                return None

#static class used to keep values for recursive calls
class Tree():
    tree = None
    index=0
    column=0

# Creates the employee tree structure
# salaries are generated partly using random numbers
class Builder():
    def __init__(self, root):
        self.root = root
        self.root.geometry("200x300")
        self.root.title("Employee tree")

    #builds the employee tree
    def build(self):
        seed(None, 2)       #initiialize random seed
        boss = Boss("CEO", 200000)
    # add VPs under Boss
        marketVP = Boss("Marketing_VP", 100000)
        boss.add(marketVP)
        prodVP = Boss("Production_VP", 100000)
        boss.add(prodVP)
        salesMgr = Boss("Sales_Mgr", 50000)
        marketVP.add(salesMgr)
        advMgr = Boss("Advt_Mgr", 50000)
        marketVP.add(advMgr)
        # add salesmen reporting to Sales Mgr
        for i in range(0, 6):
            salesMgr.add(Employee("Sales_" + str(i),
                    int(30000.0 + random() * 10000)))
        advMgr.add(Employee("Secy", 20000))
        prodMgr = Boss("Prod_Mgr", 40000)
        prodVP.add(prodMgr)
        shipMgr = Boss("Ship_Mgr", 35000)
        prodVP.add(shipMgr)

        # Add manufacturing and shipping employees
        for i in range(0, 4):
            prodMgr.add(Employee("Manuf_" + str(i),
                    int(25000 + random() * 5000)))
        for i in range(0, 4):
            shipMgr.add(Employee("Ship_Clrk_" + str(i),
                    int(20000 + random() * 5000)))

        self.buildUI(boss)
        #boss.getSalaries()
    #creates the window and user interface
    def buildUI(self, boss):
        self.frame = Frame(self.root, borderwidth=4, relief=GROOVE)
        self.frame.pack()
        self.tree = Treeview(self.frame)
        self.entry = Entry(self.frame)

        self.salbutton = SalaryButton(self.frame,boss, self.entry)


        self.tree.column("#0", width=150, minwidth=510, stretch=NO)
        self.tree.pack()
        self.salbutton.pack()
        self.entry.pack()
        boss.makeTree(self.tree)

# --program starts here---
def main():
    root = tk.Tk()
    bui = Builder(root)
    bui.build()
    mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()
