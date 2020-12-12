"""Displays seven labeled folders as Flyweight pattern
There are only two folder classes:
selected and unselected. The coordinates
are calculated at display time.
Clicking on any folder changes the select.
Clicking outside folder deselects any that is selected"""

from tkinter import ttk
from tkinter import *
from tkinter.ttk import *

# returns a selected or unselected folder
class FolderFactory():

    def __init__(self, canvas):
        brown = "#5f5f1c"
        self.selected = Folder(brown, canvas)
        self.unselected = Folder("yellow", canvas)

    def getFolder(self, isSelected):
        if isSelected:
            return self.selected
        else:
            return self.unselected

#draws a folder
class Folder():
    W =50
    H=30

    def __init__(self, color, canvas:Canvas):
        self._color = color
        self.canvas = canvas
# draw the folder
    def draw (self, tx, ty, name):
        self.canvas.create_rectangle(tx, ty, tx+Folder.W, ty+Folder.H,
                                     fill="black")
        self.canvas.create_text(tx+20, ty+Folder.H+15, text=name)
        self.canvas.create_rectangle(tx+1, ty+1, tx + Folder.W-1,
                                     ty + Folder.H-1,
                                     fill=self._color)
        self.canvas.create_line(tx+1, ty+Folder.H-5, tx+ Folder.W-1,
                                ty+Folder.H-5,
                                fill="#cccccc")
        self.canvas.create_line( tx, ty+Folder.H+1, tx+Folder.W-1,
                                 ty+Folder.H+1, fill="black")
        self.canvas.create_line(tx+Folder.W+1, ty, tx+Folder.W+1,
                                ty+Folder.H, fill="black")
        self.drawTab(tx, ty)
        self.canvas.create_line(tx + 1, ty + 1, tx + Folder.W - 1,
                                ty + 1, fill="#ffffff")
        self.canvas.create_line(tx + 1, ty + 1, tx + 1,
                                ty + Folder.H - 1, fill="#ffffff")

#draw the tab above the folder
    def drawTab(self, tx, ty):
        tableft = 0
        tabheight = 4
        tabwidth = 20
        tabslant = 3

        self.canvas.create_polygon(tx+tableft, ty,
                                   tx+tableft+tabslant, ty-tabheight,
                                   tx + tabwidth - tabslant, ty - tabheight,
                                   tx + tabwidth, ty, fill='black'
                                   )
        self.canvas.create_polygon(tx + tableft+1, ty+1,
                                   tx + tableft + tabslant+1, ty - tabheight+1,
                                   tx + tabwidth - tabslant-1, ty -tabheight+1,
                                   tx + tabwidth, ty, fill=self._color
                                   )


# construct the layout
class FlyCanvas():
    TOP = 30
    LEFT = 30
    HSPACE = 70
    VSPACE = 70
    ROWMAX = 2
    HCOUNT = 3

    def build(self):
        root = Tk()
        root.geometry("300x240")  # this one is pretty confusing
        root.title("Folders")  # title only shows if window is wide enough
        self.canvas = Canvas(root)
        self.canvas.bind('<Button-1>', self.mouseClick)
        self.factory= FolderFactory(self.canvas)

        self.canvas.pack()
        self.namelist=['Alan', 'Bonnie', 'Charlie', 'Donna', 'Edward', 'Fiametta', 'George']
        self.selectedName = 'Edward'
        self.repaint()
# repaint all the folders
    def repaint(self):
        j = 0
        row = FlyCanvas.TOP
        x= FlyCanvas.LEFT

        # look for whether any is selected and
        # use the factory to create it
        for nm in self.namelist:
            f = self.factory.getFolder(nm == self.selectedName)
            f.draw( x, row, nm)
            x+= FlyCanvas.HSPACE
            j += 1
            if j>FlyCanvas.ROWMAX:
                j = 0
                row += FlyCanvas.VSPACE
                x = FlyCanvas.LEFT
    # search to see if click is inside a folder
    # changes the selected name so repaint draws
    # a new selected folder
    def mouseClick(self, evt):
        self.selectedName= ""
        found = False
        j = 0
        row =FlyCanvas.TOP
        x = FlyCanvas.LEFT
        self.selectedName = ""  #blank if not in folder
        for nm in self.namelist:
            if x < evt.x and evt.x < (x+ Folder.W):
                 if row < evt.y and evt.y < (row+Folder.H):
                    self.selectedName = nm
                    found = True
            j += 1
            x += FlyCanvas.HSPACE
            if j > FlyCanvas.ROWMAX:
                j=0
                row += FlyCanvas.VSPACE
                x = FlyCanvas.LEFT
        self.repaint()

def main():
    FlyCanvas().build()
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()