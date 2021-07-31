"""Create a 2 button window using classes"""
import tkinter as tk
from tkinter import messagebox, LEFT, RIGHT
from tkinter.ttk import Button, Style



# derived class from Button that contains empty comd function



class DButton(Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        super().config(command=self.comd)

    # abstract method to be called by children
    def comd(self):
        pass


# derived from DButton with actual OK comd
class OKButton(DButton):
    def __init__(self, root):
        super().__init__(root, text="OK")
        self.pack(side=LEFT, padx=10)

    def comd(self):
        messagebox.showinfo("our message",
                            "tkinter is easy to use")


# derived from DButton calls Quit function
class QuitButton(DButton):
    def __init__(self, root):
        # also sets Quit to Red
        Style().configure("W.TButton", foreground="red")
        super().__init__(root, text="Quit",style="W.TButton")
        self.pack(side=RIGHT, padx=10)

    # calls the quit function and the program exits
    def comd(self):
        quit()


# set up the window and user interface
def buildUI():
    root = tk.Tk()  # get the window
    root.geometry("200x100+300+300")  # x, y window size and position
    root.title("pick one")
    # create Hello button
    slogan = OKButton(root)

    # create exit button with red letters
    button = QuitButton(root)

    #    start running the tkinter loop
    root.mainloop()


def main():
    buildUI()


###  Here we go  ####
if __name__ == "__main__":
    main()
