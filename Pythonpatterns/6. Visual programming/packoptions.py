import tkinter as tk
from tkinter import *
from tkinter.ttk import *

"""Illustrates most of the common options for pack
Note that this works better using the ttk toolkit
Otherwise the  labels end up right justified"""
root=tk

frame1 = Frame()        #first row
frame1.pack(fill=X)     #fill all of X

lbl1 = Label(frame1, text="Name", width=7) #add a label
lbl1.pack(side=LEFT, padx=5, pady=5)    #on the left
entry1 = Entry(frame1)                  # add an entry field
entry1.pack(fill=X, padx=5, expand=True)

frame2 = Frame()        #second riw
frame2.pack(fill=X)

lbl2 = Label(frame2, text="Address", width=7) #add label
lbl2.pack(side=LEFT, padx=5, pady=5)
entry2 = Entry(frame2)                        #and entry
entry2.pack(fill=X, padx=5, expand=True)

root.mainloop()

