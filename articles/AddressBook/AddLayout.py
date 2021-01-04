"""
A simple Address Book program
that allows editing, addition and deletion.
The Person class is one entry and
NameList is the collection of Person objects.
The listbox and buttons all interact
through a Mediator Design Pattern.
"""
import tkinter as tk
from tkinter import *


# derived button is alwyas 8 chars wide
# with simplified enable and disable methods
class DButton(Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, width=8, **kwargs)

    def enable(self):
        self['state'] = NORMAL

    def disable(self):
        self['state'] = DISABLED


# One person
class Person():
    def __init__(self, nameArray):
        self.name = nameArray[0]
        self.phone = nameArray[1]


# a collection of address entries
class NameList():
    def __init__(self, narray):
        self.names = []
        for nm in narray:
            p = Person(nm)
            self.names.append(p)
    # add a person
    def add(self, person):
        self.names.append(person)
    # delete a person
    def delete(self, index):
        self.names.pop(index)


# all these labels are blue
class BlueLabel(Label):
    def __init__(self, root, nm):
        super().__init__(root, text=nm, fg='blue')


# Mediator handles button and listbox interactions
class Mediator():
    # class level variable
    # array of name arrays
    contactlist = [
        ['Perry Mason', '3176738493'],
        ['David Smith', '2684430000'],
        ['Malcolm Kane', '4338354432'],
        ['Peter Maur', '6834552341'],
        ['Roger Krager', '5234852689'],
        ['Johanna Shaw', '2119876543'],
    ]

    def __init__(self, lb):
        self.listbox = lb
        self.curindex = 0

    def setEntries(self, nm, ph):
        self.nmEntry = nm
        self.phEntry = ph

    def setNamelist(self, nl):
        self.nameList = nl

    # adds a new Person and updates the display
    def addName(self):
        nm = self.nmEntry.get()
        ph = self.phEntry.get()
        if len(nm) > 0:
            p = Person((nm, ph))
            self.nameList.add(p)
            self.listbox.insert(END, p.name)

    # clears the name and phone fields
    def clearFields(self):
        self.nmEntry.delete(0, END)
        self.phEntry.delete(0, END)

    # clears the fields and enables and disables buttons
    def clearFN(self):
        self.add.enable()
        self.clearFields()
        self.update.disable()
        self.delete.disable()

    # Clicking list puts name and phone in entry fields
    def listClicked(self, evt):
        index = self.listbox.curselection()
        if len(index) > 0:
            i = int(index[0])
            self.curindex = i
            person = self.nameList.names[i]
            self.clearFields()
            self.nmEntry.insert(END, person.name)
            self.phEntry.insert(END, person.phone)
            self.delete.enable()
            self.update.enable()
            self.add.disable()

    # redraws changed list
    def refreshList(self):
        self.listbox.delete(0, END)
        for p in self.nameList.names:
            self.listbox.insert(END, p.name)


    # deletes one person
    def deletePerson(self):
        self.nameList.delete(self.curindex)
        self.refreshList()
        self.clearFields()

    # changes one name
    def updatePerson(self):
        person = self.nameList.names[self.curindex]
        person.name = self.nmEntry.get()
        person.phone = self.phEntry.get()
        self.refreshList()

    # restores the original name list
    def resetNames(self):
        self.nameList = NameList(Mediator.contactlist)
        self.refreshList()
        self.clearFields()

    # copy all button references into Mediator
    def setButtons(self, clear, add, update, delete, reset):
        self.clear = clear
        self.add = add
        self.update = update
        self.delete = delete
        self.reset = reset
        self.delete.disable()
        self.update.disable()


# constructs the layout
class BuildUI():

    def __init__(self, root):
        self.root = root
        root.geometry('400x200')
        root.title('Layout AddressBook')

    def build(self):
        # top left frame holds labels
        # and entry fields
        fr1 = Frame(self.root)
        fr1.grid(row=0, column=0)

        self.nmList = NameList(Mediator.contactlist)
        lb1 = BlueLabel(fr1, "Name")
        lb1.grid(row=0, column=0, sticky="E", pady=5, padx=10)
        self.nmentry = Entry(fr1)
        self.nmentry.grid(row=0, column=1, sticky="W", padx=10, pady=5)

        lb2 = BlueLabel(fr1, "Phone")
        lb2.grid(row=1, column=0, sticky="E", pady=5, padx=10)
        self.phnentry = Entry(fr1)
        self.phnentry.grid(row=1, column=1, sticky="W", padx=10, pady=5)

        # The listbox goes in column 2
        self.lbox = Listbox(self.root)
        self.lbox.grid(row=0, column=2, rowspan=4)

        # create Mediator and tell it about entry fields
        # and the listbox
        med = Mediator(self.lbox)
        med.setEntries(self.nmentry, self.phnentry)
        med.setNamelist(self.nmList)
        self.lbox.bind("<<ListboxSelect>>", med.listClicked)
        med.refreshList()

        # lower frame holds all the buttons
        fr2 = Frame(self.root)
        fr2.grid(row=3, column=0)
        # create the buttons and assign them commands
        self.clrButton = DButton(fr2, text="Clear", command=med.clearFN)
        self.clrButton.grid(row=3, column=0, padx=10)

        self.addButton = DButton(fr2, text="Add", command=med.addName)
        self.addButton.grid(row=3, column=1, padx=10)

        self.updateButton = DButton(fr2, text="Update", command=med.updatePerson)
        self.updateButton.grid(row=4, column=0, pady=5)

        self.deleteButton = DButton(fr2, text="Delete", command=med.deletePerson)
        self.deleteButton.grid(row=4, column=1, pady=5)

        self.resetButton = DButton(fr2, text="Reset", command=med.resetNames)
        self.resetButton.grid(row=5, column=0)

        # tell the Mediator about all the buttons
        med.setButtons(self.clrButton, self.addButton, self.updateButton,
                       self.deleteButton, self.resetButton)
        mainloop()


# main begins here
def main():
    root = tk.Tk()
    builder = BuildUI(root)
    builder.build()


###  Here we go  ####
if __name__ == "__main__":
    main()
