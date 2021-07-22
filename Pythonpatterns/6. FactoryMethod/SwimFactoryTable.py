import tkinter as tk
from tkinter import *
from tkinter import ttk
from tkinter.ttk import *
from SwimClasses import TimedFinalEvent, PrelimEvent

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
            self.swlist.insert("", row, text=str(sw.heat).strip(),
                               values=(str(sw.lane), sw.getName(), str(sw.age) ,sw.seedtime ))
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