import MySQLdb

# Open database connection
db = MySQLdb.connect("localhost","newuser","new_user","groceries" )

# prepare a cursor object using cursor() method
cursor = db.cursor()
print (cursor)
# execute SQL query using execute() method.
cursor.execute("""select foods.foodname, stores.storename, 
prices.price from  prices 
join foods on (foods.foodkey=prices.foodkey) 
join stores on  (stores.storekey = prices.storekey )
where foods.foodname='Butter'  order by price""")
row = cursor.fetchone()
while row is not None:
    print(row)
    row = cursor.fetchone()

cursor.execute("show tables")
rows = cursor.fetchall()
for r in rows:
    print(r)

