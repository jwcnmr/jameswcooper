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

class ChoiceButton(Radiobutton):
    gvar = None  # will be set to an IntVar

    def __init__(self, rt, med, label, index):
        super().__init__(rt, text = label,
                         variable =ChoiceButton.gvar,
                         value=index, fg='blue',
                         command = lambda: med.optClicked(self.text),
                         font=(None, 15))

        self.text = label
        self.index = index
        self.med = med

class Mediator():
    def __init__(self):
         self.optval="+"

         # dictionary of functions
         self.funcs = {
             '+': lambda a,b: a + b,
             '-': lambda a,b: a - b,
             '*': lambda a,b: a * b,
             '/': lambda a,b: a / b
         }

    # save fields
    def setFields(self, xentry, yentry):
        self.xEntry = xentry
        self.yEntry = yentry

    # save the text of the operator
    def optClicked(self, text):
        self.optval = text

    # save the labels
    def setLabels(self, top, bottom):
        self.topLabel = top
        self.botLabel = bottom

    def calcClicked(self):
        try:
            xval = float(self.xEntry.get())
            yval = float(self.yEntry.get())
            # get the function from the funcs dictionary
            func = self.funcs.get(self.optval)
            answer=  str(func(xval, yval))  #evaluate the function

            # call that function
            self.botLabel.configure(text="res = "
                                + answer)
        except ValueError:
            messagebox.showerror("Conversion error",
                                 "Not numbers")
        except ZeroDivisionError:
            self.botLabel.configure(text="None")


# Button displays OK
class CalcButton(DButton):
    def __init__(self, master, med, **kwargs):
        super().__init__(master, text="Calc", **kwargs)
        self.med = med
    def comd(self):
        self.med.calcClicked()

class BlueLabel(Label):
    def __init__(self,root,  lbtext, **kwargs):
        super().__init__(root,text=lbtext, justify=LEFT,  fg='blue' )

class Builder():
    def build(self):
        root = tk.Tk()
        topLabel = BlueLabel(root, "Enter 2 values:")
        topLabel.grid(row=0, column=0, columnspan=4)

        # create entry field
        xlabel = BlueLabel(root, "Num1:").grid(row=1, column=0)
        xEntry = Entry(root)
        xEntry.grid(row=1, column=1, columnspan=3, padx=10)  # and put it into the window

        ylabel = BlueLabel(root, "Num2:").grid(row=2, column=0)
        yEntry = Entry(root)
        yEntry.grid(row=2, column=1, columnspan=3,padx=10, pady=10)  # and put it into the window

        med = Mediator()
        ChoiceButton.gvar = IntVar()
        ChoiceButton.gvar.set(0)

        cbutton = ChoiceButton(root, med, '+', 0)
        cbutton.grid(row=3, column=0)
        cbutton = ChoiceButton(root, med, '-', 1)
        cbutton.grid(row=3, column=1)
        cbutton = ChoiceButton(root, med, '*', 2)
        cbutton.grid(row=3, column=2)
        cbutton = ChoiceButton(root, med, '/', 3)
        cbutton.grid(row=3, column=3)

        # OK button calls getName when clicked
        self.addButton = CalcButton(root, med)
        self.addButton.grid(row=4, column=1, columnspan=2)

 # This is the label whose text changes
        botLabel = BlueLabel(root, 'Sum')
        botLabel.grid(row=5, column=0, columnspan=4)
        med.setLabels(topLabel, botLabel)
        med.setFields(xEntry, yEntry)
        mainloop()

def main():
    bld = Builder()
    bld.build()

# starts here
if __name__ == '__main__':
    main()