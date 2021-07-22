import tkinter as tk
from tkinter import filedialog
from tkinter import *

class DButton(Button):
    def __init__(self, master=None,  **kwargs):
        super().__init__(master, command=self.comd, **kwargs)

    def comd(self):pass

# Derived Listbox with 3 convenience methods
class DListbox(Listbox):
    def __init__(self, root):
        super().__init__(root)
     # Get the current selected text
    def getSelected(self):
        selection = self.curselection()
        selindex = selection[0]
        return self.get(selindex)
    # delete the selected row
    def deleteSelection(self):
        selection = self.curselection()
        selindex = selection[0]
        self.delete(selindex)
    # Insert at bottom of list
    def insertAtEnd(self, text):
        self.insert(END, text)

class EntryButton(DButton):
    def __init__(self, root, buildui, **kwargs):
        super().__init__(root, text="Enter")
        self.buildui = buildui
    # copies entry field into left lsit
    def comd(self):
        entry = self.buildui.getEntry()
        text = entry.get()
        leftList = self.buildui.getLeftList()
        leftList.insertAtEnd(text)
        entry.delete(0, END) # clears entry

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
    # copies selected line into right list
    def comd(self):
        self.leftlist =self.buildui.getLeftList()
        self.seltext = self.leftlist.getSelected()
        self.rightlist = self.buildui.getRightList()
        self.rightlist.insertAtEnd(self.seltext)
        # and deletes from left
        self.leftlist.deleteSelection()


class BuildUI():
    def __init__(self, root):
        self.root = root

    def build(self):
        self.root.geometry("300x200")
        self.root.title("Two lists")
        self.entry= Entry(self.root)
        self.entry.grid(row=0, column=0)
        self.leftList = DListbox(self.root)
        self.leftList.grid(row=1, column=0, rowspan=4)

        self.entryButton =  EntryButton(self.root, self)
        self.entryButton.grid(row=0, column=1, sticky=W)

        self.moveButton = MoveButton(self.root, self)
        self.moveButton.grid(row=1, column=1)

        self.rightList = DListbox(self.root)
        self.rightList.grid(row=1, column=2, rowspan=4)

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
