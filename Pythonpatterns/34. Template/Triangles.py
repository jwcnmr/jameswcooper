"""Template pattern example
creates a generic triangle as a template
Then an Isosceles triangle is created
by moving the 2nd point to be equidistant
from p1 and p3"""

import math
import tkinter as tk
from tkinter import *

# Point class holds two coordinates
# publicly accessible
class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y

# base Triangle class has the drawLine and draw methods
# which are called in the derived classes
class Triangle():
    def __init__(self, canvas: Canvas, a: Point, b: Point, c: Point):
        self.p1 = a
        self.p2 = b
        self.p3 = c
        self.canvas = canvas
    # draws a line between two points
    def drawLine(self, a, b):
        self.canvas.create_line(a.x, a.y, b.x, b.y)
    #draws the complete triangle
    def draw(self):
        self.drawLine(self.p1, self.p2)
        current = self.draw2ndLine(self.p2, self.p3)
        self.closeTriangle(current)
    # this is filled in by the derived classes
    def draw2ndLine(self, a: Point, b: Point):
        pass
    #closes the triangle from c back to p1
    def closeTriangle(self, c: Point):
        self.drawLine(c, self.p1)

# A simple standard triangle
class StdTriangle(Triangle):
    def __init__(self, canvas, a, b, c):
        super().__init__(canvas, a, b, c)

    def draw2ndLine(self, a: Point, b: Point):
        self.drawLine(a, b)
        return b

# the isosceles triangle moves point p2
# to make it equidistante from p1 and p3
class IsoscelesTriangle(Triangle):

    def __init__(self, canvas, a, b, c):
        super().__init__(canvas, a, b, c)
        dx1 = b.x - a.x
        dy1 = b.y - a.y
        dx2 = c.x - b.x
        dy2 = c.y - b.y

        side1 = self.calcSide(dx1, dy1)
        side2 = self.calcSide(dx2, dy2)

        if (side2 < side1):
            incr = -1
        else:
            incr = 1

        slope = dy2 / dx2
        intercept = c.y - slope * c.x

        # move point c so that this is an isoceles triangle
        self.newcx = c.x
        self.newcy = c.y
        while math.fabs(side1 - side2) > 1:
            self.newcx += incr  # iterate a pixel at a time until close
            self.newcy = (int)(slope * self.newcx + intercept)
            dx2 = self.newcx - b.x
            dy2 = self.newcy - b.y
            side2 = self.calcSide(dx2, dy2)

        self.newc = Point(self.newcx, self.newcy)

    # calculate length of side
    def calcSide(self, dx, dy):
        return math.sqrt(dx * dx + dy * dy)

    # draws 2nd line using saved new point
    def draw2ndLine(self, b, c):
        self.drawLine(b, self.newc)
        return self.newc


# creates the two triangles and draws them
class Builder():
    def build(self):
        root = tk.Tk()
        root.title("Template plot")
        canvas = Canvas(root, width=300, height=300)
        canvas.pack()
    # coordinates of standard triangle
        p1 = Point(100, 40)
        p2 = Point(75, 100)
        p3 = Point(175, 150)

        stdTriangle = StdTriangle(canvas, p1, p2, p3)
        stdTriangle.draw()
    # starting coordinates for isosceles triangle
        p4 = Point(150, 200)
        p5 = Point(240, 140)
        p6 = Point(175, 250)

        isoTriangle = \
            IsoscelesTriangle(canvas, p4, p5, p6)
        isoTriangle.draw()
        mainloop()

##----------------
def main():
    Builder().build()


###  Here we go  ####
if __name__ == "__main__":
    main()
