"""Create a 2 button window"""
import tkinter as tk
from tkinter import Button, messagebox, LEFT, RIGHT
#from tkinter.ttk import Button
import sys


# write slogan out in a message box
def disp_slogan():
    messagebox.showinfo("our message",
                        "tkinter is easy to use")


# set up the window
root = tk.Tk()  # get the window
root.geometry("100x100+300+300")  # x, y window size and position

# create Hello button
slogan = Button(root,
                   text="Hello",
                   command=disp_slogan)
slogan.pack(side=LEFT, padx=10)
# slogan.pack()

# create exit button with red letters
button = Button(root,
                   text="QUIT",
                   fg="red",
                   command=sys.exit)
button.pack(side=RIGHT, padx=10)

# start running the tkinter loop
root.mainloop()
