from tkinter import ttk
from tkinter import *
from tkinter.ttk import *

class Bridger(Frame):
    def addData(self):pass

class VisList():
    def addLines(self): pass
    def removeLine(self): pass

# Listbox visual list
class LbVisList(Listbox, VisList):
    def __init__(self, frame ):
        super().__init__(frame)

    def addLines(self, prodlist):
        for prod in prodlist:
            self.insert(END, prod.name)

# Treelist (table) visual list
class TbVisList(Treeview, VisList)    :
    def __init__(self, frame ):
        super().__init__(frame)
        self["columns"] = ("quantity")
        self.column("#0", width=150, minwidth=100, stretch=NO)
        self.column("quantity", width=50, minwidth=50, stretch=NO)

        self.heading('#0', text='Part')
        self.heading('quantity', text='Qty')

        self.index = 0

    def addLines(self, prodlist):
        for prod in prodlist:
            self.insert("", self.index, text=prod.name,
                             values=(prod.count))
            self.index += 1


# General bridge between data any any VisList class
class ListBridge(Bridger):
    def __init__(self, frame, vislist):
        self.list = vislist
        self.list.pack()

    # adds the list of Products into any VisList
    def addData(self, products):
        #for prod in products:
        self.list.addLines( products)

# represents one product: name and quantity
class Product():
    def __init__(self, nstring):
        # splits the string into two parts
        strings =nstring.split("--")    # at the dashes
        self.name = strings[0].strip()
        self.count= strings[1].strip()

# creates an array of Product objects
class Products():
    def read(self, fname):
        with open (fname) as self.fobj:
            self.contents = self.fobj.readlines()
        i = 0
        self._products=[]
        for line in self.contents:
            prod = Product(line)
            self._products.append(prod)

    # returns the array of Products
    def getProducts(self):
         return self._products

# creates the user interface
class BuildUI():
    def build(self):
        root = Tk()
        root.geometry("335x200")  # this one is pretty confusing
        root.title("Parts list")  # title only shows if window is wide enough
        prod = Products()
        prod.read( "products.txt")

        # creates the left frame
        self.lframe = Frame(root, width=200, borderwidth=2,relief=GROOVE)
        self.leftlabel = Label(self.lframe, text="Customer view")
        self.leftlabel.pack(fill=X)

        self.vislist = LbVisList(self.lframe)
        self.lbridge = ListBridge(self.lframe, self.vislist)
        self.lbridge.addData(prod.getProducts())
        self.lframe.grid(row=0, column=0, sticky=NW)

        # creates the right frame
        self.rframe = Frame(root, borderwidth=2,relief=GROOVE)
        self.rframe.grid(row=0, column=1, sticky=E)
        self.rlabel = Label(self.rframe, text="Executive view")
        self.rlabel.pack(fill=X)

        # right frame contains a table
        # managed by the TbVisliat class
        self.rvislist = TbVisList(self.rframe)
        self.rlb = ListBridge( self.rframe, self.rvislist)
        self.rlb.addData(prod.getProducts())
#----------------------------------
def main():
    BuildUI().build()
    mainloop()

###  Here we go  ####
if __name__== "__main__":
    main()