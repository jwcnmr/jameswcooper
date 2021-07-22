from tkinter import ttk
import tkinter as tk
import tkinter.ttk as ttk

from tkinter import *
from tkinter.ttk import *


DATA_FILE = "states.txt"
"""Object representing one state
 Contains the name, abbreviation, capital and founding date"""


class State():
    def __init__(self, stateString):
        self._tokens = stateString.split(",")   #split the string into tokens
        self._statename = ""
        if len(self._tokens) > 3:
            self._statename = self._tokens[0]   #state name
            self._abbrev = self._tokens[1]      #abbreviation
            self._founded = self._tokens[2]     #founding date
            self._capital = self._tokens[3]     #capital

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
        #read all lines into the contents
        with open(stateFile) as self.fobj:
            self.contents = self.fobj.readlines()

        self._states = []
        for st in self.contents:
            if len(st)>0:
                self.state = State(st)      #create a new State object
                self._states.append(self.state) #and add it to the list

    def getText(self):
        return self.contents

    def getStateList(self):
        return self._states

"""Loads the UI and manages the list click events"""
class BuildUI():
    def __init__(self, root, slist):
        self.states = slist
        #create list of names to add to combo box
        names=[]
        for s in self.states:
            names.append(s.getStateName())
        #add list to combo box
        self.combo = Combobox(root, values=names)
        self.combo.current(0)
        self.combo.bind('<<ComboboxSelected>>', self.onselect)
        self.combo.grid(column=0, row=0, rowspan=8, padx=10)

        # create 4 labels on right

        self.lbstate = Label( text="")
        self.lbabbrev = Label( text="", foreground="red")
        self.lbcapital = Label(text="")
        self.lbfounded = Label(text="")


        self.lbstate.grid( column=2, row=0, sticky=NW)  # left aligned
        self.lbabbrev.grid( column=2, row=1, sticky=NW)
        self.lbcapital.grid(column=2, row=2, sticky=NW)
        self.lbfounded.grid(column=2, row=3, sticky=NW)

    # receives the combo click event and loads the labels with state info
    def onselect(self, evt):
        index = self.combo.current()
        state = self.states[index]
        self.loadLabels(state)

    def loadLabels(self, state):
        # fill in the labels from that state
        self.lbstate.config(text=state.getStateName())
        self.lbcapital.config(text=state.getCapital())
        self.lbabbrev.config(text=state.getAbbrev())
        self.lbfounded.config(text=state.getFounded())
# ----------------------------------
def main():
    sl = StateList(DATA_FILE)
    root = Tk()
    root.geometry("300x200")  # this one is pretty confusing
    print ("starting")
    bdui = BuildUI(root, sl.getStateList())

    root.title("State List")  # title only shows if window is wide enough
    root.mainloop()


""" Here we go  """
if __name__ == "__main__":
    main()
