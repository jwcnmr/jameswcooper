import tkinter
from tkinter import *
from tkinter import messagebox
import sys

class ButtonFuncs():
    def __init__(self):
        pass
    def hello(self):
        messagebox.showinfo("Hi", "Hello")
    def exit(self):
        ans = messagebox.askquestion("Leaving so soon?",
                                     "Do you really want to exit")
        if ans == 'yes':
            sys.exit()


class Builder() :

    def build(self):
        root = Tk()
        root.geometry("200x100")
        bf = ButtonFuncs()
        helloButton = Button(root, text="Hello", width=8, command = bf.hello)
        helloButton.pack(side=LEFT, padx=20)
        leaveButton = Button(root, text="Leave", width=8, command =  bf.exit)
        leaveButton.pack(side=RIGHT, padx=20)
        mainloop()

def main():
   bld =Builder()
   bld.build()


if __name__ == '__main__':
    main()