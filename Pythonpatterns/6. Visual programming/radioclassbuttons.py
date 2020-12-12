from tkinter import ttk
import tkinter as tk
from tkinter import *

# ----------------------------------------
# ChoiceButton is derived from RadioButton
class ChoiceButton(tk.Radiobutton):
    gvar = None  # the group var will go here

    def __init__(self, rt, color, index, cLabel):
        super().__init__(rt, text=color,
                         padx=20, command=self.comd,
                         variable=ChoiceButton.gvar,
                         value=index)
        self.pack(anchor=W)
        self.color = color   #button color name
        self.cLabel = cLabel #label to be colored
        self.index = index   # index of button

    # clicks are sent here
    def comd(self):
        #set the label text and color
        self.cLabel.configure(fg=self.color, text=self.color)
# ------------------
# main begins here
def main():
    root = tk.Tk()
    tk.Label(root,
             text="""Choose your favourite color:""",
             justify=LEFT,
             padx=20).pack()

    cLabel = Label(root, text='color')
    # set the group variable inside the class
    ChoiceButton.gvar = IntVar()
    ChoiceButton.gvar.set(None)
    ChoiceButton(root, 'Red',   0, cLabel)
    ChoiceButton(root, 'Blue',  1, cLabel)
    ChoiceButton(root, 'Green', 2, cLabel)

    cLabel.pack()
    mainloop()


###  Here we go  ####
if __name__ == "__main__":
    main()
