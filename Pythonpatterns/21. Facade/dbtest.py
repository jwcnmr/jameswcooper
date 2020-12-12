import MySQLdb

# Open database connection
db = MySQLdb.connect("localhost","newuser","new_user","groceries1" )

# prepare a cursor object using cursor() method
cursor = db.cursor()

# execute SQL query using execute() method.
cursor.execute("select foods.foodname, stores.storename,"
               + " prices.price from foods, stores, prices where "
               +" foods.foodkey=prices.foodkey"
               +" and stores.storekey = prices.storekey"
               +" and foods.foodname='apples'")

row = cursor.fetchone()
while row is not None:
    print(row)
    row = cursor.fetchone()

cursor.execute("show tables")
rows = cursor.fetchall()
for r in rows:
    print(r)
