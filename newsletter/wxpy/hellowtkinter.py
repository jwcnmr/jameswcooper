import tkinter as tk
from tkinter import *

root = tk.Tk()
root.geometry('100x100')
topLabel = Label(root, text= 'Hello World')
topLabel.grid(row=0, column=0, columnspan=2)

root.mainloop()