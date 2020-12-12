import tkinter as tk
from tkinter import *
from tkinter import messagebox

messagebox.showwarning("Warning", "file not found")
messagebox.showerror("Error", "Division by zero")
result = messagebox.askokcancel("Continue", "Go on?")
result= messagebox.askyesnocancel("Really", "Want to go on?")