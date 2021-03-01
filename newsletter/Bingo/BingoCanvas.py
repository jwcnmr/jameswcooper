import random

import tkinter as tk
from tkinter import *

class BingoCol():
    def __init__(self, name, min, max):
        self.name = name
        bset=set()
        while len(bset) < 5:
            i = random.randint(min,max)
            bset.add(i)
        self.bara = list(bset)
        random.shuffle(self.bara)

    def getRowval(self, i):
         return str(self.bara[i])

class NBingoCol(BingoCol):
    def __init__(self, name, min,max):
        super().__init__(name,min,max)
    def getRowval(self, i):
        if(i==2):
            return "Free"
        else:
            return str(self.bara[i])

class Builder():

    def drawGrid(self):
        # convenient constants
        EDGE=10
        x = y = EDGE
        WIDTH = 50
        # draw grid lines
        for i in range(0,7):
            self.canvas.create_line(x, y, x+5*WIDTH, y, fill='black')
            y=y+WIDTH
        self.canvas.update()
        x = y = EDGE
        for i in range(0,6):
            self.canvas.create_line(x, y, x, y+6*WIDTH, fill='black')
            x += WIDTH

        # put Text labels in top row
        x = y = EDGE+WIDTH/2
        for r in self.cols:
            self.canvas.create_text(x, y, fill="darkblue",
                                font="Times 20 italic bold",
                                text=r.name)
            x += WIDTH

        # fill in numbers
        x = EDGE+WIDTH/2
        y = EDGE+WIDTH+WIDTH/2
        for i in range(0, 5):
            for r in self.cols:
                self.canvas.create_text(x, y, fill="black",
                                        font="Times 20",
                                        text=r.getRowval(i))
                x += WIDTH
            x = EDGE + WIDTH / 2
            y = EDGE + (i+2)*WIDTH + WIDTH / 2
        # create a light blue rectangle
        rect=self.canvas.create_rectangle(EDGE,EDGE,5*WIDTH+EDGE,
                                          WIDTH+EDGE, fill='lightblue')
        # and put the rectangle behind the text
        self.canvas.tag_lower(rect)
        self.canvas.update()


# create column objects and draw the matrix
    def build(self):
        root = tk.Tk()
        root.geometry("280x350")
        root.title("Bingo")
        self.canvas = Canvas(root, width=400, height=420)
        self.canvas.pack()

        # create an array of 5 Bingo column objects with names
        self.cols = []
        self.cols.append(BingoCol("B", 1, 15))
        self.cols.append(BingoCol("I", 16, 30))
        self.cols.append(NBingoCol("N", 31, 45))
        self.cols.append(BingoCol("G", 46, 60))
        self.cols.append(BingoCol("O", 61, 75))
        # draw the matrix
        self.drawGrid()
        mainloop()

# create the builder class to draw the cards
def main():
    bld = Builder()
    bld.build()

# starts here
if __name__ == '__main__':
    main()