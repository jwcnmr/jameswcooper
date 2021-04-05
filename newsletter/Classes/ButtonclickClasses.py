
from tkinter import *
from tkinter import messagebox
import sys

class HelloButton(Button):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Hello",
                         command = self.comd, **kwargs)
    def comd(self):
        messagebox.showinfo("Hi", "Hello")

class LeaveButton(Button):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Leave",
                         command = self.comd, **kwargs)

    def comd(self):
        ans = messagebox.askquestion("Leaving so soon?",
                                     "Do you really want to exit")
        if ans == 'yes':
            sys.exit()


class Builder() :

    def build(self):
        root = Tk()
        root.geometry("200x100")

        helloButton = HelloButton(root,  width=8)
        helloButton.pack(side=LEFT, padx=20)
        leaveButton = LeaveButton(root,  width=8)
        leaveButton.pack(side=RIGHT, padx=20)
        mainloop()

def main():
   bld =Builder()
   bld.build()

if __name__ == '__main__':
    main()

