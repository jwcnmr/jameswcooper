"""Simple classes for managing a MySQL database
Illustrates the Facade pattern
DBObjects contains only 4 objects: Database, Query, Table and Results
The Query class supports replacement of arguments if the string ?0, ?1
and so forth are in the query. So replaces Apple with Oranges is very simple"""

from DBObjects import *
import tkinter as tk
from tkinter import Listbox, GROOVE, SINGLE, NO, END, mainloop
from tkinter.ttk import Button,Frame, Treeview

from SqltDatabase import SqltDatabase


class DButton(Button):
    def __init__(self, foodquery, builder, master=None, **kwargs):
        super().__init__(master, command=self.comd, text="Get prices", **kwargs)
        self.query = foodquery
        self.builder = builder

    def comd(self):
        foodname = self.builder.getFoodname()
        self.query.insertArgs(foodname)
        results = self.query.execute()
        rows=results.getRows()
        tree = self.builder.getTree()
        # delete old tree entries
        for i in tree.get_children():
            tree.delete(i)

        index=0
        for row in rows:
            tree.insert("", index, text=row[0], values=(row[1], row[2]))
            index += 1


# Builds the user interface
class Builder():
    def __init__(self, root):
        self.root = root

    def build(self):
        #db = Database("localhost", "newuser", "new_user","groceries")
        db = SqltDatabase("groceries.db")
        self.cursor = db.cursor
        print(self.cursor)
        self.cursor.execute("select name from sqlite_master where type='table'")
        rows = self.cursor.fetchall()
        for r in rows:
            print("".join(r))


        qstring = ("select foods.foodname, stores.storename, prices.price from  prices "+
        "join foods on (foods.foodkey=prices.foodkey) "+
        "join stores on  (stores.storekey = prices.storekey ) "+
        "where foods.foodname=?0 order by price")
        # create the query with replaceable argument
        self.foodQuery = VariableQuery (self.cursor, qstring)

        self.root.geometry ("400x300")
        self.root.title("Grocery queries")

        lframe = Frame(self.root,borderwidth=3, relief=GROOVE)
        lframe.grid(row=0, column=0 )
        self.leftlist= Listbox(lframe, selectmode=SINGLE)
        self.leftlist.pack()
        self.leftlist.bind('<<ListboxSelect>>', self.lbselect)

        midframe = Frame(self.root, borderwidth=3, relief=GROOVE)
        midframe.grid(row=0, column=1)
        self.midlist = Listbox(midframe, selectmode=SINGLE)
        self.midlist.pack()
        self.midlist.bind('<<ListboxSelect>>', self.mbselect)

        rightframe = Frame(self.root, borderwidth=3, relief=GROOVE)
        rightframe.grid(row=0, column=2)
        self.rightlist = Listbox(rightframe, selectmode=SINGLE)
        self.rightlist.pack()

        queryButton = DButton(self.foodQuery, self)
        queryButton.grid(row=5, column=0, columnspan=3)

        # header and columns for tree view
        self.tree = Treeview(self.root)
        self.tree.grid(row=6, column=0, columnspan=3)
        self.tree["columns"] = ("store", "price")
        self.tree.column("#0", width=100, minwidth=100, stretch=NO)
        self.tree.column("store", width=100, minwidth=50, stretch=NO)
        self.tree.column("price", width=50, minwidth=50, stretch=NO)

        self.tree.heading('#0', text='Food')
        self.tree.heading('store', text='Store')
        self.tree.heading('price', text='Price')

        # load table names into left listbox
        self.tables = db.getTables()
        for t in self.tables:
            self.leftlist.insert(END, t.name)

    # Returns foodname  selected in right list, or "apples" if none selected
    def getFoodname(self):
        index = self.rightlist.curselection()
        if len(index) >0:
            foodname:str = self.rightlist.get(index[0])
        else:
            foodname ="apples"
        return foodname

    # return tree for use in query
    def getTree(self):
        return self.tree

    # left list box selected
    # list columns of selected table in middle listbox
    def lbselect(self, evt):
        index=self.leftlist.curselection()
        if len(index)>0:
            self.table = self.tables[index[0]]
            cols = self.table.getColumns()
            self.midlist.delete(0, END)
            for c in cols:
                self.midlist.insert(END, c[0])

    # middle list box has been selected
    # get column contens and display in right listbox
    def mbselect(self, evt):
        index = self.midlist.curselection()
        if len(index) > 0:
            midname = self.midlist.get(index[0])
            rows = self.table.getColumnContents(midname)
            self.rightlist.delete(0, END)
            for r in rows:
                self.rightlist.insert(END, r[0])


# --program starts here---
def main():
    root = tk.Tk()
    bui = Builder(root)
    bui.build()
    mainloop()

###  Here we go  ####
if __name__ == "__main__":
    main()