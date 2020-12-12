"""Observer pattern demo
The ColorRadio is a Subject which sends messages to the Observers
The ColorFrame and ColorList act as observers and represent
the selected color as a colored frame or a list of colors.
Note the use of TopLevel instead of Frame for the other two windows"""
import tkinter as tk
from operator import attrgetter
from tkinter import *

# interface all observers must have
class Observer:
    def sendNotify(self):
        pass
# interface the Subject must have
class Subject:
    def registerInterest(self, obs:Observer):
        pass

# ChoiceButton is derived from RadioButton
class ChoiceButton(tk.Radiobutton):
    def __init__(self, root, color, index, gvar, **kwargs):
        super().__init__(root, text=color,
                         padx=20,
                         variable=gvar, value=index,**kwargs)

        self.pack(anchor=W)
        self.root = root
        self.color = color
        self.index = index
        self.var = gvar

# list box that displays the text of the chosen color
class ColorList(Observer):
    def __init__(self, master=None):
        frame = Toplevel(master)
        frame.geometry("100x100")
        frame.title("Color list")
        self.list = Listbox(frame)
        self.list.pack()

    def sendNotify(self, color: str):
        self.list.insert(END, color.capitalize())

# a Frame that is filled with the chosen color
class ColorFrame(Observer):
    def __init__(self, master=None):
        self.frame = Toplevel(master)
        self.frame.geometry("100x100")
        self.frame.title("Color")

    def sendNotify(self, color:str):
        self.frame.config(bg = color)

# The base Subject window that sends messages to the Observers
class ColorRadio(Subject):
    def __init__(self, root):
        root.geometry("100x100")
        root.title("Subj")
        self.subjects = []
        self.var = tk.IntVar()
        self.colors=["red", "blue", "green"]

        ChoiceButton(root, 'Red', 0, self.var, command=self.colrChange)
        ChoiceButton(root, 'Blue', 1, self.var, command=self.colrChange)
        ChoiceButton(root, 'Green', 2, self.var, command=self.colrChange)
        self.var.set(None)  # No buttons selected

    def colrChange(self):
        cindex = self.var.get()  #get the index of the color
        color = self.colors[cindex] # look up in color list

        #send notification to all the observers
        for subj in self.subjects:  #send color name to Observers
            subj.sendNotify(color)

    # Observers tell the Subject they want to know of changes
    def registerInterest(self, subj:Subject):
        self.subjects.append(subj)

#Create the three windows
class Builder():
    def build(self):
        root = tk.Tk()
        colr = ColorRadio(root)   #create radio frane
        cframe = ColorFrame(None) #create color frame
        colr.registerInterest(cframe) # and register it
        clist = ColorList(None)      #create color lis
        colr.registerInterest(clist) # and register it

        mainloop()
# ----------------------------
def main():
    Builder().build()

###  Here we go  ####
if __name__ == "__main__":
    main()
