"""Memento graphics demo. You can create rectangles when the R box is checked
and select them and drag them when it is not,
The Undo button removes rectangles from the stack in the Caretaker class
and restores their previous position using a Memento to store the last position
before the rectangel is dragged"""
import tkinter as tk
from operator import attrgetter
from tkinter import *
#import tkinter.ttk
#from tkinter.ttk import *

# Command interface
class Command():
    def comd(self):pass

#derived button class with an abstract comd method
class DButton(Button, Command):
    def __init__(self, master,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

# Undoes rectangles and drags
class UndoButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text="U")
        self.med = med
    def comd(self):
        self.med.undo()

# Manages the stack of Rectangles and Mementoes
class Caretaker():
    def __init__(self, med):
        self.med = med
        self.rectList= []
        med.setCare(self)
    #append latest visObj
    def append(self, visobj):
        self.rectList.append(visobj)
    #get the top of the stack and undo the visObj
    def undo(self):
        if len(self.rectList) > 0:
            visobj = self.rectList.pop()
            visobj.undo()
    # clear the canvas
    def clear(self):
        while len(self.rectList) > 0:
            visobj = self.rectList.pop()
            visobj.undo()

# abstract class representing both Rectangles and Mementos
class VisObject():
    def undo(self): pass
    def contains(self, x,y):
        return False
    def isSelected(self):
        return False

# draw 30 x 20 rectangle
# and 4 pixel square handles if selected
class Rectangle(VisObject):
    def __init__(self,x, y, canvas):
        self.x = x  # save coordinates
        self.y = y
        self.canvas = canvas
        self._selected = False
        self.handles = []   #create corners array
        fillcol='black'     # color or rectangle and handles

        #create main Rectangle
        self.crect = self.canvas.create_rectangle(x - 20,
                        y - 15, x + 20, y + 15, outline=fillcol)

        # and create the four (hidden) handles
        c = self.canvas.create_rectangle(x - 22,
                                         y - 2, x - 18, y + 2, fill=fillcol, state=HIDDEN)
        self.handles.append(c)
        c = self.canvas.create_rectangle(x + 18,
                                         y - 2, x + 22, y + 2, fill=fillcol, state=HIDDEN)
        self.handles.append(c)
        c = self.canvas.create_rectangle(x - 2,
                                         y - 17, x + 2, y - 13, fill=fillcol, state=HIDDEN)
        self.handles.append(c)
        c = self.canvas.create_rectangle(x - 2,
                                         y + 17, x + 2, y + 13, fill=fillcol, state=HIDDEN)
        self.handles.append(c)

    # move rectangle and handles,
    # using a delta between old and new positions
    def move(self, x, y):
        oldx = self.x
        oldy = self.y

        self.x = x
        self.y = y
        deltax= x - oldx    # calc deltas
        deltay = y - oldy
        # move rect
        self.canvas.move(self.crect, deltax, deltay)
        # move handles
        for c in self.handles:
            self.canvas.move(c, deltax, deltay)


    # deletes the rectangle on the screen
    def undo(self):
        self.canvas.delete(self.crect)
        self.deleteHandles()

    # draws the handles
    def draw(self):
         if self._selected:
            for c in self.handles:
                self.canvas.itemconfigure(c, state=NORMAL)

    # returns True if x,y is inside the rectangle
    def contains(self, x, y):
        inside =  self.x-30 <=x and x <= self.x+30 \
            and self.y-20 <= y and y <= self.y +20
        return inside

    # state to selected or not
    def setSelected(self, val):
        self._selected = val
    #returns True if selected
    def isSelected(self):
        return self._selected

    # hide the handles
    def hideHandles(self):
        for c in self.handles:
            self.canvas.itemconfigure(c, state=HIDDEN)

    #deletes the handles when rect is deleted
    def deleteHandles(self):
        for c in self.handles:
            self.canvas.delete(c)

# Memento stores last position of rectangle before dragging
# and restores it by clicking undo button
class Memento(VisObject):
    def __init__(self, x, y, rect:Rectangle):
        self.rect = rect
        self.oldx = x
        self.oldy = y
    def undo(self):
        self.rect.move(self.oldx, self.oldy )

# Mediator manages the button and mouse events
class Mediator():
    def __init__(self, canvas):
        self.canvas = canvas
        self.rect = FALSE       # check bax state
        self.selectRect=None    # not selected
        self.dragging = False   # not dragging
        self.memento = None     # variable goes here

    # save ref to Caretaker
    def setCare(self,care):
        self.care = care

    # save currently selected rectangle
    def rectClicked(self, var):
        self.rect= var

    # button 1 has been clicked
    def buttonDown(self, evt):
        # create new rectabgle if box checked
        if self.rect:
            newrect = Rectangle(evt.x, evt.y,self.canvas)
            newrect.draw()
            self.care.append(newrect)   # save in stack
        else:
            x = evt.x
            y = evt.y
            saverect = None

        # if there is a selected rectangle,
        # hide its handles
            for r in self.care.rectList:
                if r.isSelected():
                    r.setSelected(False)
                    r.hideHandles()
                    r.draw()
        # if one was clicked in, make it selected
            for r in self.care.rectList:
                if r.contains(x, y):
                    r.setSelected(True)
                    self.selectRect = r
                    r.draw()

    # when button is up store the Memento
    def buttonUp(self, evt):
        if self.dragging:
            self.care.append(self.memento)
            self.dragging = False

    #drag rectangle to new position
    def drag(self, evt):
        if self.selectRect != None:
            if not self.dragging:
                self.dragging = True
                # save the memento as drag starts
                self.memento = Memento(self.selectRect.x,
                            self.selectRect.y, self.selectRect)
            self.selectRect.move(evt.x, evt.y)

    # undo stack
    def undo(self):
        self.care.undo()

    # clear all objects
    def clear(self):
        self.care.clear()

# Clear button removes all rectangles
class ClearButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text="Clr")
        self.med = med
    def comd(self):
        self.med.clear()

# Rect is a check box
# When selected you can create rectangles
class RectBox(Checkbutton):
    def __init__(self, rt,  gvar, med):
        super().__init__(rt,  var=gvar, text="R",indicatoron=0, command =self.comd)
        self.med = med
        self.gvar=gvar
    def comd(self):
        self.med.rectClicked(self.gvar.get())

# builds the user interface
class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("350x250")
        root.title("Memento demo")
        frame = Frame(root)
        frame.grid(row=0, column=0, sticky=EW)
        canvas = Canvas(root)
        canvas.grid(row=1, column=0, sticky=NSEW)
        med = Mediator(canvas)
        care = Caretaker(med)

        #binds the mouse events
        canvas.bind("<Button-1>", med.buttonDown)
        canvas.bind("<B1-Motion>", med.drag)
        canvas.bind("<ButtonRelease-1>", med.buttonUp)
        groupv = tk.IntVar(0)
        chkval = tk.BooleanVar()

        # create button bar at top
        rectButton = RectBox(frame, chkval, med)
        undoButton = UndoButton(frame, med)
        clearButton = ClearButton(frame, med)
        rectButton.pack(side=LEFT, padx=5)
        undoButton.pack(side=LEFT, padx=1)
        clearButton.pack(side=LEFT, padx=20)

        mainloop()

# ----------------------------
def main():
    Builder().build()

###  Here we go  ####
if __name__ == "__main__":
    main()