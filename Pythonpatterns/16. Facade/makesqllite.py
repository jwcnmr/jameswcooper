import sqlite3
from DBObjects import Database, Query, Table,Intcol,Primary,Floatcol, Charcol
from DBObjects import Column

"""This program uses the Table and Query classes to generate the SQL
to create the groceries database described in the Facade chapter."""
class SqltDatabase(Database):
    def __init__(self, *args):
        self._db = sqlite3.connect(args[0])
        self._dbname = args[0]
        self._cursor = self._db.cursor()

    def commit(self):
        self._db.commit()

    def create(self, dbname):
        pass



# Table class used to create all the table
class SqltTable(Table):
    def __init__(self, db, name):
        self.cursor = db.cursor
        self.db = db
        self.tname = name   # first of tuple
        self.colList=[]     # list of column names generated
        self._primarystring = ""


    # creates the sql to make the columns--Sqlite differs slightly
    def addRows(self, varnames):
        qry = "insert into "+self.tname +"("
        i = 0
        for i in range(0, len(self.colList)-1):
            c = self.colList[i]
            qry += c.name + ","

        qry += self.colList[-1].name+") values ("
        for i in range(0, len(self.colList) - 1):
            qry += "?,"
        qry +="?);"

        query = Query(self.cursor, qry, varnames)
        print(qry+"\n", varnames)
        query.execute()
        self.db.commit()

    # creates the table and columns
    def create(self):
        sql = "create table " +  self.name + " ("
        for col in self.colList:
            sql += col.getName()+","

        sql += Primary.primaryString
        sql +=");"
        print (sql)
        self.cursor.execute(sql)


# program starts here
class Builder():
    def build(self):
        db = SqltDatabase("groceries.db")
        #db.create("groceries2")
        #med = Mediator(db)  #keeps the primary key string

        # Create food table
        foodtable = SqltTable(db, "foods")
        foodtable.addColumn(Intcol("foodkey", True))  # primary key
        foodtable.addColumn (Charcol("foodname", 45))
        foodtable.create()

        vals = [(1, 'Apples'),   (2, 'Oranges'),
               (3, 'Hamburger'), (4, 'Butter'),
               (5, 'Milk'),      (6, 'Cola'),
               (7, 'Green beans')]

        foodtable.addRows(vals)

        # create store table
        storetable  = SqltTable(db, "stores")
        storetable.addColumn( Intcol("storekey", True))  # primary key
        storetable.addColumn(Charcol("storename", 45))
        storetable.create()

        vals = [(1, 'Stop and Shop'),
                (2, 'Village Market'),
                (3, 'Shoprite')]
        storetable.addRows(vals)

        # create price table
        pricetable = SqltTable(db, "prices")
        pricetable.addColumn(Intcol("pricekey", True))  # primary key
        pricetable.addColumn(Intcol("foodkey", False))
        pricetable.addColumn(Intcol("storekey", False))
        pricetable.addColumn(Floatcol("price"))
        pricetable.create()

        vals = [( 1, 1, 1, 0.27),  (2, 2, 1, 0.36), (3, 3, 1, 1.98),
                (4, 4, 1, 2.39), (5, 5, 1, 1.98),
                (6, 6, 1, 2.65),  (7, 7, 1,  2.29),
                (8, 1, 2, 0.29),  (9, 2, 2,  0.29),
                (10, 3, 2, 2.45), (11, 4, 2,  2.99),
                (12,   5,   2,  1.79), (13,   6,   2,  3.79),
                (14,   7,   2,  2.19), (15,   1,   3,  0.33),
                (16,   2,   3,  0.47),  (17,   3,   3,  2.29),
                (18,   4,   3,  3.29),  (19,   5,   3,  1.89),
                (20,   6,   3,  2.99),  (21,   7,   3,  1.99)
        ]
        pricetable.addRows(vals)


# --program starts here---
def main():
    bld = Builder()
    bld.build()

###  Here we go  ####
if __name__ == "__main__":
    main()