import tkinter as tk
from tkinter import *
from tkinter import messagebox

# derived button
# with simplified enable and disable methods

class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, width=6, command= self.comd, **kwargs)

    def enable(self):
        self['state'] = NORMAL

    def disable(self):
        self['state'] = DISABLED

    def comd(self): pass

class Mediator():
    def setFields(self, xentry, yentry):
        self.xEntry = xentry
        self.yEntry = yentry

    def setLabels(self, top, bottom):
        self.topLabel = top
        self.botLabel = bottom

    def addClicked(self):
        try:
            xval = float(self.xEntry.get())
            yval = float(self.yEntry.get())
            self.botLabel.configure(text="Sum = " + str(xval + yval))
        except ValueError:
            messagebox.showerror("Conversion error",
                                 "Not numbers")

# Button displays OK
class AddButton(DButton):
    def __init__(self, master, med, **kwargs):
        super().__init__(master, text="Add", **kwargs)
        self.med = med
    def comd(self):
        self.med.addClicked()

class BlueLabel(Label):
    def __init__(self,root,  lbtext, **kwargs):
        super().__init__(root,text=lbtext, justify=LEFT,  fg='blue' )

class Builder():
    def build(self):
        root = tk.Tk()
        topLabel = BlueLabel(root, "Enter 2 values:")
        topLabel.grid(row=0, column=0, columnspan=2)

        # create entry field
        xlabel = BlueLabel(root, "Num1:").grid(row=1, column=0)
        xEntry = Entry(root)
        xEntry.grid(row=1, column=1, padx=10)  # and put it into the window

        ylabel = BlueLabel(root, "Num2:").grid(row=2, column=0)
        yEntry = Entry(root)
        yEntry.grid(row=2, column=1, padx=10, pady=10)  # and put it into the window

        med = Mediator()
        # OK button calls getName when clicked
        self.addButton = AddButton(root, med)
        self.addButton.grid(row=3, column=0, columnspan=2)

 # This is the label whose text changes
        botLabel = BlueLabel(root, 'Sum')
        botLabel.grid(row=4, column=0, columnspan=2)
        med.setLabels(topLabel, botLabel)
        med.setFields(xEntry, yEntry)
        mainloop()

def main():
    bld = Builder()
    bld.build()

# starts here
if __name__ == '__main__':
    main()