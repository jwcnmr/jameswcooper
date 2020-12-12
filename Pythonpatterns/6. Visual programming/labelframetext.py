import tkinter as tk
from tkinter import *

import tkinter.ttk as ttk
from tkinter.ttk import *


# main begins here
def main():
    root = tk.Tk()
    root.geometry("100x250")
    # style required if used on Windows 10
    style = Style()
    style.theme_use('alt')
    
    # create LabelFrame
    labelframe = LabelFrame(root, text="State data",
                            borderwidth=7, relief=RAISED)
    labelframe.pack(pady=5)

    # add 4 labels
    Label(labelframe, text="State").pack()
    Label(labelframe, text="Abbrev").pack()
    Label(labelframe, text="Capital").pack()
    Label(labelframe, text="Founded").pack()

    mainloop()


###  Here we go  ####
if __name__ == "__main__":
    main()


