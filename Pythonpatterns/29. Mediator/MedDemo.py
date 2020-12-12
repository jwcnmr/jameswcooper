"""Demo of Mediator pattern.
The Mediator class connects the buttons, listboxes
and entry field so that the rest of the program
doesn't need to know about them"""

import tkinter as tk
from operator import attrgetter
from tkinter import *
#import tkinter.ttk
#from tkinter.ttk import *

# Command interface
class Command():
    def comd(self):pass

# Mediator class for interaction between the buttons,
# entry field and lis boxes
class Mediator():
    def __init__(self, swmrs):
        self.swmrs = swmrs      # swimmers array
    # copy button
    def setCopyButton (self, copyb):
        self.copyb = copyb
        self.copyb.disable()   # start disabled
    # clear button
    def setClearButton(self, clearb):
        self.clearb = clearb
        self.clearb.disable()  # start disabled
    # left hand list
    def setSwlist(self, swlist):
        self.swlist = swlist
        # load the list box
        for sw in self.swmrs:
            self.swlist.insert(END, sw.getName() )

    # right hand list
    def setSublist(self, sublist): self.sublist = sublist
    # entry field
    def setEntryfield(self,entryf): self.entryf = entryf

    # copy button is clicked
    def copyClick(self):
        nm = self.entryf.get()  # copy entry into right list
        self.sublist.insert(END, nm)
        self.clearb.enable()    #enable the clear button

    # Clear button clears right list and entry field
    # disable buttons and list selection
    def clearClick(self):
        self.sublist.delete(0, END)
        self.entryf.delete(0, END)
        self.copyb.disable()
        self.clearb.disable()
        self.swlist.select_clear(0, END)

    # List clicked enables copy
    # and copies selection into entry field
    def listClicked(self,evt):
        self.copyb.enable()
        # get the selected name from the list box
        nm =self.swlist.get(self.swlist.curselection())
        self.entryf.delete(0, END) # clear the entry field
        self.entryf.insert(END, nm) # insert new name

#derived button class with an abstract comd method
class DButton(Button, Command):
    def __init__(self, master,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)
    # disable button
    def disable(self):
        try:
            self.state(['disabled'])    #ttk
        except AttributeError:
            self.configure(state="disable") #tkinter
    # enable button
    def enable(self):
        try:
            self.state(["!disabled"]) #ttk
        except AttributeError:
            self.configure(state=NORMAL) #tkinter

# Copy button calls Mediator
class CopyButton(DButton):
    def __init__(self, root, med:Mediator):
        super().__init__(root, text="Copy")
        self.med = med
        self.med.setCopyButton(self)
    def comd(self):
        self.med.copyClick()

# Clear button resets everything using Mediator
class ClearButton(DButton):
    def __init__(self, root, med:Mediator):
        super().__init__(root, text="Clear")
        self.med = med
        med.setClearButton(self)
    def comd(self):
        self.med.clearClick()

# One swimmer consists of name, club and time
class Swimmer():
    def __init__(self, dataline):
        sarray = dataline.split()  # read in a row and separate the columns
        i = 1  # skip the numbered column
        self.frname = sarray[1]  # names
        self.lname = sarray[2]
        self.age = int(sarray[3])  # age
        self.club = sarray[4]  # club symbol
        self.seedtime = sarray[5]  # seed time as string
        self.time = 0.0  # set defaults

        # remove colon from times of 1 minute or greater
        # so they can be sorted numerically
        if self.seedtime.find(":") > 0:
            mins = self.seedtime.split(":")
            atime = mins[0] + mins[1]  # time with colon removed
            self.time = float(atime)  # converted to float for sorting
        else:
            self.time = float(self.seedtime)

    def getName(self):
        return self.frname + " " + self.lname


# Array of swimmers that is displayed on the left
class Swimmers():
    def __init__(self, filename):
        self.swimmers = []

        # read in the data file for this event
        f = open(filename, "r")
        # the Swimmer class parses each line of the data file
        for swstring in f:
            sw = Swimmer(swstring)
            self.swimmers.append(sw)
        f.close()

    # returns an array of Swimmers
    def getSwimmers(self):
        return self.swimmers

# builds the UI, reads in the swimmer data
class Builder():
    def build(self):
        self.swmrs = Swimmers("100free.txt")
        root = tk.Tk()
        root.geometry("350x250")
        root.title("Mediator demo")

        # creates left list box then filled by Mediator
        self.swlist = Listbox(root, width=25) # swimmer listbox
        slist = self.swmrs.getSwimmers()
        med = Mediator(slist)       # create the Mediator
        med.setSwlist(self.swlist)  # pass in list box
        self.swlist.grid(row=1, column=0, rowspan=4, padx=10)

        #right list box filled by Copy button
        self.sublist = Listbox(root)
        self.sublist.grid(row=1, column=1, rowspan=3, padx=10)
        med.setSublist(self.sublist)

        # the frame contains the entry field and 2 buttons
        frame =Frame(root)
        frame.grid(row=0, columnspan=2)

        copyb = CopyButton(frame, med)
        copyb.pack(side=LEFT, padx=10)
        med.setCopyButton(copyb)

        clearb = ClearButton(frame, med)
        clearb.pack(side=LEFT, padx=10)
        med.setClearButton(clearb)

        entryf=Entry(frame)
        med.setEntryfield(entryf)
        entryf.pack(side=LEFT, padx=10)

       # connect click event to Mediator
        self.swlist.bind('<<ListboxSelect>>', med.listClicked)
        mainloop()

# ----------------------------
def main():
    Builder().build()


###  Here we go  ####
if __name__ == "__main__":
    main()
