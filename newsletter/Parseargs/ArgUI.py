import tkinter
from tkinter import *
from tkinter import filedialog
import sys, os
import ntpath

# creates the menu bar
class Menubar(Menu):
    def __init__(self, root):
        super().__init__(root)
        root.config(menu=self)

# this class represents the top menu item in each column
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
       fname = ""
       if len(sys.argv) >1: #get arg from command line
           fname = sys.argv[1]
       if not os.path.exists(fname): # if it doesn't exist call Open
           fname= filedialog.askopenfilename( title="Select file")

    # display stripped filename in title bar
       sname = ntpath.basename(fname)
       self.root.title(sname)


class Builder():

    def build(self):
        root=Tk()
        root.title("Menu demo")
        root.geometry("200x100")
        menubar = Menubar(root)

        # create the File menu and its child
        filemenu = TopMenu(root, "File", menubar)
        filemenu.addMenuitem(Opencommand(root, "Open"))
        mainloop()

def main():
    bld = Builder()
    bld.build()

    ###  Here we go  ####
if __name__ == "__main__":
    main()