# Create calculator interface with tkinter

import tkinter as tk
from tkinter import *
from tkinter import font as tkFont  # for convenience

class Numentry():
    def __init__(self, string, sign):
        self.numval = float(string)
        self.sign = sign

class Mediator():
    def __init__(self, label):
        self.tlabel = label
        self.first = True
        self.noDot = True
        self.array = []

    # convenience methods
    def getLabelText(self):
        return self.tlabel['text']
    def setlabelText(self, string):
        self.tlabel['text'] = string

    def addClicked(self, sign):
        val=Numentry(self.getLabelText(), sign)
        self.array.append(val)
        self.first = True

    # reduce stack and computer result
    def equalsClicked(self):

        funcs = {"+": self.addfun,
                 "-": self.subfun,
                 "*": self.multfun,
                 "/": self.divfun}
        sym = Numentry(self.getLabelText(), "+")
        self.array.append(sym)
        evstring = ""
        for val in self.array:
            evstring += str(val.numval)
            evstring += val.sign
        evstring = evstring[0:len(evstring)-1]
        print(evstring)
        """
        self.stack=[]
        while len(self.array) >0:
            self.stack.append(self.array.pop())
        while len(self.stack) > 1:
            val = self.stack.pop()
            num = self.stack.pop()
            sign = val.sign
            self.stack.append(num.numval)
            self.stack.append(val.numval)
            func = funcs.get(sign)
            sum = func()
            newsym = Numentry(sum, sign)
            self.stack.append(newsym)

        sym = self.stack[-1]
        self.setlabelText(str(sym.numval))
        self.array.append(sym)"""
        sum = eval(evstring)
        self.setlabelText(sum)
        self.array = []


    # Any number is clicked
    def numClick(self, text):
        if self.first: # if first char clear the zero
            self.setlabelText(" ") # leading space
            self.first = False
        st = self.getLabelText() + text
        self.setlabelText(st)

    # the decimal point is clicked
    def dotClicked(self):
        if self.noDot:  # prevent multiple dots
            self.numClick(".")
            self.noDot = False

    # change sign by replacing first character
    # it is either a space or a minus sign
    def chgSign(self):
        lbstring = self.getLabelText()
        sign = lbstring[0:1]    # get first char

        if sign == "-":
            sign = " "
        else:
            sign = "-"
        lbstring = sign + lbstring[1:] # append new sign to rest
        self.setlabelText(lbstring)

    def clearEntryClick(self):
        self.setlabelText(" 0")
        self.first = True
        self.noDot = True

    def clearAllClick(self):
        self.clearEntryClick()
        self.array=[]

    def addfun(self):
        return self.stack.pop() + self.stack.pop()
    def subfun(self):
        return self.stack.pop() - self.stack.pop()
    def multfun(self):
        return self.stack.pop() * self.stack.pop()
    def divfun(self):
        return self.stack.pop() / self.stack.pop()


# abstract class defines command interface
class DButton (Button):
    def __init__(self, master, **kwargs):
        super().__init__(master, command=self.comd, **kwargs)
    def comd(self):
        pass

class TopLabel(Label):
    def __init__(self, master, **kwargs):
        super().__init__(master, width=10, anchor='e', **kwargs)
        butfont = tkFont.Font(family='Helvetica',  size=12)
        self['font'] = butfont

class NumButton(DButton):
    def __init__(self, master, med, **kwargs):
        super().__init__(master, width=2, fg='white', bg="#aaa", **kwargs)
        butfont = tkFont.Font(family='Helvetica', size=16, weight='bold')
        self['font'] = butfont
        self.med= med
    def comd(self):
        self.med.numClick(self['text'])

class ZeroButton(NumButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=5, text='0')

class CEButton(NumButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        butfont = tkFont.Font(family='Helvetica', size=12)
        self['font'] = butfont
        self.config(width=3, text='CE', bg="#a00")
    def comd(self):
        self.med.clearEntryClick()

class ClrButton(CEButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=3, text='C', bg="#c40")
    def comd(self):
        self.med.clearAllClick()

class SignButton(CEButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=3, text='+/-', bg="#c40")
    def comd(self):
        self.med.chgSign()

class DivButton(CEButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=3, text='/', bg="#a40")

# all 4 op buttons use the some command
class MultButton(CEButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        butfont = tkFont.Font(family='Helvetica', size=16, weight='bold')
        self['font'] = butfont
        self.config(width=2, text='*', bg="#a40")
    def comd(self):
        self.med.addClicked(self['text'])

class MinusButton(MultButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=2, text='-', bg="#a40")

class PlusButton(MultButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=2, text='+', bg="#a40")

class DotButton(NumButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(text='.')
    def comd(self):
        self.med.dotClicked()

class EqualsButton(MultButton):
    def __init__(self, med, master, **kwargs):
        super().__init__(med, master, **kwargs)
        self.config(width=2, text='=', bg="#2a2")
    def comd(self):
        self.med.equalsClicked()


class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("152x250")
        root.title("Calculator")
        root.configure(bg="#449")

        topLabel = TopLabel(root, text=" 0")
        topLabel.grid(row=0, column=0, columnspan=4,pady=4,padx=1)

        med =Mediator(topLabel)

        but = CEButton(root, med)
        but.grid(row=1, column=0)

        but = ClrButton(root, med)
        but.grid(row=1, column=1)

        but = SignButton(root, med)
        but.grid(row=1, column=2)

        but = DivButton(root, med)
        but.grid(row=1, column=3)

        but = MultButton(root, med)
        but.grid(row=2, column = 3)

        but = MinusButton(root, med)
        but.grid(row=3, column=3)

        but = PlusButton(root, med)
        but.grid(row=4, column=3)

        but = NumButton(root, med, text='7')
        but.grid(row=2, column=0, padx=1, pady=1)
        but = NumButton(root, med, text='8')
        but.grid(row=2, column=1, padx=1, pady=1)
        but = NumButton(root, med, text='9')
        but.grid(row=2, column=2, padx=1, pady=1)

        but = NumButton(root, med, text='4')
        but.grid(row=3, column=0, padx=1, pady=1)
        but = NumButton(root, med, text='5')
        but.grid(row=3, column=1, padx=1, pady=1)
        but = NumButton(root, med, text='6')
        but.grid(row=3, column=2, padx=1, pady=1)

        but = NumButton(root, med, text='1')
        but.grid(row=4, column=0, padx=1, pady=1)
        but = NumButton(root, med, text='2')
        but.grid(row=4, column=1, padx=1, pady=1)
        but = NumButton(root, med, text='3')
        but.grid(row=4, column=2, padx=1, pady=1)

        but = ZeroButton(root, med)
        but.grid(row=5, column=0, columnspan=2, padx=1, pady=1)

        but = DotButton(root, med)
        but.grid(row=5, column=2, padx=1, pady=1)

        but = EqualsButton(root, med)
        but.grid(row=5, column=3, padx=1, pady=1)



        mainloop()


##  Here we go  ####
if __name__ == "__main__":
    bld = Builder()
    bld.build()
