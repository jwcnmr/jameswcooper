import tkinter
from tkinter import *
from tkinter import messagebox
import sys


class Builder() :

    def build(self):
        root = Tk()
        root.geometry("200x100")
        root.title("Basic buttons")

        helloButton = Button(root, text="Hello", width=8)
        helloButton.pack(side=LEFT, padx=20)
        leaveButton = Button(root, text="Leave", width=8)
        leaveButton.pack(side=RIGHT, padx=20)
        mainloop()

def main():
   bld =Builder()
   bld.build()


if __name__ == '__main__':
    main()