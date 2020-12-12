"""Simple classes for managing a MySQL database
Illustrate the Facade pattern
It contains only 4 objects: Database, Query, Table and Results
The Query class supports replacement of arguments if the string ?0, ?1
and so forth are in the query. So replaces Apple with Oranges is very simple"""

import MySQLdb
from tkinter import ttk, messagebox
import tkinter as tk
from tkinter import *
from tkinter.ttk import *

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

class Database():
    def __init__(self, server, user, pwd, dbname):
        self._db = MySQLdb.connect(server, user, pwd, dbname)
        self._cursor = self._db.cursor()

    @property
    def cursor(self):
        return self._cursor

    def getTables(self):
        self._cursor.execute("show tables")

        # create array of table objects
        self.tables = []
        rows = self._cursor.fetchall()
        for r in rows:
            self.tables.append(Table(self._cursor, r))
        return self.tables

# Query object makes queries and returns Results
class Query():
    def __init__(self, cursor, qstring):
        self.qstringMaster = qstring  #master copy
        self.qstring = self.qstringMaster
        self.cursor = cursor

    # copies master and inserts arguments into it
    def insertArgs(self, *args):
        index = 0
        self.qstring = self.qstringMaster
        # replaces ?0, ?1 etc with the provided args
        # to create a revised query
        for arg in args:
            tempstr = "?" + str(index)
            self.qstring = self.qstring.replace(tempstr, "'" + arg + "'")
            index += 1

    # executes the query and returns all the results
    def execute(self):
        print (self.qstring)
        self.cursor.execute(self.qstring)
        rows = self.cursor.fetchall()
        return Results(rows)

    #executes the query and returns only the first result
    def executeFetchone(self):
        self.cursor.execute(self.qstring)
        rows = self.cursor.fetchone()
        return Results(rows)

    # fetches the next result
    def fetchOne(self):
        rows = self.cursor.fetchone()
        return Results(rows)

    #fetches up to max more results
    def fetchMany(self, max):
        rows = self.cursor.fetchmany(max)
        return Results(rows)

# Represents a database table
class Table():
    def __init__(self, cursor, name):
        self.cursor = cursor
        self.tname = name[0]    # first of tuple
        # get column names
        self.cursor.execute("show columns from " + self.tname)
        self.columns = self.cursor.fetchall()

    @property
    def name(self):     # gets table name
        return self.tname

    # returns a list of columns
    def getColumns(self):
        return self.columns

    # get contents of a column
    def getColumnContents(self, cname):
        query = Query(self.cursor, "select " +cname+" from "+self.tname)
        results = query.execute()
        return results.getRows()


# contains the result of a query
class Results():
    def __init__(self, rows):
        self.rows = rows

    def getRows(self):
        return self.rows

# Builds the user interface
class Builder():
    def __init__(self, root):
        self.root = root

    def build(self):
        db = Database("localhost", "newuser", "new_user","groceries")
        self.cursor = db.cursor

        qstring = ("select foods.foodname, stores.storename, prices.price from foods,"
                   + "stores, prices where foods.foodkey=prices.foodkey and "
                   + "stores.storekey = prices.storekey and foods.foodname=?0 "
                   + " order by price")
        # create the query with replaceable argument
        self.foodQuery = Query (self.cursor, qstring)

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