import tkinter as tk
from tkinter import messagebox, filedialog

messagebox.showwarning("Warning", "file not found")
messagebox.showerror("Error", "Division by zero")
result = messagebox.askokcancel("Continue", "Go on?")
result= messagebox.askyesnocancel("Really", "Want to go on?")

# open a single file
fname = filedialog.askopenfilename(defaultextension="*.csv")
print(fname)

# select several files -returns a tuple
fnames = filedialog.askopenfilenames(defaultextension="*.py")
print(fnames)