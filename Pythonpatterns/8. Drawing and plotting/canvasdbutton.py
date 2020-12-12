
from tkinter import *
#import tkinter as tk

class DButton(Button):
    def __init__(self, canv, rect, master=None,  **kwargs):
        super().__init__(master, kwargs)
        super().config(command=self.move, text="Move") 
        self.canv=canv
        self.rect=rect
        
    def move(self):
        x1,y1,x2,y2 = self.canv.coords(self.rect)  #returns a tuple
        x1+=10  #move both x's by 10 pixels
        x2+=10
        self.canv.coords(self.rect,x1,y1,x2,y2)  #and move the figure
    
def main():
    root = Tk()
    canv= Canvas(root, width=300, height=200)
    canv.pack()
    x1=20       #rectagle coordinates
    x2=100
    y1=40
    y2=150
    #create rectangle and oval
    rect = canv.create_rectangle(x1,y1,x2,y2, fill="blue")
    canv.create_oval(130, 40, 200,150, fill="red")
    canv.tag_raise(rect)
    #create a Move button
    button1 = DButton(canv, rect)
 
    #canv.create_window(140,175, window=button1)
    button1.pack()
    #button1.config(command = lambda: move(canv, rect))

    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()

