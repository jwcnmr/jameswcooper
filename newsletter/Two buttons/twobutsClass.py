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

class Mediator():
    def setButtons(self,okbut, quitbut):
        self.qbutton = quitbut
        self.okbut =  okbut

    def OKClicked(self):
        self.qbutton.enable()


class OKButton(DButton):
    def __init__(self, master, med, **kwargs):
        super().__init__(master, text="OK", **kwargs)
        self.med = med
    def comd(self):
        self.med.OKClicked()

class QuitButton(DButton):
    def __init__(self, master, **kwargs):
        super().__init__(master, text="Quit", **kwargs)
    def comd(self):
        sys.exit()


class Builder():
    def bEnable(self):
        self.quitBut['state']=NORMAL

    def exit(self):
        sys.exit()

    def build(self):
        root = tk.Tk()
        root.geometry("152x50")
        root.title("2 buttons")
        self.med = Mediator()

        self.okBut = OKButton(root, self.med)
        self.okBut.pack(side=LEFT, padx=10)

        self.quitBut = QuitButton(root )
        self.quitBut.pack(side=RIGHT, padx=10)
        self.quitBut.disable()

        self.med.setButtons(self.okBut, self.quitBut)

        mainloop()

def main():
    bld = Builder()
    bld.build()

# starts here
if __name__ == '__main__':
    main()
