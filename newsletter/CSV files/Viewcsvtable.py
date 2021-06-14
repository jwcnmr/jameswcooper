import tkinter as tk
from tkinter import *
from tkinter.ttk import *
import csv

class ReadCsv:
    def __init__(self, filename):
        # now read in the entire file
        with open(filename, newline='') as csvfile:
            addReader = csv.reader(csvfile)
            self.rows = []
            for row in addReader:
                self.rows.append(row)
            self.headRow = self.rows.pop(0)

# Builder creates the GUI
class Builder:
    def __init__(self):
        # create candidate list
        self.readCsv = ReadCsv('namehlist.csv')

    def loadTree(self):
        rows = self.readCsv.rows
        index = 0

        for r in rows:
            self.mainTree.insert("", index,
                             text = r,
                             values = r)
            index += 1

    def build(self):
        root = tk.Tk()
        root.geometry("375x200")
        root.title("Demo table")
        frame = Frame(root)
        self.readCsv.rows

        self.mainTree = Treeview(root, height=20)
        header = self.readCsv.headRow
         # create and name columns
        self.mainTree["columns"] = tuple(header)
        self.mainTree.column("#0", width=10, minwidth=20, stretch=NO)  # first name
        self.mainTree.column(header[0], width=60, stretch=NO)
        self.mainTree.column(header[1], width=60, stretch=NO)
        self.mainTree.column(header[2], width=120, stretch=NO)
        self.mainTree.column(header[3], width=80, stretch=NO)
        self.mainTree.column(header[4], width=40, stretch=NO)
    # insert  column labels
        self.mainTree.heading('#0', text="key")
        self.mainTree.heading(header[0], text=header[0])
        self.mainTree.heading(header[1], text=header[1])
        self.mainTree.heading(header[2], text=header[2])
        self.mainTree.heading(header[3], text=header[3])
        self.mainTree.heading(header[4], text=header[4])

        # load rows
        self.loadTree()
        self.mainTree.grid(row=0, column=0, columnspan=4)

def main():
    bld = Builder()
    bld.build()
    mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()
