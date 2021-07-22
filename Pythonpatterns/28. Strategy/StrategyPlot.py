"""Strategy pattern demo
The program displays two buttons.
Each button pops up a window using differing
strategies to plot the same data.
"""

import tkinter as tk
from tkinter import *

# Command interface
class Command():
    def comd(self):pass

#derived button class with an abstract comd method
class DButton(Button, Command):
    def __init__(self, master,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

# Button launches the line plot window
class LineButton(DButton):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Line plot", **kwargs)
    def comd(self):
        lst = LineStrategy()
        lst.plot()

# This button launches te bar plot window
class BarButton(DButton):
    def __init__(self, root, **kwargs):
        super().__init__(root, text="Bar plot", **kwargs)

    def comd(self):
        bst = BarStrategy()
        bst.plot()

# Base plot stategy class that reads in the data
# finds its maxima and minima and computes the
# scaling factors for a given window
class PlotStrategy():
    def __init__(self, title):
        self.width = 300
        self.height = 200
        self.title = title
        self.color = "black"  #default color if none chosen
        frame = Toplevel(None)
        frame.title(self.title)
        self.canvas = Canvas(frame, width=self.width, height=self.height)
        self.canvas.pack()
        #read in the file and find its bounds
        self.readFile("data.txt")
        self.findBounds(self.xp, self.yp)

    #abstract plot method, filled in by derived classes
    def plot(self, xp, yp):pass

    def setPencolor(self, c):
        self.color = c

    #finds the max and min of each array
    def findBounds(self, x, y):
        self.minx = min(x)
        self.miny = 0
        self.maxx  = max(x)
        self.maxy = max(y)

    # compute scaling factors
    def calcScale(self, h, w):
        self.xfactor = (0.9 * w) / (self.maxx - self.minx)
        self.yfactor = (0.9 * h) / (self.maxy - self.miny)

        self.xpmin = (int)(0.05 * w)
        self.ypmin = (int)(0.05 * h)
        self.xpmax = w - self.xpmin
        self.ypmax = h - self.ypmin

    # calculate x pixel position
    def calcx(self,xp):
        x= (xp - self.minx) * self.xfactor + self.xpmin
        return x
    # calculate y pixel position
    def calcy(self, yp, h):
        y = h - (yp - self.miny)*self.yfactor
        return y

    # read the data file into x and y arrays
    def readFile(self, fname):
        self.xp = []
        self.yp = []
        with open(fname, "r") as f:
            for sname in f:
                sarray = sname.split()
                self.xp.append(float(sarray[0]))
                self.yp.append(float(sarray[1]))

# strategy for line plot
class LineStrategy(PlotStrategy):
    def __init__(self, master=None):
        super().__init__("Line plot")

    def plot(self):
        w = self.width
        h = self.height
        self.calcScale(h, w)
    # Line plot of the two arrays
        coords = []         #array of x,y pairs
        for i in range(0, len(self.xp)):
            x = self.calcx(self.xp[i])
            y = self.calcy(self.yp[i], h)
            coords.append(x)
            coords.append(y)
        # lot x,y data
        self.canvas.create_line(coords, fill=self.color)

# strategy for bar plots, using colors in list
class BarStrategy(PlotStrategy):
    def __init__(self, master=None):
        super().__init__("Bar plot")
        self.colors= ['red', 'green', 'blue', 'orange', 'gray']

    def plot(self):
        w = self.width
        h = self.height
        self.calcScale(h, w)

        # each bar is a filled rectangles
        ypm = self.ypmax *1.05
        for i in range(0, len(self.xp)):
            x = self.calcx(self.xp[i])
            y = self.calcy(self.yp[i], h)
            self.canvas.create_rectangle(x-10, h,
                        x+10, y, fill =self.colors[i])

# create 2 button window
class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("200x50")
        root.title("Strategy plot")
        lbutton = LineButton(root, width = 10)
        lbutton.pack(side=LEFT, padx=10)
        bbutton = BarButton(root, width=10)
        bbutton.pack(side=RIGHT, padx=10)
        mainloop()

# ----------------------------
def main():
    Builder().build()

###  Here we go  ####
if __name__ == "__main__":
    main()