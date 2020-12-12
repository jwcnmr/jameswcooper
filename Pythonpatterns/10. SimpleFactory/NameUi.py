"""Displays an entry field, two name fields and
3 buttons labeled COmpute, CLear, and Quit
The Compute and CLear buttons are derived from the
abstract DBUtton class
The NameFactory decides based on a comma whether the last name is first or not
and generates the correct Namer ckass"""
import tkinter as tk
from tkinter import *

import tkinter.ttk as ttk
from tkinter.ttk import *

#abstract button class
class DButton(Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        super().config(command=self.comd)   #abstract since comd is empty

    # abstract method to be called by children
    def comd(self):
        pass

"""This button takes the text from the entryfield
uses the NamerFactory to create the right namer
and then loads the two entry fields for first and last names"""
class ComputeButton(DButton):
    def __init__(self, root, namefield, frname, lname):
        super().__init__(root, text="Compute")
        self.entry = namefield
        self.frname = frname
        self.lname = lname

   #replaces empty comd in base abstract class
    def comd(self):
        name = self.entry.get()
        namer = NamerFactory(name)
        self.frname.insert(0, namer.getNamer().getFirst())
        self.lname.insert (0, namer.getNamer().getLast())

class ClearButton(DButton):
    def __init__(self, root, namefield, frname, lname):
        super().__init__(root, text="Clear")
        self.entry = namefield
        self.frname = frname
        self.lname = lname
    def comd(self):
        self.frname.delete(0, END)
        self.lname.delete(0, END)
        self.entry.delete(0, END)

#base Namer class
class Namer():
    def __init__(self):
        self.last=""
        self.first=""
    def getFirst(self):
        return self.first
    def getLast(self):
        return self.last

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
dependning on whether a comma is present"""
class NamerFactory():
    def __init__(self, namestring):
        self.name = namestring
    def getNamer(self):
        i = self.name.find(",") #if it finds a comma
        if i>0:
            return LastFirst(self.name) #get the LastFirst class
        else:
            return FirstFirst(self.name) #else get the FirstFirst

def buildUI():
    root = tk.Tk()
    root.title("Simple Factory")
    Label(root, text="Enter name").grid(row=0,columnspan=3 )

    entry = Entry(root)
    entry.grid(row=1, columnspan=3)

    Label(root,text="First name:").grid(row=2, column=0, sticky=W, pady=10)
    frentry = Entry(root)
    frentry.grid(row=2, column=1, sticky=E, pady=10)

    Label(root,text="Last name:").grid(row=3, column=0, sticky=W, pady=5);
    lsentry=Entry(root)
    lsentry.grid(row=3, column=1, sticky=E, pady=5)

    btcompute= ComputeButton(root,entry,frentry,lsentry)
    btcompute.grid(row=4,column=0, pady=5)

    btclear= ClearButton (root, entry,frentry, lsentry)
    btclear.grid(row=4, column=1, pady=5)

    btquit = Button(text="Quit", command=quit)
    btquit.grid(row=4, column=2, pady=5)

    mainloop()

def main():
    buildUI()
###  Here we go  ####
if __name__ == "__main__":
    main()


