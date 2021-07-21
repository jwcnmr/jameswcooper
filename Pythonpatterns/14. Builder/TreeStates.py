from tkinter import ttk
#import tkinter as tk
#import tkinter.ttk as ttk

from tkinter import *
from tkinter.ttk import *
import os, sys


DATA_FILE="states.txt"
"""Object representing one state
 Contains the name, abbreviation, capital and founding date"""
class State():
    def __init__(self, stateString):
        stateST=stateString.rstrip()
        self._tokens = stateString.split(",")
        self._statename=""
        print(self._tokens)
        if (len(self._tokens) > 3) :
            self._statename = self._tokens[0]
            self._abbrev = self._tokens[1]
            self._founded = self._tokens[2]
            self._capital = self._tokens[3]
    def getStateName(self):
        return self._statename

    def getCapital(self):
        return self._capital
    def getAbbrev(self):
        return self._abbrev
    def getFounded(self):
        return self._founded

"""Loads and contains the entire list of State objects"""
class StateList():
    def __init__(self, stateFile):
        with open (stateFile) as self.fobj:
            self.contents = self.fobj.readlines()
        i = 0
        self._states=[]
        while (i < len(self.contents)):
            if(len(self.contents[i]) > 0):
                self.state = State(self.contents[i])
                self._states.append(self.state)
                i += 1

    def getText(self):
        return self.contents

    def getStateList(self):
        return self._states



"""Loads the UI and manages the list click events"""
class BuildUI():
    def __init__(self, root, slist):
        root.geometry("350x200")
        self.states = slist
        self.tree = Treeview(root)

        self.tree["columns"] = ("abbrev", "capital", "founded")
        self.tree.column("#0", width=100, minwidth=100, stretch=NO)
        self.tree.column("abbrev", width=50, minwidth=50, stretch=NO)
        self.tree.column("capital", width=100, minwidth=100, stretch=NO)
        self.tree.column("founded", width=70, minwidth=60, stretch=NO)

        self.tree.heading('#0', text='Name')
        self.tree.heading('abbrev', text='Abbrev')
        self.tree.heading('capital', text='Capital')
        self.tree.heading('founded', text='Founded')
        style = ttk.Style()
        style.configure("Treeview.Heading", font=(None, 10, "bold"))

        i=1
        for state in self.states:
            self.tree.insert("", i, text=state.getStateName(), values=( state.getAbbrev(), state.getCapital(), state.getFounded()))
            i+=1

        self.tree.pack(side=TOP, fill=X)

#----------------------------------
def main():
    sl = StateList(os.path.join(sys.path[0], DATA_FILE))
    root = Tk()
    root.geometry("300x200")  # this one is pretty confusing
    bdui = BuildUI(root, sl.getStateList())

    root.title("State List")  # title only shows if window is wide enough
    root.mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()