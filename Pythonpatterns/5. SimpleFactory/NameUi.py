"""Displays an entry field, two name fields and
3 buttons labeled COmpute, CLear, and Quit
The Compute and CLear buttons are derived from the
abstract DBUtton class
The NameFactory decides based on a comma whether the last name is first or not
and generates the correct Namer class"""
import tkinter as tk
from tkinter import *

import tkinter.ttk as ttk
from tkinter.ttk import *

# Derived class makes all labels blue
class BlueLabel(Label):
    def __init__(self, master, **kwargs):
        super().__init__(master, foreground='blue', **kwargs)

#base Namer class
class Namer():
    def __init__(self):
        self.last=""
        self.first=""

#derived namer class for First <space> Last
class FirstFirst(Namer):
    def __init__(self, namestring):
        super().__init__()
        i = namestring.find(" ")    #find space between names
        if i > 0 :
            names = namestring.split()
            self.first = names[0]
            self.last = names[1]
        else:
            self.last = namestring

#derived Namer class for Last <comma> First
class LastFirst(Namer):
    def __init__(self, namestring):
        super().__init__()
        i = namestring.find(",")  # find comma between names
        if i > 0 :
            names = namestring.split(",")
            self.last = names[0]
            self.first = names[1]
        else:
            self.last = namestring

"""The NameFactory returns an instance of the Namer class that separates first and last names
depending on whether a comma is present"""
class NamerFactory():
    def __init__(self, namestring):
        self.name = namestring
    def getNamer(self):
        i = self.name.find(",") # if it finds a comma
        if i>0:
            return LastFirst(self.name) # get the LastFirst class
        else:
            return FirstFirst(self.name) # else get the FirstFirst


class Builder:

    """clears all fields"""
    def clearPanel(self):
        self.frname.delete(0, END)
        self.lname.delete(0, END)
        self.entry.delete(0, END)

    """ fills the fields using the namer 
        from the Namer factory """
    def compute(self):
        name = self.entry.get()  # get the name string

        # get the Namer Factory and then the namer class
        namerFact = NamerFactory(name)  # get namer factory
        namer = namerFact.getNamer()  # get namer

        # get the names and copy them into the fields
        self.frname.insert(0, namer.first)
        self.lname.insert(0, namer.last)

    """Builds the UI """
    def buildUI(self):
        root = tk.Tk()
        root.title("Simple Factory")
        BlueLabel(root, text="Enter name").grid(row=0,columnspan=3 )

        self.entry = Entry(root)
        self.entry.grid(row=1, columnspan=3)

        BlueLabel(root,text="First name:").grid(row=2, column=0, sticky=W, pady=10)
        self.frname = Entry(root)
        self.frname.grid(row=2, column=1, sticky=E, pady=10)

        BlueLabel(root,text="Last name:").grid(row=3, column=0, sticky=W, pady=5);
        self.lname=Entry(root)
        self.lname.grid(row=3, column=1, sticky=E, pady=5)

        btcompute= Button(root,text="Compute",command=self.compute)
        btcompute.grid(row=4,column=0, pady=5)

        btclear= Button (root, text="Clear", command=self.clearPanel)
        btclear.grid(row=4, column=1, pady=5)

        btquit = Button(text="Quit", command=quit)
        btquit.grid(row=4, column=2, pady=5)

        mainloop()

def main():
    bld = Builder()
    bld.buildUI()

###  Here we go  ####
if __name__ == "__main__":
    main()


