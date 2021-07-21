import tkinter as tk
from tkinter import *
from tkinter import messagebox
from tkinter import ttk
from Lib import copy
import os, sys

# derived class from Button that contains empty comd function
class DButton(Button):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        super().config(command=self.comd)

    # abstract method to be called by children
    def comd(self):
        pass
class RefreshButton(DButton):
    def __init__(self,root,  bldr, **kwargs):
        super().__init__(root, text="Reload")
        self.bldr = bldr
    def comd(self):
        self.bldr.refreshLeft()

class CopyButton(DButton):
    def __init__(self,root,  bldr, **kwargs):
        super().__init__(root, text="Copy")
        self.bldr = bldr
    def comd(self):
        self.bldr.shallowCopy()

class CloneButton(DButton):
    def __init__(self,root,  bldr, **kwargs):
        super().__init__(root, text="Clone")
        self.bldr = bldr
    def comd(self):
        self.bldr.clone()

class ReloadButton(DButton):
    def __init__(self,root,  bldr, **kwargs):
        super().__init__(root, text="<--Refresh")
        self.bldr = bldr
    def comd(self):
        self.bldr.restoreLeft()


# Swimmer object holds all data on one swimmer
class Swimmer():
    def __init__(self, dataline):
        sarray = dataline.split(",")  # read in a row and separate the columns
        names = sarray[0]
        narray = names.split()
        self.frname = narray[0]  # names
        self.lname = narray[1]
        self.age = int(sarray[1])  # age
        self.club = sarray[2]  # club symbol
        self.seedtime = sarray[3]  # seed time as string
        self.sex = sarray[4].strip()
        self.time = 0.0  # set defaults

        # remove colon from times of 1 minute or greater
        # so they can be sorted numerically
        if self.seedtime.find(":") > 0:
            mins = self.seedtime.split(":")
            atime = mins[0] + mins[1]  # time with colon removed
            self.time = float(atime)  # converted to float for sorting
        else:
            self.time = float(self.seedtime)

    # mConcatenate first and last names
    def getName(self):
        return self.frname + " " + self.lname  # combine names


class BuildUI():
    def __init__(self,root):
        self.root = root
        root.geometry("400x200")
        root.title("Prototype demo")
        self.readFile()
        self.swmrs = self.sortUpwards()

        #build ui
        self.leftList = Listbox(width=25)
        self.leftList.grid(row=0, column=0, rowspan=4, sticky="W")
        self.cloneButton = CloneButton(root, self)
        self.cloneButton.grid(row=1, column=1)
        self.copyButton = CopyButton(root, self)
        self.copyButton.grid(row=2, column=1)
        self.reloadButton = ReloadButton(root, self)
        self.reloadButton.grid(row=3, column=1)
        self.refreshButton = RefreshButton(root, self)
        self.refreshButton.grid(row=4, column=1)

        self.rightlist = Listbox(width=25)
        self.rightlist.grid(row=0, column=2, rowspan=4, sticky="E")
        root.grid_columnconfigure(0, weight=1)
        root.grid_columnconfigure(2, weight=1)
        self.fillList(self.leftList, self.swmrs)

        mainloop()
    def readFile(self):
        self.swimmers = []  # array of swimmers
        # read in the data file for this event
        datafile = (os.path.join(sys.path[0], 'Swimmers.txt'))
        f = open(datafile, "r")
        # the Swimmer class parses each line of the data file
        for swstring in f:
            sw = Swimmer(swstring)
            self.swimmers.append(sw)
        f.close()

    def refreshLeft(self):
        self.readFile()
        self.swmrs = self.sortUpwards()
        self.fillList(self.leftList, self.swmrs)

    def fillList(self, list, swmrs):
        list.delete(0, END)
        for sw in swmrs:
             text = sw.getName()+" "+str(sw.age)+" "+sw.seedtime+" "+sw.sex
             list.insert(END, text)

    def sexLoad(self):
        swmrs=self.sbySex(self.swmrs)
        self.fillList(self.rightlist, swmrs)

    def shallowCopy(self):
        swmrs = self.swmrs  #copies the pointers not the data
        sw = self.sbySex(swmrs)
        self.fillList(self.rightlist, sw)

    def clone(self):
        swmrs=copy.copy(self.swmrs)
        sw= self.sbySex(swmrs)
        self.fillList(self.rightlist, sw)

    def sbySex(self, swmrs):
        for i in range(0, len(swmrs)):
            for j in range(i, len(swmrs)):
                if (swmrs[i].sex > swmrs[j].sex):
                    swtemp = swmrs[i]
                    swmrs[i] = swmrs[j]
                    swmrs[j] = swtemp
        return swmrs

    def restoreLeft(self):
        self.leftList.delete(0, END)
        self.fillList(self.leftList, self.swmrs)

        # Sorts the swimmers by seed time
    def sortUpwards(self):
        swmrs = []

        for swmr in self.swimmers:
            swmrs.append(swmr)

        for i in range(0, len(swmrs)):
            for j in range(i, len(swmrs)):
                if (swmrs[i].time > swmrs[j].time):
                    swtemp = swmrs[i]
                    swmrs[i] = swmrs[j]
                    swmrs[j] = swtemp
        return swmrs


# main begins here
def main():
    root=tk.Tk()
    builder = BuildUI(root)
    #builder.build()


###  Here we go  ####
if __name__ == "__main__":
    main()

