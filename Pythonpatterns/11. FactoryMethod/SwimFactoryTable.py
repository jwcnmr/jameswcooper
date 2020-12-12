import tkinter as tk
from tkinter import *
from tkinter import ttk
from tkinter.ttk import *

class Seeding:
    def getSwimmers(self): pass
    def getCount(self): pass
    def getHeats(self): pass

class Event():
    def __init__(self, filename, lanes):
        self.numLanes = lanes
        self.swimmers=[]

        f = open(filename, "r")
        for swstring in f:
            sw = Swimmer(swstring)
            self.swimmers.append(sw)
        f.close()
    #place holders to be filled in in actual classes
    def getSeeding(self): pass
    def isPrelim(self): pass
    def isFinal(self): pass
    def isTimedFinal(self): pass
#-----------------------
class PrelimEvent (Event):
 #creates a preliminary event which is circle seeded
    def __init__(self, filename, lanes):
        super().__init__(filename, lanes)

    def  getSeeding(self):
        return CircleSeeding(self.swimmers, self.numLanes)
#--------------------
class TimedFinalEvent (Event):
#creates an event that will be straight seeded
   def __init__(self, filename,  lanes):
        super().__init__(filename, lanes)

   def getSeeding(self):
        return StraightSeeding(self.swimmers, self.numLanes)

"""Straight seeding puts the top swimmers in the last heat
and the next fastest ones in the second heat and so forth"""
class StraightSeeding():
    def __init__(self, sw, nlanes):
        self.swimmers = sw
        self.numLanes = nlanes
        self.count = len(sw)
        self.lanes = self.calcLaneOrder()
        self.seed()
# --------------------------------
    def seed(self):
    #loads the swmrs array and sorts it
        asw = self.sortUpwards()  # number in last heat
        self.lastHeat = self.count % self.numLanes
        if (self.lastHeat < 3):
            self.lastHeat = 3 # last heat must have 3 or more

        lastLanes =self.count - self.lastHeat
        self.numHeats = self.count / self.numLanes

        if (lastLanes > 0):
            self.numHeats += 1 # compute total number of heats
        heats = self.numHeats

        # place heat and lane in each swimmer's object
        j = 0
          # load from fastest to slowest
          # so we start with last heat  # and work downwards
        for i in range(0, lastLanes) :
            sw = asw[i] # get each swimmer
            sw.setLane(self.lanes[j]) # copy in lane
            j += 1
            sw.setHeat(heats) # and heat
            if (j >= self.numLanes):
                heats -= 1 # next heat
                j=0
    # Add in last partial heat
        if (j < self.numLanes):
             heats -= 1
             j = 0
      #for (int i = lastLanes-1; i < count; i++):
        for i in range(lastLanes-1, self.count):
             sw = asw[i]
             sw.setLane(self.lanes[j])
             j += 1
             sw.setHeat(heats)

    # copy from array back into Vector
        swimmers = []
        for i in range(0, self.count):
            swimmers.append(asw[i]);

    # Sorts the swimmers by seed time
    def sortUpwards(self):
        swmrs = []

        for swmr in self.swimmers:
           swmrs.append(swmr)

        for i in range(0, self.count):
            for j in range(i, self.count):
                if (swmrs[i].getTime() > swmrs[j].getTime()):
                    swtemp = swmrs[i]
                    swmrs[i] = swmrs[j]
                    swmrs[j] = swtemp
        return swmrs

    # This works for any number of lanes, odd or even
    # seeing always starts in the middle and works outward
    def calcLaneOrder(self):
        lanes =[]
        mid = self.numLanes / 2
        if self.odd(self.numLanes):
            mid = mid + 1 # start in middle lane

        incr = 1
        ln = mid

        for i in range(0, self.numLanes):
            lanes.append(ln)
            ln = mid + incr
            incr = - incr
            if (incr > 0):
                incr = incr + 1
        return lanes
    #returns a List of sorted, seeded swimmers
    def getSwimmers(self):
        return self.swimmers

    #simple function to return true if the number is off
    def odd(self, num):
        return (num % 2) != 0

"""Circle seeding distributes the fastest swimmers into the top 3 heats"""
class CircleSeeding(StraightSeeding):
    def __init__(self, sw, nlanes):
        super().__init__(sw, nlanes)

    def seed(self):
        super().seed() # do straight seed as default
        if (self.numHeats >= 2):
            if (self.numHeats >= 3):
                circle = 3
            else:
                circle = 2
        i = 0

        for j in range(0, self.numLanes)    :
            for k in range(0, circle):
                self.swimmers[i].setLane(self.lanes[j])
                self.swimmers[i].setHeat(self.numHeats - k)
                i += 1
#------------
class Swimmer():
     def __init__(self, dataline):
         sarray = dataline.split()  #read in a row and separate the columns
         self.frname=sarray[1]      #names
         self.lname=sarray[2]
         self.age=int(sarray[3])    #age
         self.club=sarray[4]        #club symbol
         self.seedtime=sarray[5]    #seed time as string
         self.time=0.0              #set defaults
         self.lane=0                #seeded heats and lanes go here
         self.heat=0
         #remove colon from times of 1 minute or greater
         #so they can be sorted numerically
         if self.seedtime.find(":") > 0:
             mins = self.seedtime.split(":")
             atime = mins[0] + mins[1]  # time with colon removed
             self.time=float(atime)     #converted to float for sorting
         else:
             self.time=float(self.seedtime)
    #mConcatenate first and last names
     def getName(self):
          return self.frname+" "+self.lname #combine names

     def getAge(self):  return self.age
     def getClub(self): return self.club
     def getSeed(self): return self.seedtime
     def getTime(self): return self.time
     def getHeat(self): return self.heat
     def getLane(self):  return self.lane
     def setLane(self,lane):  self.lane=int(lane)
     def setHeat(self, heat): self.heat = int(heat)
#----------
class BuildUI():
    def __init__(self, root):
        self.root=root
        root.title("Seeding")

    #calllback when you click on a seim event in the left left box
    def evselect(self, evt):
        index = self.evlist.curselection()  # returns a tuple
        i = int(index[0])  # this is row number
        # there are only two swimmer files
        # We read in one or the other
        if i <=0 :
            event = TimedFinalEvent("500free.txt",6)
        else:
            event = PrelimEvent("100free.txt", 6)

        seeding = event.getSeeding()    #factory here
        swmrs= seeding.getSwimmers()    #do one sort of seeding or the other
        # self.swlist.delete(0, END)      #clear the listbox

        self.swlist.delete(*self.swlist.get_children())
        #load new values into list box
        row=1
        for sw in swmrs:
           #self.swlist.insert(END, str(sw.getHeat())+" "+ str(sw.getLane())+" " + sw.getName()+" "+ str(sw.getAge())+ " "+sw.getSeed())
            self.swlist.insert("", row, text=str(sw.getHeat()).strip(),
                               values=(str(sw.getLane()), sw.getName(), str(sw.getAge()) ,sw.getSeed() ))
            row += 1
    #creates the two listbox user interface
    def build(self):
        self.root.geometry("400x200")
        self.evlist = Listbox(self.root)
        self.evlist.insert(END,"500 Free")
        self.evlist.insert(END, "100 Free")
        self.evlist.grid(row=0, column=0)
        self.evlist.bind('<<ListboxSelect>>', self.evselect)
    #create a treeview for the seeded results--used as a table
        tree = Treeview(self.root)
        tree["columns"] =("lane", "name","age","seed")
        tree.column("#0", width=40, minwidth=10, stretch=NO) #heat
        tree.column("lane", width=30, stretch=NO)
        tree.column("name", width=100, stretch=NO)
        tree.column("age", width=40, stretch=NO)
        tree.column("seed", width=50, stretch=NO)
        tree.heading('#0', text="H")
        tree.heading('lane', text="L")
        tree.heading('name', text="Name")
        tree.heading("age", text="Age")
        tree.heading('seed', text="Seed")
        # Sets the column header font to bold
        style = ttk.Style()
        style.configure("Treeview.Heading",
                        font=(None, 10, "bold"))
        self.swlist = tree
        self.swlist.grid(row=0, column=1, pady=10,sticky="nsew")
        self.root.grid_columnconfigure(0, weight=1)
        self.root.grid_columnconfigure(1, weight=3)
        mainloop()

#--------------------------
# -----main begins here----
def main():
    root= tk.Tk()
    builder = BuildUI(root)
    builder.build()


###  Here we go  ####
if __name__ == "__main__":
    main()