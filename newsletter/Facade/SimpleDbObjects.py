import MySQLdb

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

        # executes the query and returns all the results
    def execute(self):
        print (self.qstring)
        self.cursor.execute(self.qstring)
        rows = self.cursor.fetchall()
        return Results(rows)

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
# contains the result of a query
class Results():
    def __init__(self, rows):
        self.rows = rows

    def getRows(self):
        return self.rows

# --program starts here---
def main():
    db = Database("localhost", "newuser", "new_user", "groceries")

    # print out table names
    tables = db.getTables()
    for t in tables:
        print (t.name)

    qstring = ("""select foods.foodname, stores.storename, 
prices.price from  prices 
join foods on (foods.foodkey=prices.foodkey) 
join stores on  (stores.storekey = prices.storekey )
where foods.foodname='apples'  order by price""")

    # create and execute the query
    foodQuery = Query(db.cursor, qstring)
    result = foodQuery.execute()
    rows = result.getRows()
    for r in rows:
        print(r)


###  Here we go  ####
if __name__ == "__main__":
    main()