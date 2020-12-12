"""Garden planning ap
Allows you to select three types of gardens and
get recommendation for sun, shade and border plants.
Uses the Abstract Factory pattern to select the type of plants
for each the Garden"""
import tkinter as tk
from tkinter import *
from tkinter.ttk import *

# Abstract Garden class
class Garden:
    def getShade(): pass
    def getCenter(): pass
    def getBorder(): pass

# Plant class gives you its name
class Plant:
    def __init__(self, pname):
        self.name = pname     #save name
    def getName(self):
        return self.name

# one of three Garden subclasses
class VeggieGarden (Garden):
    def getShade(self):
        return  Plant("Broccoli")
    def getCenter(self):
        return Plant("Corn")
    def getBorder(self):
        return  Plant("Peas")

class AnnualGarden (Garden):
    def getShade(self):
       return Plant("Coleus")
    def getCenter(self):
        return Plant("Marigold")
    def getBorder(self):
        return Plant("Alyssum")

class PerennialGarden (Garden):
    def getShade(self):
        return Plant("Astilbe")
    def getCenter(self):
        return Plant("Dicentrum")
    def getBorder(self):
        return Plant("Sedum")

# derived button containing its command
# Sends the type of garden toe th Gardening class
class Dbutton(Button):
    def __init__(self, master, **kwargs) :
        super().__init__(master,  command=self.comd, **kwargs)
    def setGarden(self, gardener):
        self.gardener =gardener
    def comd(self): pass

# 3 derived buttons for selecting the 3 types of plants
class CentralButton (Dbutton):
    def __init__(self,  master, **kwargs):
        super().__init__( master, **kwargs)
    def comd(self):
        self.gardener.setCenter()
class ShadeButton (Dbutton):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
    def comd(self):
        self.gardener.setShade()
class BorderButton(Dbutton):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
    def comd(self):
        self.gardener.setBorder()

# ChoiceButton is derived from RadioButton
class ChoiceButton(Radiobutton):
    def __init__(self, rt, name, index, garden, gardener, gvar):
        super().__init__(rt, text=name,
                         command=self.comd,
                         variable=gvar, value=index)

        self.pack(anchor=W)
        self.root = rt		#copy values into this class
        self.name = name
        self.index = index
        self.var = gvar		#contains current selection
        self.garden = garden
        self.gardener = gardener

    # clicks are sent here
    # The background is also cleared
    def comd(self):
        self.gardener.setGarden(self.garden)
        self.gardener.clearCanvas()

# Outer class that contains the Gardens
class Gardener():
    def __init__(self):
        self.garden=VeggieGarden

    def setGarden(self, garden):
        self.garden =garden
    def clearCanvas(self):
        self.canv.delete("all")
        self.canv.create_oval(20, 20, 100, 100, fill="lightgray")
    def setCenter(self):
        self.canv.create_text(100,120, text=self.garden.getCenter(self).getName())
    def setBorder(self):
        self.canv.create_text(75, 180, text=self.garden.getBorder(self).getName())
    def setShade(self):
        self.canv.create_text(60, 60, text=self.garden.getShade(self).getName())
    #  builds the UI
    def build(self):
        root = tk.Tk()
        root.title("Garden planner")
        lframe = Frame()
        rframe = Frame()
        lframe.grid(row=0,column=0)
        rframe.grid(row=0, column=1)
        style = Style()
        style.theme_use('alt')
        lbframe=LabelFrame(lframe, text="Garden type")
        #lbframe.pack(side=TOP)
        lbframe.grid(row=0)
        groupv = tk.IntVar()

        ChoiceButton(lbframe, 'Vegetable', 0, VeggieGarden, self,  groupv)
        ChoiceButton(lbframe, 'Annual', 1, AnnualGarden, self, groupv)
        ChoiceButton(lbframe, 'Perennial', 2, PerennialGarden, self, groupv)

        self.canv = Canvas(rframe, width=200, height=200,  bg="white")
        self.canv.pack()
        self.canv.create_oval(20,20, 100,100, fill="lightgray")
        self.clearCanvas()
        rf1=Frame(rframe)
        rf1.pack()

        #  places the buttons under the canvas
        centButton = CentralButton(rf1,text="Central")
        centButton.setGarden(self)
        bordButton = BorderButton(rf1,text="Border")
        bordButton.setGarden(self)
        shadeButton = ShadeButton(rf1,text="Shade")
        shadeButton.setGarden(self)
#        lbotframe = Frame(lframe)
#        lbotframe.pack(side=BOTTOM)
 #       quitButton = Button(lbotframe,text="Quit", command = quit)
        quitButton = Button(lframe, text="Quit", command=quit)

        centButton.grid(row=0, column=0)
        bordButton.grid(row=0, column=1)
        shadeButton.grid(row=1, column=0, columnspan=2)
        #quitButton.pack(side=BOTTOM)
        quitButton.grid(row=2, pady=50)

        mainloop()

def main():
    gardener = Gardener()
    gardener.build()

###  Here we go  ####
if __name__ == "__main__":
    main()



