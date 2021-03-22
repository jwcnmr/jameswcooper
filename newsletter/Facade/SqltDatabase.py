from GroceryDisplay import Database
import sqlite3

class SqltDatabase(Database):
    def __init__(self, dbname):
        self._db = sqlite3.connect(dbname)
        self._cursor = self._db.cursor()
