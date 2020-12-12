import MySQLdb
"""This program uses the Table and Query classes to generate the SQL
to create the groceries database described in the Facade chapter."""
class Database():
    def __init__(self, *args):
        self._db = MySQLdb.connect(args[0], args[1], args[2])
        self.host=args[0]
        self.userid=args[1]
        self.pwd = args[2]
        self._cursor = self._db.cursor()

    def commit(self):
        self._db.commit()

    def create(self, dbname):
        self.cursor.execute("drop database if exists "+dbname)
        self._cursor.execute("Create database "+ dbname)
        self._dbname = dbname
        self._db=MySQLdb.connect(self.host, self.userid, self.pwd, dbname)
        self.cursor.execute("use "+dbname)
        self._cursor= self._db.cursor()

    def getName(self):
        return self._dbname

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
    def __init__(self, cursor, *qstring):
        self.qstring = qstring[0]
        self.multiple=False
        if len(qstring) >1:
            self.vals = qstring[1]
            self.multiple = True
        self.cursor = cursor

        # executes the query and returns all the results
    def execute(self):
        print (self.qstring)
        if not self.multiple:
            self.cursor.execute(self.qstring)
            rows = self.cursor.fetchall()
            return Results(rows)
        else:
            self.cursor.executemany(self.qstring, self.vals)

    def executeMultiple(self, vals):
        print (self.qstring, vals)
        self.cursor.executemany(self.qstring, vals)

#  Mediator used by columns ad Table class to keep
# the primary key string used in creating the SQL
class Mediator() :
    def __init__(self, db):
        self.db = db
    def setPrimaryString(self, prims):
        self.pstring = prims
    def getPrimaryString(self):
        return self.pstring

# base class Column
class Column():
    def __init__(self, name):
        self._name=name
        self._primary = False

    def isPrimary(self):
       return self._primary

    @property
    def name(self):
        return self._name

# Integer column- may be a primary key
class Intcol(Column)  :
    def __init__(self, name, primary,med:Mediator):
        super().__init__(name)
        self._primary = primary
        self.med = med

    def getName(self):
        idname = self.name+" INT NOT NULL "
        if self._primary:
            self.med.setPrimaryString( "PRIMARY KEY ("+self.name+")")
        return idname
# Float col
class Floatcol(Column):
    def __init__(self, name):
        super().__init__(name)

    def getName(self):
        idname =  self.name + " FLOAT NOT NULL "
        return idname
# character column - length is  the 2nd argument
class Charcol(Column):
    def __init__(self, name, width:int):
        super().__init__(name)
        self.width=width
    def getName(self):
        idname =  self.name + " VARCHAR("+str(self.width)+") NULL "
        return idname
# Table class used to create all the table
class Table():
    def __init__(self, db, name, med:Mediator):
        self.cursor = db.cursor
        self.db = db
        self.tname = name   # first of tuple
        self.colList=[]     # list of column names generated
        self._primarystring = ""
        self.med = med

    @property
    def name(self):     # gets table name
        return self.tname

    # add a column
    def addColumn(self, column):
        self.colList.append(column)

    # creates the sql to make the columbs
    def addRows(self, varnames):
        qry = "insert into "+self.tname +"("
        i = 0
        for i in range(0, len(self.colList)-1):
            c = self.colList[i]
            qry += c.name + ","
        qry += self.colList[-1].name+") values ("
        for i in range(0, len(self.colList) - 1):
            qry += "%s,"
        qry +="%s)"
        query = Query(self.cursor, qry, varnames)
        query.execute()
        self.db.commit()

    # creates the table and columns
    def create(self):
        sql = "create table "+self.db.getName()+"."+ self.name+" ("
        for col in self.colList:
            sql += col.getName()+","

        sql += self.med.getPrimaryString()
        sql +=")"
        print (sql)
        self.cursor.execute(sql)

    # returns a list of columns
    def getColumns(self):
        self.cursor.execute("show columns from " + self.tname)
        self.columns = self.cursor.fetchall()
        return self.columns

# contains the result of a query
class Results():
    def __init__(self, rows):
        self.rows = rows

    def getRows(self):
        return self.rows

# program starts here
class Builder():
    def build(self):
        db = Database("localhost", "newuser", "new_user")
        db.create("groceries")
        med = Mediator(db)  #keeps the primary key string

        # Create food table
        foodtable = Table(db, "foods", med)
        foodtable.addColumn(Intcol("foodkey", True, med))  # primary key
        foodtable.addColumn (Charcol("foodname", 45))
        foodtable.create()

        vals = [(1, 'Apples'),   (2, 'Oranges'),
               (3, 'Hamburger'), (4, 'Butter'),
               (5, 'Milk'),      (6, 'Cola'),
               (7, 'Green beans')
               ]
        foodtable.addRows(vals)

        # create store table
        storetable  = Table(db, "stores", med)
        storetable.addColumn( Intcol("storekey", True, med))  # primary key
        storetable.addColumn(Charcol("storename", 45))
        storetable.create()

        vals = [(1, 'Stop and Shop'),
                (2, 'Village Market'),
                (3, 'Shoprite')]
        storetable.addRows(vals)

        # create price table
        pricetable = Table(db, "prices", med)
        pricetable.addColumn(Intcol("pricekey", True, med))  # primary key
        pricetable.addColumn(Intcol("foodkey", False, med))
        pricetable.addColumn(Intcol("storekey", False, med))
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