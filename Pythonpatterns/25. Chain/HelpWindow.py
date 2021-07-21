"""Demonstration of a Help system
using the Chain of Responsibility
Each widget checks to see if it has the focus
and if so, displays its help message"""
import tkinter as tk
from tkinter import *
import tkinter.ttk
from tkinter.ttk import *
from tkinter import messagebox
import sys

# Derived button class with an abstract comd method
class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

    def comd(self):pass

# Chain base class
class Chain():
    def addChain(self, chain):
        self.nextChain = chain

    def sendToChain(self, evt):pass

    
# the File button and help message
class FileButton(DButton, Chain):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="File", **kwargs)

    def sendToChain(self, evt):
        sel = self.focus_get()._name
        nm = self._name
        if sel.find(nm) >=0:
            messagebox.showinfo("File button",
                            "Opens an existing file")
        else:
            self.nextChain.sendToChain(evt)

# The New button
class NewButton(DButton, Chain):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="New", **kwargs)
        self.root = root

# for the first chain link, we have to check that something has the focus
    def sendToChain(self, evt):
        s1 = str(self.focus_get()) #check name of focus object
        if len(s1)>1:   #if it is "." it is the frame
            sel = self.focus_get()._name    #get the real focus object
            nm = self._name         #and the name of this class

            if sel.find(nm) >=0:    #sel will start with a "!"
                messagebox.showinfo("New button", "Creates a new file")
            else:
                self.nextChain.sendToChain(evt)
        else:
            # if no object has focus display general message
            messagebox.showinfo("Button help",
                            "Select any control using the Tab key\n"
                           + "to get help on using it" )


# Quit button actually exits the program
class QuitButton(DButton, Chain):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Quit", **kwargs)

    def sendToChain(self, evt):
        sel = self.focus_get()._name
        nm = self._name
        if sel.find(nm) >=0:
            messagebox.showinfo("Quit button", "Exits from the program")
        else:
            self.nextChain.sendToChain(evt)
    def comd(self):
        sys.exit()  #exit the program

# Derived Checkbox from Checkbutton
# keeps the IntVar internally to each instace
class Checkbox(Checkbutton):
    def __init__(self, root, btext, gvar):
        super().__init__(master=None, text=btext, variable=gvar)
        self.text=btext
        self.var = gvar

    def getText(self):
        return self.text
    def getVar(self):
        return self.var.get()   #get the value stored in this IntVar

# Text checkbox widget
class TextCheck(Checkbox, Chain):
    def __init__(self, root, btext, gvar):
       super().__init__(root, btext, gvar)
       self.text = btext
       self.var = gvar

    def sendToChain(self, evt):
       sel = self.focus_get()._name
       nm = self.__class__.__name__.lower()
       if sel.find(nm) >=0:
           messagebox.showinfo("Text checkbox", "Limits selection to text files")
       else:
           self.nextChain.sendToChain(evt)
# Bin checkbox widget
class BinCheck(Checkbox, Chain):
    def __init__(self, root, btext, gvar):
        super().__init__(root, btext, gvar)
        self.text = btext
        self.var = gvar
    def sendToChain(self, evt):
        sel = self.focus_get()._name
        nm = self.__class__.__name__.lower()

        if sel.find(nm) >=0:
            messagebox.showinfo("Binary checkbox", "Limits selection to binary files")
        else:
            if self.nextChain != None:
                self.nextChain.sendToChain(evt)

# UI Builder starts here
class HelpWindow():
    def build(self):
        self.root = tk.Tk()
        self.root.geometry("250x150")
        self.frame = self.root

        self.root.title("Help demo")

        self.newButton = NewButton(self.frame, width=7)
        self.newButton.grid(row=0, column=0, padx=20, pady=5)

        self.fileButton = FileButton(self.frame, width=7)
        self.fileButton.grid(row=1, column =0, padx=20, pady=5)

        self.quitButton = QuitButton(self.frame, width=7)
        self.quitButton.grid(row=2, column=0, padx=20, pady=5)

        var = IntVar(0)
        self.textCheck = TextCheck(self.frame, "Text Files", var)
        self.textCheck.grid(row=0, column=1, padx=5, pady=5, sticky=W)

        var1 = IntVar(0)
        self.binCheck = BinCheck(self.frame, "Binary Files", var1)
        self.binCheck.grid(row=1, column=1, padx=5, pady=5, sticky=W)
        # connect the keystroke event monitor
        self.frame.bind("<Key>", self.keyPress)

        # construct the Chain of Responsibility
        self.newButton.addChain(self.fileButton)
        self.fileButton.addChain(self.quitButton)
        self.quitButton.addChain(self.textCheck)
        self.textCheck.addChain(self.binCheck)

        mainloop()

   #intercepts all key strokes but only acts on 'F1'
    def keyPress(self, evt):
        if evt.keysym == 'F1':
            self.newButton.sendToChain(evt)

# Program starts here
def main():
    HelpWindow().build()

###  Here we go  ####
if __name__ == "__main__":
    main()