import tkinter as tk
from tkinter import *
from tkinter.ttk import *

"""Illustrates most of the common options for grid
"""
root=Tk()
root.title("grid")
#lbl1 = Label( text="Name", width=7)
lbl1 = Label( text="Name")
lbl1.grid(row=0, column=0, padx=5, pady=5, sticky=W)
#lbl1.grid(row=0, column=0, padx=5, pady=5)
entry1 = Entry()
entry1.grid(row=0, column=1)

#lbl2 = Label( text="Address", width=7)
lbl2 = Label( text="Address")
#lbl2.grid(row=1, column=0, padx=5, pady=5)
lbl2.grid(row=1, column=0, padx=5, pady=5, sticky=W)
entry2 = Entry()
entry2.grid(row=1, column=1, padx=5)

root.mainloop()

