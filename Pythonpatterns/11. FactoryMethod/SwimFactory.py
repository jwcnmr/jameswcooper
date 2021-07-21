import tkinter as tk
from tkinter import *
from tkinter import ttk
from SwimClasses import TimedFinalEvent, PrelimEvent

#----------
class BuildUI():
    def __init__(self, root):
        self.root=root
        root.title("Seeding")

    #calllback when you click on a swim event in the left left box
    def evselect(self, evt):
        index = self.evlist.curselection()  # returns a tuple
        i = int(index[0])  # this is row number
        # there are only two swimmer files
        # We read in one or the other
        if i <=0 :
            event = TimedFinalEvent("500free.txt", 6)
        else:
            event = PrelimEvent("100free.txt", 6)

        seeding = event.getSeeding()    #factory here
        swmrs= seeding.getSwimmers()    #do one sort of seeding or the other
        self.swlist.delete(0, END)      #clear the listbox
        #load new values into list box
        for sw in swmrs:
           self.swlist.insert(END, str(sw.heat)+" "+ str(sw.lane)+" "
                              + sw.getName()+" "+ str(sw.age)+ " "+sw.seedtime)

    #creates the two listbox user interface
    def build(self):
        self.root.geometry("325x200")
        self.evlist = Listbox(self.root)
        self.evlist.insert(END,"500 Free")
        self.evlist.insert(END, "100 Free")
        self.evlist.grid(row=0, column=0)
        self.evlist.bind('<<ListboxSelect>>', self.evselect)
        self.swlist = Listbox(self.root)
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