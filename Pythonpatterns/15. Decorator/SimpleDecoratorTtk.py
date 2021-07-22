"""Decorator example using Ttk classes
You have to use the 'alt' theme to make this work
Hovering over a flat button makes it into a raised one.
The Quit button is not affected"""
from tkinter import ttk
from tkinter import *
from tkinter.ttk import *

class HButton(Button):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        self.BTstyle =  ttk.Style()
        self.BTstyle.configure("Flat.TButton",  relief=FLAT)
        self.BTstyle.theme_use("alt")

        self.Rstyle = ttk.Style()
        self.Rstyle.configure("Raise.TButton", relief=RAISED)
        self.Rstyle.theme_use("alt")

        self.configure(style="Flat.TButton")
        self.bind("<Enter>", self.on_enter)
        self.bind("<Leave>", self.on_leave)

    def on_enter(self, evt):
        self.configure(style="Raise.TButton")

    def on_leave(self, evt):
        self.configure(style="Flat.TButton")


class CButton(HButton):
    def __init__(self, master, **kwargs):
        super().__init__(master, text="C Button")
        self.config(style="Flat.TButton")

class DButton(HButton):
    def __init__(self, master, **kwargs):
        super().__init__(master, text="D Button")
        self.configure(style="Flat.TButton")

class Builder():
    def build(self):
        root = Tk()
        root.geometry("300x150")
        root.title("Ttk Buttons")
        cbut = CButton(root)
        dbut = DButton(root)
        qbut = Button(root, text="Quit", command=quit)
        cbut.pack(pady=3)
        dbut.pack(pady=3)
        qbut.pack()


#----------------------------------
def main():
    Builder().build()
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()