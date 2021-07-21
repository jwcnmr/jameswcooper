"""Chain of Responsibility demonstration.
Text typed into the entry field gets forwarded down a chain fof 4 applications"""
import tkinter as tk
from tkinter import *

import tkinter.ttk
from tkinter import *
from tkinter.ttk import *
import os
from PIL import ImageTk, Image

#derived button class with an abstract comd method
class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

    def comd(self):pass

# Send button initiates sending text down the chain
class EntryButton(DButton):
    def __init__(self, root, echain):
        super().__init__(root, text="Send ")
        self.echain = echain

    def comd(self):
        self.echain.buttonClick()

# Chain base class
class Chain():
    def addChain(self, chain):
        self.nextChain = chain
    def sendToChain(self, mesg:str): pass
    #@property
    #def nextChain(self):
    #    return self._nextChain

# looks fod jpg file to display
class ImageChain(Canvas, Chain):
    def __init__(self, root, **kwargs):
        super().__init__(root, **kwargs)
        self.root = root
        self.nextchain=None

    def sendToChain(self, mesg:str):
        try:
            img = Image.open(mesg + ".jpg")
            self.photoImg = ImageTk.PhotoImage(img)
            self.create_image(0, 0, anchor=NW, image=self.photoImg)
        except:
            self.nextChain.sendToChain(mesg)

# puts any command that gets this far into a listbox
class ErrorList(Listbox, Chain):
    def __init__(self, root):
        super().__init__(root)

    def sendToChain(self, mesg: str):
        self.insert(END, mesg)

# displays any of the eight tkinter colors
# in a Frame
class ColorFrame(Frame, Chain):
    def __init__(self, root,**kwargs):
        super().__init__(root, **kwargs)
        self.root = root
        self.nextChain = None
        # set of known tkinter colors
        self.colorSet = { "white", "black", "red", "green",
                          "blue", "cyan", "yellow","magenta"}
    def sendToChain(self, mesg:str):
        # if message is one of these colors
        # display it
        if mesg in self.colorSet:
            s = tkinter.ttk.Style()
            s.configure('new.TFrame', background=mesg)
            self.configure(style='new.TFrame')
        else:
            self.nextChain.sendToChain(mesg)

# highlight any file whose name is typed in
class FileList(Listbox, Chain):
    def __init__(self, root):
        super().__init__(root)
        self.files = os.listdir('.')
        for f in self.files:
            self.insert(END, f)

    def sendToChain(self, mesg:str):
        index = 0
        found = False
        for f in self.files:
            if mesg == f.lower():
                self.selection_set(index)
                found = True
            index += 1
        if not found:
            self.nextChain.sendToChain(mesg)

# Entry field and Send button inside labelframe
class EntryChain(LabelFrame, Chain):
        def __init__(self, root):
            super().__init__(text="Enter command",
                             borderwidth=3, relief=RAISED)
            self.nextChain = None
            self.root = root
            self.entry = Entry(self)
            self.entry.pack(pady=10, padx=10)
            self.button = EntryButton(self, self)
            self.button.pack(fill=Y)
        # called when button is clicked
        def buttonClick(self):
            mesg = self.entry.get().lower().strip()
            self.entry.delete(0, END)
            self.nextChain.sendToChain(mesg)

# Builds the UI
class Builder():
    def build(self):
        root = tk.Tk()

        root.geometry("425x350")
        root.title("Chain of resp demo")
        style = Style()
        style.theme_use('alt')
    # Create the visual components
        self.imgchain = ImageChain(root, width=150, height=200)
        self.imgchain.grid(row=0, column=0)

        self.entrychain =EntryChain(root)
        self.entrychain.grid(row=1, column=0, pady=30)

        self.cframe = ColorFrame(root, width=100, height=100)
        self.cframe.grid(row=1, column=1)

        self.flistbox=FileList(root)
        self.flistbox.grid(row=0, column=1)

        self.errList = ErrorList(root)
        self.errList.grid(row=0, column=2)

    # construct the chain
        self.entrychain.addChain(self.imgchain)
        self.imgchain.addChain(self.flistbox)
        self.flistbox.addChain(self.cframe)
        self.cframe.addChain(self.errList)

        mainloop()

def main():
    Builder().build()
###  Here we go  ####
if __name__ == "__main__":
    main()