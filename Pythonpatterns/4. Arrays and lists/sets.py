# This is a sample Python script.
# Examples of set uses

fruit = {'apples', 'pears', 'lemons'}
fruitPie = {'apples', 'pears'}

# both are true if fruitPie
# is a member of fruit
print (fruitPie.issubset(fruit))
print (fruitPie < fruit)

# combine sets
nuts = {'walnuts', 'pecans'}
granola = fruit | nuts
print(granola)

data = set()    # create an empty set
data.add (2.3)  # and add vales
data.add (4.6)
data.add(7.0)
data.add(2.3)
print (data)