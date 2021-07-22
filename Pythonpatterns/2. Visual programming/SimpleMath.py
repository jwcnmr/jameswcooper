"""
Creates a window with two entry fields
a button and another label.
When you click on the OK button
the text of the two entry field are converted to floats and added
The sum is placed in the lower label
"""

from tkinter import ttk, messagebox
import tkinter as tk
from tkinter import *

class Builder():
    # gets the two entry fields, converts them to floats
    # places their sum in the cLabel text field
    # if either field is not a number
    # am exception occurs
    def getSum(self):
        try:
            xval= float(self.xEntry.get())
            yval = float(self.yEntry.get())
            self.cLabel.configure(text="Sum = "+str(xval+yval))
        except:
            messagebox.showerror("Conversion error", "Not numbers")

    # build the window interface
    def build(self):
        root = tk.Tk()
        root.geometry("350x200")
        # top label
        Label(root,
             text="""Enter numbers to add""",
                justify=LEFT, fg='blue', pady=10, padx=20).\
                grid(row=0, column=0, columnspan=2)

        # create entry fields
        Label(text="x=", fg='blue').grid(row=1,column=0)
        self.xEntry = Entry(root)
        self.xEntry.grid(row=1,column=1, padx=10)

        Label(text="y=", fg='blue').grid(row=2, column=0)
        self.yEntry = Entry(root)
        self.yEntry.grid(row=2, column=1, padx=10)

        # OK button calls getSum when clicked
        self.okButton = Button(root, text="OK", command=self.getSum )
        self.okButton.grid(row=3,column=0, columnspan=2)

        # This is the label whose text changes
        self.cLabel = Label(root, text='sum', fg='blue')
        self.cLabel.grid(row=4, column=0, columnspan=2)
        mainloop()

###  Here we go  ####
if __name__ == "__main__":
    bldr = Builder()
    bldr.build()