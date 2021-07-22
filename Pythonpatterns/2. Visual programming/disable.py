import tkinter as tk#import tkinter as tk
#from tkinter import ttk
#from tkinter.ttk import *
from tkinter import *

class Dbutton(Button):
     def __init__(self, master=None, **kwargs):
         super().__init__(master,  command=self.comd, **kwargs)

     def comd(self): pass

     def disable(self):
        try:
            self['state'] =tk.DISABLED
        except AttributeError:
             self.configure(state=tk.DISABLED)

     def enable(self):
         try:
             self['state']=[tk.NORMAL]
         except AttributeError:
             self.configure(state=tk.NORMAL)

class Mediator():
    def setSbutton(self,sbutton):
        self.sbutton=sbutton

    def setQuit(self, qbutton):
        self.qbutton = qbutton

    def sclicked(self):
        self.qbutton.enable()

class SampleButton(Dbutton):
    def __init__(self, root, med, **kwargs):
        super().__init__(root, text="Sample", **kwargs)
        self.med = med
        self.enable()
    def comd(self):
        self.med.sclicked()

class QuitButton(Dbutton):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Quit", **kwargs)
        self.disable()
    def comd(self):
        quit()


root = tk.Tk()
med = Mediator()
btn = SampleButton(root, med)

quitbutton = QuitButton(root)
med.setQuit(quitbutton)

btn.grid(column=0, row=0)
quitbutton.grid(column=1, row=0)

root.mainloop()
