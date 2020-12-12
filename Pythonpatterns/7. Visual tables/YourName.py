"""
Creates a window with a label, an entry field
a button and another label.
When you click on the OK button
the text of the entry field is copied into the label
along with 'Hi' and "boy'
"""

from tkinter import ttk
import tkinter as tk
from tkinter import *

class Builder():
    # gets the entry field text
    # places it on the cLabel text field
    def getName(self):
       newName = self.nmEntry.get()
       self.cLabel.configure(text="Hi "+newName+" boy!")

    def build(self):
        root = tk.Tk()
        # top label
        Label(root,
             text="""What is your name?""",
             justify=LEFT, fg='blue', pady=10, padx=20).pack()

        # create entry field
        self.nmEntry = Entry(root)
        self.nmEntry.pack()

        # OK button calls getName when clicked
        self.okButton = Button(root, text="OK", command=self.getName )
        self.okButton.pack()

        # This is the label whose text changes
        self.cLabel = Label(root, text='name', fg='blue')
        self.cLabel.pack()
        mainloop()

###  Here we go  ####
if __name__ == "__main__":
    bldr = Builder()
    bldr.build()