"""Filtered iterator used to return members of a single
swim club. The list of clubs is created by adding club names to a set
and then sorting the list"""

import tkinter as tk
from operator import attrgetter
from tkinter import *
import tkinter.ttk
from tkinter.ttk import *
import os, sys


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

        # creates a set of club names
        # using the set to eliminate duplicates
        self.clubs = set()
        for sw in self.swimmers:
            self.clubs.add(sw.club)

    # gets an array of clubs and sorts it
    def getClubs(self):
        clubnames = []
        for c in self.clubs:
            clubnames.append(c)
        clubnames.sort(reverse=False)
        return clubnames

    # returns an array of Swimmers
    def getSwimmers(self):
        return self.swimmers


# Filtered iterator returns only members of one club
class SwmrIter():
    def __init__(self, club, swmrs):
        self.club = club
        self.swmrs = swmrs

    def __iter__(self):
        self.index = 0
        return self

    # Next operation returns next swimmer in list
    # that is a club member
    # Terminated with StopIteration when the index
    # pass the end of the list
    def __next__(self):
        found = False
        while not found and self.index < len(self.swmrs):
            swm = self.swmrs[self.index]
            if swm.club == self.club:
                found = True
                self.index += 1
                return swm.getName()
            else:
                self.index += 1
                found = False
        raise StopIteration


# builds the UI, reads in the swimmer data
class Builder():
    def build(self):
        self.swmrs = Swimmers(os.path.join(sys.path[0], "100free.txt"))
        root = tk.Tk()
        root.geometry("350x250")
        root.title("Filtered")
        swlist = Listbox(root, width=25)
        slist = self.swmrs.getSwimmers()
        for sw in slist:
            swlist.insert(END, sw.frname + " " + sw.lname + "   " + sw.club)
        swlist.grid(row=0, column=0, rowspan=4, padx=10)

        self.combo = Combobox(root)

        self.combo['values'] = self.swmrs.getClubs()
        self.combo.current(0)
        self.combo.grid(row=0, column=1, padx=20)
        self.combo.bind("<<ComboboxSelected>>", self.cbclick)

        self.sublist = Listbox(root)
        self.sublist.grid(row=1, column=1, rowspan=3, padx=10)
        mainloop()

    def cbclick(self, evt):
        self.sublist.delete(0, END)
        club = self.combo.get()
        print(club)
        switer = SwmrIter(club, self.swmrs.getSwimmers())
        for val in switer:
            self.sublist.insert(END, val)


# ----------------------------
def main():
    Builder().build()


###  Here we go  ####
if __name__ == "__main__":
    main()
