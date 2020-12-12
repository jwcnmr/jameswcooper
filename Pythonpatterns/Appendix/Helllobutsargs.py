"""Create a 2 button window"""
import tkinter as tk
from tkinter import *
from tkinter import messagebox




class Builder():
    # write slogan out in a message box
    def write_slogan():
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
                           command=self.write_slogan)
        slogan.pack(side=LEFT, padx=10)
        # slogan.pack()

        # create exit button with colored letters
        button = tk.Button(root,
                           text=rightText,
                           fg=bcolor,
                           command=sys.exit)
        button.pack(side=RIGHT, padx=10)




# ----------------------------
def main():
    Builder().build()
    mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()