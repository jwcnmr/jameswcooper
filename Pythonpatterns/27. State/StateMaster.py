"""State pattern demonstration
THe first four buttons change how the screen reacts to
mouse clicks and mouse movement.
You can create a rectangle or a circle, pick either one
and drag it. Or you can use the fill button to fill the currently
selected drawing or the next one you select.
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
    def select(self):
        self.config(relief=SUNKEN)
    def deselect(self):
        self.config(relief=RAISED)


class State():
    def mouseDown(self, evt:Event):pass
    def mouseUp(self, evt:Event):pass
    def mouseDrag(self, evt:Event):pass
    def select(self):pass

class PickState(State):
    def __init__(self, med):
        self.med = med
        self.dragging = False
    def mouseDown(self, evt:Event):
        x = evt.x
        y = evt.y
        rectList =  self.med.getRectlist()
        for r in rectList:
            r.setSelected(False)
        for r in rectList:
            if r.contains(x,y):
                r.setSelected(True)
                self.med.setSelected(r)
                r.drawHandles()

    def mouseDrag(self, evt:Event):
        if self.med.selectRect != None:
            if not self.dragging:
                self.dragging = True
            self.med.selectRect.move(evt.x, evt.y)

class RectState(State):
    def __init__(self, med):
        self.med = med
    def mouseDown(self, evt:Event):
        # create new rectangle if box checked
        newrect = Rectangle(evt.x, evt.y, self.med.canvas)
        rectList = self.med.getRectlist()
        rectList.append(newrect)  # save in stack

        # if there is a selected rectangle,
        # hide its handles
        for r in rectList:
            if r.isSelected():
                r.setSelected(False)
                r.hideHandles()

        # if one was clicked in, make it selected
        for r in rectList:
            if r.contains(evt.x, evt.y):
                r.setSelected(True)
                self.med.setSelected( r)

class CircState(State):
    def __init__(self, med):
        self.med = med
    def mouseDown(self, evt:Event):
        # create new circle
        newrect = Circle(evt.x, evt.y, self.med.canvas)
        rectList = self.med.getRectlist()
        rectList.append(newrect)  # save in stack

        # if there is a selected rectangle,
        # hide its handles
        for r in rectList:
            if r.isSelected():
                r.setSelected(False)
                r.hideHandles()

        # if one was clicked in, make it selected
        for r in rectList:
            if r.contains(evt.x, evt.y):
                r.setSelected(True)
                self.selectRect = r

class FillState(State):
    def __init__(self, med):
        self.med = med
    # if a figure is selected, fill it
    def select(self):
        rect = self.med.getSelected()
        if rect != None:
            rect.fillObject()
    # otherwise fill the next figure you click on
    def mouseDown(self, evt:Event):
        rectList = self.med.getRectlist()
        for r in rectList:
            if r.contains(evt.x, evt.y):
                r.fillObject()
                self.selectRect = r

# switches betweeen states depending on the button you click
class StateManager():
    def __init__(self, med):
        self.med = med
        # create instances of each state
        self.pickState = PickState(med)
        self.curState = self.pickState
        self.rectState = RectState(med)
        self.fillState =  FillState(med)
        self.circState = CircState(med)

    # here  are the three events we act on
    def mouseDown(self, evt):
        self.curState.mouseDown(evt)
    def mouseDrag(self, evt):
        self.curState.mouseDrag(evt)
    def select(self):
        self.curState.select()

    # switch states as you click on buttons
    def setRect(self):
        self.curState = self.rectState
    def setCirc(self):
        self.curState = self.circState
    def setFill(self):
        self.curState = self.fillState
    def setPick(self):
        self.curState = self.pickState


# draw 30 x 20 rectangle
# and 4 pixel square handles if selected
class Rectangle():
    def __init__(self,x, y, canvas):
        self.x = x  # save coordinates
        self.y = y
        self.canvas = canvas
        self._selected = False
        self.handles = []   #create corners array
        self.fillcol='black'     # color or rectangle and handles

        #create main Rectangle
        self.crect = self.canvas.create_rectangle(x - 20,
                        y - 15, x + 20, y + 15, outline=self.fillcol)
        self.createHandles(x,y)

    def createHandles(self, x, y):
        # and create the four (hidden) handles
        fillcol=self.fillcol
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
    def drawHandles(self):
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

    def fillObject(self):
        self.canvas.itemconfig(self.crect, fill='red')


class Circle(Rectangle):
    def __init__(self, x,y, canvas):
        self.x = x  # save coordinates
        self.y = y
        self.canvas = canvas
        self._selected = False
        self.handles = []  # create corners array
        self.fillcol = 'black'  # color or rectangle and handles

        # create main Circle
        self.crect = self.canvas.create_oval(x - 20, y - 20, x + 20, y + 20, outline=self.fillcol)
        self.createHandles(x, y)
        self.hideHandles()

# Mediator manages the button and mouse events
class Mediator():
    def __init__(self, canvas):
        self.canvas = canvas
        self.selectRect=None    # not selected
        self.dragging = False   # not dragging
        self.memento = None     # variable goes here
        self.rectList=[]
        self.buttons = []
        # create the StateManager
        self.statemgr = StateManager(self)

    def getRectlist(self):
        return self.rectList

    def addButton(self, but:DButton):
        self.buttons.append(but)

    #unselect all 4 buttons
    def unselectButtons(self):
        for but in self.buttons:
            but.deselect()

       # button 1 has been clicked
    def buttonDown(self, evt):
        self.statemgr.mouseDown(evt)

    # circle button sets Circle state
    def circleClicked(self):
        self.statemgr.setCirc()

    #selected rect or circle stored
    def setSelected(self, r):
        self.selectRect = r

    #gets the selected drawing object
    def getSelected(self):
        return self.selectRect

    #drag rectangle/circle to new position
    def drag(self, evt):
        self.statemgr.mouseDrag(evt)

    # clear all objects
    def clear(self):
        while len(self.rectList) > 0:
            visobj = self.rectList.pop()
            visobj.undo()

# Clear button removes all rectangles
class ClearButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text="Clr")
        self.med = med
    def comd(self):
        self.med.clear()

# When selected you can create rectangles
class RectButton(DButton):
    def __init__(self, rt,  med):
        super().__init__(rt)
        self.photo = PhotoImage(file="rectforbutton.png")
        self.config(image=self.photo)
        self.med = med
        med.addButton(self) # add to button list

    def comd(self):
        # deselect all buttons
        self.med.unselectButtons()
        self.select()   #select this one
        # set the statemanager to Rect state
        self.med.statemgr.setRect()

# This is the arrow button
class PickButton(DButton):
    def __init__(self, rt,  med):
        super().__init__(rt)
        self.photo = PhotoImage(file="arrow.gif")
        self.config(image=self.photo)
        self.med = med
        med.addButton(self)

    def comd(self):
        self.med.unselectButtons()
        self.select()
        self.med.statemgr.setPick()

# The circle button
class CircleButton(DButton):
    def __init__(self, rt,  med):
        super().__init__(rt)
        self.photo = PhotoImage(file="circlebutton.png")
        self.config(image=self.photo)
        self.med = med
        self.med.addButton(self)

    def comd(self):
        self.med.unselectButtons()
        self.select()
        self.med.statemgr.setCirc()

# The fill button
class FillButton(DButton):
    def __init__(self, rt,  med):
        super().__init__(rt)
        self.photo = PhotoImage(file="redbutton.png")
        self.config(image=self.photo)
        self.med = med
        self.med.addButton(self)

    def comd(self):
        self.med.unselectButtons()
        self.select()
        # sets the fill state
        # the selected button state in case an object is already selected
        self.med.statemgr.setFill()
        self.med.statemgr.curState.select()

# builds the user interface
class Builder():
    def build(self):
        root = tk.Tk()
        root.geometry("350x250")
        root.title("State demo")
        frame = Frame(root)
        frame.grid(row=0, column=0, sticky=EW)
        canvas = Canvas(root)
        canvas.grid(row=1, column=0, sticky=NSEW)
        med = Mediator(canvas)

        #binds the mouse events
        canvas.bind("<Button-1>", med.buttonDown)
        canvas.bind("<B1-Motion>", med.drag)

        # create button bar at top
        pickButton = PickButton(frame, med)
        rectButton = RectButton(frame, med)
        circleButton = CircleButton(frame,med)
        fillButton = FillButton(frame,med)
        clearButton = ClearButton(frame, med)

        pickButton.pack(side=LEFT, padx=5)
        rectButton.pack(side=LEFT, padx=5)
        circleButton.pack(side=LEFT, padx=5)
        fillButton.pack(side=LEFT, padx=5)
        clearButton.pack(side=LEFT, padx=20)

        mainloop()

# ----------------------------
def main():
    Builder().build()

###  Here we go  ####
if __name__ == "__main__":
    main()