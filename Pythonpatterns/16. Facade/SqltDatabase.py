#from GroceryDisplay import Database
from DBObjects import Database, Query, VariableQuery, Table, Primary
import sqlite3

class SqltDatabase(Database):
    def __init__(self, dbname):
        self._db = sqlite3.connect(dbname)
        self._dbname = dbname
        self._cursor = self._db.cursor()

    def commit(self):
        self._db.commit()

    def create(self, dbname):
        pass
    def getTables(self):
        tbQuery = Query(self.cursor,
                        "select name from sqlite_master where type='table'")

        # create array of table objects
        self.tables=[]
        rows = tbQuery.execute().getRows()
        for r in rows:
            self.tables.append(SqltTable(self._db, r))
        return self.tables

# Table class used to create all the table
class SqltTable(Table):
    def __init__(self, db, name):
        self.cursor = db.cursor()
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

    def getColumns(self):
        tn = self.tname[0]
        print(self.tname)
        sql="select name from pragma_table_info('"+tn+"')"
        print(sql)
        self.cursor.execute(sql)
        self.columns = self.cursor.fetchall()
        return self.columns
