import tkinter as tk
from tkinter import *
import sys

class Builder():
    # enable quit button
    def bEnable(self):
        self.quitBut['state']=NORMAL

    # exit from program
    def exit(self):
        sys.exit()

    # construct the UI
    def build(self):
        root = tk.Tk()
        root.geometry("160x50")
        root.title("2 buttons")

        # the OK button
        self.okBut = Button(root, text="OK", command=self.bEnable)
        self.okBut.pack()

        # the quit button
        self.quitBut = Button(root, text="Quit", command=self.exit)
        self.quitBut.pack()
        # disable the quit button
        self.quitBut['state'] = DISABLED

        # wait for UI events
        mainloop()

def main():
    bld = Builder()
    bld.build()

# Program starts here
if __name__ == '__main__':
    main()


