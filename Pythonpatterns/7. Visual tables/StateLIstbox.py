from tkinter import ttk
from tkinter import *
from tkinter.ttk import *
import os, sys


DATA_FILE="states.txt"
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
        self.states= slist
        self.listbox = Listbox(root, selectmode=SINGLE)
        self.listbox.bind('<<ListboxSelect>>', self.lbselect)

        self.listbox.grid(column=0, row=0, rowspan=4, padx=10)

        self.entry=Entry(root)      #create an entry field at the bottom
        self.entry.grid(column=0, row=4, pady=4)
        self.entry.focus_set()      #set the focus to it
        self.entry.bind("<Key>", self.keyPress) #bind a keypress to lbselect method

        for state in self.states:
            self.listbox.insert(END, state.getStateName())

        #create 4 labels on right
        self.lbstate = Label("")
        self.lbabbrev = Label(root, text="", foreground="red")
        self.lbcapital = Label("")
        self.lbfounded = Label("")
        self.lbstate.grid(column=2, row=0, sticky=W) #left aligned
        self.lbabbrev.grid(column=2, row=1, sticky=W)
        self.lbcapital.grid(column=2, row=2, sticky=W)
        self.lbfounded.grid(column=2, row=3, sticky=W)

        #set up the scroll bar
        scrollBar = Scrollbar(root)
        scrollBar.config(command=self.listbox.yview)    #connect to listbox

        #stretch to top and bottom
        scrollBar.grid(row=0, column=1, rowspan=4, sticky="NS")
        #connect scrollbar y movement to listbox
        self.listbox.config(yscrollcommand=scrollBar.set)

#receives the listbox click event and loads the labels with state info
    def lbselect(self, evt):
        index = self.listbox.curselection()  #returns a tuple
        i= int(index[0])                    #this is the actual index
        state = self.states[i]              #get the state from the list
        self.loadLabels(state)

    def loadLabels(self,state):
        #fill in the labels from that state
        self.lbstate.config(text=state.getStateName())
        self.lbcapital.config(text=state.getCapital())
        self.lbabbrev.config(text=state.getAbbrev())
        self.lbfounded.config(text=state.getFounded())


    def keyPress(self, evt):
        char = evt.char.upper()
        i=0
        found= False
        #search for state starting with char
        while (not found) and (i< len(self.states)):
            found =  self.states[i].getStateName().startswith(char)
            if not found:
                i += 1
        if (found):
            state = self.states[i]      #get the state
            self.listbox.select_clear(0, END)   #clear selectsions
            self.listbox.select_set(i)      #set the selection
            self.listbox.see(i)             #make it visible
            self.loadLabels(state)          #load the labels

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