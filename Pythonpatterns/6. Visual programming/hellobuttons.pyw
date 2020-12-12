"""Create a 2 button window"""
import tkinter as tk
from tkinter import *
from tkinter import messagebox
    
#write slogan out in a message box
def write_slogan():
    messagebox.showinfo("our message",
                        "tkinter is easy to use")

#set up the window
root = tk.Tk()              #get the window
root.geometry("100x100+300+300")    #x, y window size and position

#create Hello button
slogan = tk.Button(root,
                   text="Hello",
                   command=write_slogan)
slogan.pack(side=LEFT, padx=10)
#slogan.pack()

#create exit button with red letters
button = tk.Button(root, 
                   text="QUIT", 
                   fg="red", 
                   command=quit)
button.pack(side=RIGHT, padx=10)
#button.pack()

#start running the tkinter loop
root.mainloop()