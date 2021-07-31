#from GroceryDisplay import Database
import DBObjects
from DBObjects import Database, Query, VariableQuery, Table, Primary
import pymysql

class MysqlDatabase(Database):
    def __init__(self, host, username, password,dbname):
        self._db = pymysql.connect(host=host, user=username,
                                   password=password, database=dbname)
        self._dbname = dbname
        self._cursor = self._db.cursor()

    def commit(self):
        self._db.commit()

    def create(self, dbname):
        pass

    def getTables(self):
        self._cursor.execute("show tables")

        # create array of table objects
        self.tables = []
        rows = self._cursor.fetchall()
        for r in rows:
            self.tables.append(Table(self._cursor, r))
        return self.tables
# Table class used to create all the table
class Table(DBObjects.Table):
    def __init__(self, cursor, name):
        self.cursor = cursor
        #self.db = db
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
        print(self.tname)
        sql = "show columns from " + "".join(self.tname)
        tquery = Query(self.cursor, sql)
        self.columns = tquery.execute().getRows()
        return self.columns
