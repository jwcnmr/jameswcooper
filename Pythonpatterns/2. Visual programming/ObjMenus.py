"""Creates a window and uses objects to create the menubar
and the menu items, to preserve information encapsulation.
Each menu item contains its own comd action method
 """

import tkinter as tk
from tkinter import filedialog
from tkinter import *

# creates the menu bar
class Menubar(Menu):
    def __init__(self, root):
        super().__init__(root)
        root.config(menu=self)

   # def get(self):
    #    return self.menubar

# abstract base class for menu items
class Menucommand():
    def __init__(self, root, label):
        self.root = root
        self.label=label
    def getLabel(self):
        return self.label
    def comd(self): pass

# menu item that calls the file open dialog
class Opencommand(Menucommand):
    def __init__(self, root, label):
        super().__init__(root, label)
    def comd(self):
       fname= filedialog.askopenfilename( title="Select file")
       # check for nonzero string length
       if len(fname.strip()) > 0:
           nameparts = fname.split("/")
           # find the base file name without the path
           k = len(nameparts)
           if k>0 :
               fname = nameparts[k-1]
           self.root.title(fname)

# exits from the program
class Quitcommand(Menucommand):
    def __init__(self, root,  label):
        super().__init__(root,  label)
    def comd(self):
        sys.exit()

# draws a circle
class Drawcircle(Menucommand):
    def __init__(self, root,  canvas, label):
        super().__init__(root,  label)
        self.canvas = canvas
    def comd(self):
        self.canvas.create_oval(130, 40,
                200, 110, fill="red")

#draws a square
class Drawsquare(Menucommand):
    def __init__(self, root,  canvas, label):
        super().__init__(root,  label)
        self.canvas = canvas
    def comd(self):
        self.canvas.create_rectangle(10, 80, 110, 180, fill="blue")

#this class represents the top menu item in each column
class TopMenu():
    def __init__(self, root, label, menubar):
        self.mb = menubar
        self.root = root
        self.fmenu = Menu(self.mb, tearoff=0)
        self.mb.add_cascade(label=label, menu=self.fmenu)

    def addMenuitem(self, mcomd):
        self.fmenu.add_command(label = mcomd.getLabel(),
                    command = mcomd.comd)

    def addSeparator(self):
        self.fmenu.add_separator()

# create the window and the menu items
def InitUI(root):
    root.title("Menu demo")
    root.geometry("300x200")
    canvas = Canvas(root)
    canvas.pack()
    # create the menu bar
   # menubar = Menubar(root).get()
    menubar = Menubar(root)

    #create the File menu and its children
    filemenu = TopMenu(root, "File", menubar)
    filemenu.addMenuitem(Menucommand(root, "New"))
    filemenu.addMenuitem(Opencommand(root, "Open"))
    filemenu.addSeparator()
    filemenu.addMenuitem(Quitcommand(root, "Quit"))

    # create the Draw menu and its children
    drawmenu= TopMenu(root, "Draw", menubar)
    drawmenu.addMenuitem(Drawcircle(root, canvas, "Circle"))
    drawmenu.addMenuitem(Drawsquare(root, canvas, "Square"))

# program starts here
def main():
    root = tk.Tk()
    InitUI(root)    #builds the window and menus
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()
