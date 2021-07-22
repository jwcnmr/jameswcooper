import tkinter as tk
from tkinter import *

def InitUI(root):
    menubar = Menu(root)
    root.config(menu=menubar)
    root.title("Menu demo")
    root.geometry("300x200")
    filemenu = Menu(menubar, tearoff=0)
    menubar.add_cascade(label="File", menu=filemenu)

    filemenu.add_command(label="New", command=None)
    filemenu.add_command(label="Open", command=None)
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=None)

    drawmenu = Menu(menubar, tearoff=0)
    menubar.add_cascade(label="Draw", menu=drawmenu)
    drawmenu.add_command(label="Circle", command=None)
    drawmenu.add_command(label="Square", command=None)

    mainloop()




def main():
    root = Tk()
    InitUI(root)

###  Here we go  ####
if __name__== "__main__":
    main()
