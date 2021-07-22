from tkinter import ttk
from tkinter import *
from tkinter.ttk import *
import os, sys


DATA_FILE="States.txt"
"""Object representing one state
 Contains the name, abbreviation, capital and founding date"""
class State():
    def __init__(self, stateString):
        self._tokens = stateString.split(",")
        self._statename=""
        if (len(self._tokens) > 3) :
            self._statename = self._tokens[0]
            self._abbrev = self._tokens[1]
            self._founded = self._tokens[2]
            self._capital = self._tokens[3]
    def getStateName(self):
        return self._statename
    def toString(self):
        return self._statename
    def getCapital(self):
        return self._capital
    def getAbbrev(self):
        return self._abbrev

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
        self.states= slist
        self.listbox = Listbox(root, selectmode=SINGLE)
        #self.listbox.bind('<<ListboxSelect>>', self.onselect)
        self.listbox.grid(column=0, row=0, rowspan=4, padx=10)
        for state in self.states:
            self.listbox.insert(END, state.getStateName())


#----------------------------------
def main():
    sl = StateList(os.path.join(sys.path[0],DATA_FILE))
    root = Tk()
    root.geometry("300x200")  # this one is pretty confusing
    bdui = BuildUI(root, sl.getStateList())

    root.title("Simple State List")  # title only shows if window is wide enough
    root.mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()
