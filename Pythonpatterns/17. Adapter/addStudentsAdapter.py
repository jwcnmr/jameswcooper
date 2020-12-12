import tkinter as tk
from random import *
from tkinter import ttk
from tkinter import *
from tkinter.ttk import *


class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

    def comd(self):pass


class DListbox(Listbox):
    def __init__(self, root):
        super().__init__(root)

    def getSelected(self):
        selection = self.curselection()
        selindex = selection[0]
        return self.get(selindex)

    def deleteSelection(self):
        selection = self.curselection()
        selindex = selection[0]
        self.delete(selindex)

    def insertAtEnd(self, text):
        self.insert(END, text)

class ListboxAdapter(DListbox):
    def __init__(self, root, tree):
        super().__init__(root)
        self.tree = tree
        self.index=1

    # gets the text selected from the tree
    def getSelected(self):
        treerow = self.tree.focus() #get the selected row
        row = self.tree.item(treerow) # returns a dict
        return row.get('text')

    # delete the line selected in the tree
    def deleteSelection(self):
        treerow = self.tree.focus()
        self.tree.delete(treerow)

    # insert a line at the bottom of the treelist
    def insertAtEnd(self, name):
        # create random IQs and scores
        self.tree.insert("", self.index, text=name,
                         values=(Randint.getIQ(self),
                                 Randint.getScore(self)) )
        self.index += 1


class EntryButton(DButton):
    def __init__(self, root, buildui, **kwargs):
        super().__init__(root, text="Enter")
        self.buildui = buildui

    def comd(self):
        entry = self.buildui.getEntry()
        text = entry.get()
        leftList = self.buildui.getLeftList()
        leftList.insertAtEnd(text)
        entry.delete(0, END)

class RestoreButton(DButton):
    def __init__(self, root, buildui, **kwargs):
        super().__init__(root, text="<--Restore")
        self.buildui = buildui

    def comd(self):
        rlist = self.buildui.getRightList()
        seltext = rlist.getSelected()
        leftlist = self.buildui.getLeftList()
        leftlist.insertAtEnd( seltext)
        rlist.deleteSelection()

class MoveButton(DButton):
    def __init__(self, root, buildui, **kwargs):
        super().__init__(root, text="Move-->")
        self.buildui = buildui

    def comd(self):
        self.leftlist =self.buildui.getLeftList()
        self.seltext = self.leftlist.getSelected()
        self.rightlist = self.buildui.getRightList()
        self.rightlist.insertAtEnd(self.seltext)
        self.leftlist.deleteSelection()

# Random number generator
class Randint():
    def __init__(self):
        seed(None, 2)   # set up the random seed

    # compute a random IQ between 115 and 145
    @staticmethod
    def getIQ(self):
        return randint(115,145)
    # compute a random score between 25 and 35
    @staticmethod
    def getScore(self):
        return randint(25,35)


class BuildUI():
    def __init__(self, root):
        self.root = root

    def build(self):
        self.root.geometry("400x200")
        self.root.title("Two lists")
        self.entry= Entry(self.root)
        self.entry.grid(row=0, column=0)
        self.leftList = DListbox(self.root)
        self.leftList.grid(row=1, column=0, rowspan=4)

        self.entryButton =  EntryButton(self.root, self)
        self.entryButton.grid(row=0, column=1, sticky=W)

        self.moveButton = MoveButton(self.root, self)
        self.moveButton.grid(row=1, column=1)

        self.tree = Treeview(self.root)
        self.tree["columns"] = ("iq", "score")
        self.tree.column("#0", width=100, minwidth=100, stretch=NO)
        self.tree.column("iq", width=50, minwidth=50, stretch=NO)
        self.tree.column("score", width=50, minwidth=50, stretch=NO)

        self.tree.heading('#0', text='Name')
        self.tree.heading('iq', text='IQ')
        self.tree.heading('score', text='Score')

        self.rightList = ListboxAdapter(self.root,self.tree)
        self.tree.grid(row=1, column=2, rowspan=4)

        self.restore = RestoreButton(self.root, self)
        self.restore.grid(row=2, column=1)

    def getRightList(self):
        return self.rightList

    def getLeftList(self):
        return self.leftList

    def getEntry(self):
        return self.entry










# program starts here
def main():
    root = tk.Tk()
    bui=BuildUI(root)
    bui.build()
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()
