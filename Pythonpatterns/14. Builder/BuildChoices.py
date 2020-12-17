"""Demonstration of Builder Pattern
Listbox on left allows selection of one of 3 security type.
If that type contains more than three securities,
a multichoice listbox is created on the right.
Otherwise a group of up to 3 checkboxes is created.
Both support the same methods.
The Show button pops up a message box with those selected"""

import tkinter as tk
from tkinter import *
from tkinter import messagebox
from tkinter import ttk

"""This is the abstract base class
   that the listbox and checkbox choice Frames
   are derived from"""
class MultiChoice:
    def __init__(self, frame, choiceList):
        self.choices = choiceList    #save list
        self.frame = frame

   #to be implemented in derived classes
    def makeUI(self): pass  #fill a Frame of components
    def getSelected(self): pass  #get list of items

    #clears out the components of the frame
    def clearAll(self):
        for widget in self.frame.winfo_children():
            widget.destroy()

# derived class from Button that contains empty comd function
class DButton(Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        super().config(command=self.comd)

    # abstract method to be called by children
    def comd(self):
        pass

#Pops up message box showing selected securities
class ShowButton(DButton):
    def __init__(self, bldr, root, **kwargs):
        super().__init__( root, text="Show")
        self.bldr = bldr

    def comd(self):
        list = self.bldr.getSelected()
        text = ""
        for stock in list:
            text = text +  stock + "\n"
        messagebox.showinfo("Selected securities", text)

#----------------------------------------------
class ListboxChoice( MultiChoice):

    def  __init__(self, frame, choices):
        super().__init__(frame, choices)

    # creates and loads the listbox into the frame
    def makeUI(self):
       self.clearAll()
      #create a frame containing a list box
       self.list = Listbox(self.frame, selectmode=MULTIPLE)	#list box
       self.list.pack()

    #add investments into list box
       for st in self.choices:
           self.list.insert(END, st)

    # returns a list of the selected elements
    def getSelected(self):
        sel = self.list.curselection()
        selist=[]
        for i in sel:
            st = self.list.get(i)
            selist.append(st)
        return selist
#-----------------------------------------------
"""Checkbox class derived from Checkbutton
includes get methods to get the name var state"""
class Checkbox(Checkbutton):
    def __init__(self, root, btext, gvar):
        super().__init__(root, text=btext, variable=gvar)
        self.text=btext
        self.var = gvar     #saves the gvar here

    def getText(self):
        return self.text

    #returns whether checked or not
    def getVar(self):
        return int(self.var.get())   #get the value stored in this IntVar


#---------------------------------------
class CheckboxChoice(MultiChoice):
    def __init__(self, panel, choices):
        super().__init__(panel, choices)

    #creates the checkbox UI
    def makeUI(self):
        self.boxes = []  # list of check boxes stored here
        self.clearAll()
        r = 0
        for name in self.choices:
            var = IntVar()  # create an IntVar
            cb = Checkbox(self.frame, name, var)  # create checkbox
            self.boxes.append(cb)  # add it to list
            cb.grid(column=0, row=r, sticky=W)  # grid layout
            r += 1

     # returns list of selected check boxes
    def getSelected(self):
        items=[]
        for b in self.boxes:
            if b.getVar() > 0:
                items.append(b.getText())
        return items
        #---------------------------------------
# This factory makes either a Listbox Choice or a Checkbos Choice frame
class ChoiceFactory:
   """This class returns a Panel containing
   a set of choices displayed by one of
   several UI methods. """
   def getChoiceUI(self, choices, frame):
        if len(choices) <=3:
        #return a panel of checkboxes
            return CheckboxChoice(frame, choices)
        else:
        #return a multi-select list box panel
            return ListboxChoice(frame, choices)

"""List of securities and name of type of security"""
class Securities() :
    def __init__(self, name, list):
        self.name = name
        self.list = list
    def getName(self):
        return self.name
    #returns list of security names
    def getList(self):
        return self.list
# UI Builder class creates window and securities lists
class BuildUI():
    def __init__(self, root):
        self.root = root
        self.root.geometry("250x200")
        self.root.title("Wealth Builder")
        self.seclist=[] #start with empty list
     #create the UI
    def build(self):
        # create securities list
        self.stocks= Securities("Stocks", ["Cisco", "Coca Cola", "General Electric", "Harley-Davidson", "IBM"])
        self.seclist.append(self.stocks)
        self.bonds = Securities("Bonds", ["CT State GO 2024", "New York GO 2026", "GE Corp Bonds"] )
        self.seclist.append(self.bonds)
        self.mutuals = Securities("Mutuals", ["Fidelity Magellan", "T Rowe Price", "Vanguard Primecap", "Lindner"])
        self.seclist.append(self.mutuals)

        # Fill left list box with security types
        lframe = Frame(self.root)     # frame for left side
        lframe.grid(row=0, column=0)

        # Note that Windows 10 requires the exportselection setting
        # or clicks on either listbox will be received
        self.leftList = Listbox(lframe, exportselection=FALSE)
        self.leftList.pack()
        # add in names of types of securities
        for sec in self.seclist:
            self.leftList.insert(END, sec.getName())

        # connect select event to the lbselect method
        self.leftList.bind('<<ListboxSelect>>', self.lbselect)
        self.rframe = Frame(self.root, name="right")
        self.rframe.grid(row=0, column=1)
        self.showbutton = ShowButton(self, self.root)
        self.showbutton.grid(row=1, column=0, columnspan=2)

        mainloop()

    # callback when left list box is selected
    def lbselect(self, evt):
        index = self.leftList.curselection()  # returns a tuple
        i = int(index[0])  # this is the actual index
        securities = self.seclist[i]
        cf = ChoiceFactory()
        self.cui = cf.getChoiceUI(securities.getList(), self.rframe)
        self.cui.makeUI()         #creates right hand panel

   # returns list of selected items no matter what display
    def getSelected(self):
        return self.cui.getSelected()

# main begins here
def main():
    root=tk.Tk()
    builder = BuildUI(root)
    builder.build()

###  Here we go  ####
if __name__ == "__main__":
    main()
