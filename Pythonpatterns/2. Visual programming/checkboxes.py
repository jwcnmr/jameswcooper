import tkinter as tk
from tkinter import *

# Button with comd method to print out list of toppings ordered
# keeps a reference to the list of checkboxes
class OKButton(Button):
    def __init__(self, root, boxes):
        super().__init__(root, text="Order")
        super().config(command=self.comd)
        self.boxes= boxes           #save the list of checkboxes

    #print out the list of ordered toppings
    def comd(self):
        for box in self.boxes:
            print (box.text, box.getVar())

"""Checkbox class derived from Checkbutton
includes get methods to get the name var state"""
class Checkbox(Checkbutton):
    def __init__(self, root, btext, gvar):
        super().__init__(root, text=btext, variable=gvar)
        self.text = btext
        self.var = gvar

        #Internet joke about Pineapple on pizza
        if self.text == "Pineapple":        #prevent Pineapple on pizza
            self.configure(state=DISABLED)


    def getVar(self):
        return self.var.get()   #get the value stored in this IntVar

"""Create the window, checkboxes and Order button
Also creates a list containing the checkboxes 
and passes it to the Order button"""
class InitUI():
    def __init__(self, root):
        self.names = ["Cheese","Pepperoni","Mushrooms",
                      "Sausage","Peppers","Pineapple"]
        root.title("Pizza")
        root.geometry("200x175")

        boxes=[]            # list of check boxes stored here
        r = 0
        for name in self.names:
            var=IntVar()                    # create an IntVar for each one
            cb = Checkbox(root, name, var)  # create each checkbox
            boxes.append(cb)                # and add it to the list
            cb.grid(column=0, row=r, sticky=W) # format in grid layout
            r += 1                            # row counter

        #Create the Order button and give it the list of boxes
        OKButton(root, boxes).grid(column=1, row=3, padx=20)
        mainloop()
def main():
    root = Tk()
    InitUI(root)

###  Here we go  ####
if __name__== "__main__":
    main()
