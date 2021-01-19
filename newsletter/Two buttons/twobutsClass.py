import tkinter as tk
from tkinter import *
import sys

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

# Mediator handles button interactions
class Mediator():
    # save buttons
    def setButtons(self,okbut, quitbut):
        self.qbutton = quitbut
        self.okbut =  okbut

    def OKClicked(self): # Ok button clicked
        self.qbutton.enable()

    def quitClicked(self): # Quit button clicked
        sys.exit()

# Button displays OK
class OKButton(DButton):
    def __init__(self, master, med, **kwargs):
        super().__init__(master, text="OK", **kwargs)
        self.med = med
    def comd(self):
        self.med.OKClicked()

# Button displays Quit
class QuitButton(DButton):
    def __init__(self, master,med, **kwargs):
        super().__init__(master, text="Quit", **kwargs)
        self.med = med
    def comd(self):
        self.med.quitClicked()

# build the UI
class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("152x50")
        root.title("2 buttons")
        self.med = Mediator()   # create the Mediator

        # create the OK button
        self.okBut = OKButton(root, self.med)
        self.okBut.pack(side=LEFT, padx=10)

        # create the Quit button
        self.quitBut = QuitButton(root, self.med )
        self.quitBut.pack(side=RIGHT, padx=10)
        self.quitBut.disable()

        # tell the Mediator about the buttons
        self.med.setButtons(self.okBut, self.quitBut)

        mainloop()

def main():
    bld = Builder()
    bld.build()

# starts here
if __name__ == '__main__':
    main()
