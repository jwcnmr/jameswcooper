"""Decorator demo using Tkinter widgets
Clicking on the C Button decorates the D Button with an image
of a red line.  Clicking on the D button restores the text"""
from tkinter import *

# Derived Button is abstract class for comd
class ComdButton(Button):
    def __init__(self, master,  **kwargs):
        super().__init__(master, **kwargs)
        self.configure(relief=RAISED, command=self.comd)
    def comd(self):
        pass

# one button. Clicking on it makes the D button display an image
class CButton(ComdButton):
    def __init__(self, master, dbut, **kwargs):
        super().__init__(master, text="C Button")
        self.button = dbut

    def comd(self):
        self.button.loadImage()

# Image displyed on this button when C button is clicked.
# Clicking on this button restores the text
class DButton(ComdButton):
    def __init__(self, master, **kwargs):
        super().__init__(master, text="D Button")

   # load the image from a file and put on button
    def loadImage(self):
        self.imagePng = \
            PhotoImage(file="redline.png")
        self.config(image=self.imagePng,
                    compound=None, width="50", height="18")
        self.config(text="")

    def comd(self):
        #  remove the image
        self.imagePng.blank()
        self.config(text="D button")
        self.config(image=None, compound=CENTER)

# creates the user interface
class Builder():
    def build(self):
        root = Tk()
        root.geometry("200x100")
        root.title("Deco buttons")
        #create two decorated buttons and one normal one

        dbut = DButton(root)
        cbut = CButton(root, dbut)

        qbut = Button(root, text="Quit", command=quit)
        cbut.pack( pady=3)
        dbut.pack( pady=3)

        qbut.pack()


#----------------------------------
def main():
    Builder().build()
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()