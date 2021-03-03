"""Create a 2 button window"""
import tkinter as tk
from tkinter import *
from tkinter import messagebox

class Builder():
    # write slogan out in a message box
    def disp_slogan(self):
        messagebox.showinfo("our message",
                            "tkinter is easy to use")
    def build(self):
        # Get the arguments
        leftText= sys.argv[1]
        rightText = sys.argv[2]
        bcolor = sys.argv[3]

        # set up the window
        root = tk.Tk()  # get the window
        root.geometry("100x100+300+300")  # x, y window size and position

        # create Hello button
        slogan = tk.Button(root,
                           text=leftText,
                           command=self.disp_slogan)
        slogan.pack(side=LEFT, padx=10)

        self.colorSet = {"white", "black", "red", "green",
                         "blue", "cyan", "yellow", "magenta"}
        if bcolor in self.colorSet:
            newColor = bcolor   # legal color
        else:
            newColor = '#c0f'    #default color purple
        # create exit button with colored letters
        button = tk.Button(root,
                           text=rightText,
                           fg=newColor,
                           command=sys.exit)
        button.pack(side=RIGHT, padx=10)

# ----------------------------
def main():
    Builder().build()
    mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()