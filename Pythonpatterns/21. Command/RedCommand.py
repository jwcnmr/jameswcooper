"""Illustrates the Command interface and pattern on
menu and button objects"""

import tkinter as tk
from tkinter import *
from tkinter import *
from tkinter.filedialog import askopenfile


# Command interface
class Command():
    def comd(self):pass

# abstract button class with Command interface
class DButton(Button, Command):
    def __init__(self, master,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)
    def comd(self):pass

# Button creates a red background
class RedButton(DButton):
    def __init__(self, root):
        super().__init__(root, text="Red")
        self.root = root
    def comd(self):
        self.root.configure(bg='red')

# exit menu
class Exititem(Command):
    def __init__(self, fmenu):
        fmenu.add_command(label="Exit", command=self.comd)
    def comd(self):
        sys.exit()

# Save menu
class SaveMenu(Command):
    def __init__(self, fmenu):
        fmenu.add_command(label="Save", command = self.comd)
    def comd(self):
        print("Saving")  # just prints out a message

# the Open menu
class Openitem(Command):
    def __init__(self,fmenu):
        fmenu.add_command(label="Open", command=self.comd)
    def comd(self):
        file = askopenfile(mode='r')

# builds the UI
class Builder():
    def build(self):
        root = Tk()
        root.geometry("150x100")
        root.title("Command demo")

        menubar:Menu = Menu(root)
        root.config(menu=menubar)
        filemenu = Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=filemenu)
        fileitem = Openitem(filemenu)
        svmn = SaveMenu(filemenu)
        exititem = Exititem(filemenu)

        rbutton = RedButton(root)
        rbutton.pack(pady=10)

        mainloop()
#----------------------------
def main():
    Builder().build()

###  Here we go  ####
if __name__ == "__main__":
    main()