#decisions in Python

age = 25
hasStudentId = False
"""Demonstration of elif"""
if age < 6:
    price = 0    #child is free
elif age>=6 and age < 60:
    price = 35   #adult price
elif age >= 60 and age < 80:
    price = 30   #senior
elif hasStudentId:
    price = 15   #student
else:
    price = 20   #super Senior 80 or higher
print("price = ", price)




 
"""while loop example"""
i = 0
x = 0
while i < 100:
    x = x + i
    i += 1
print ("x=", x)

"""for loop examples"""
array = [5,12,34,57,22,6]
for x in array:
    print (x)
    
for i in range(0,5):
    print (i, array[i])
    
# elif Demo using range method instead
if age < 6:
    price = 0    #child is free
elif age in range(6,60):
    price = 35   #adult price
elif age in range(60,80):
    price = 30   #senior
elif hasStudentId:
    price = 15   #student
else:
    price = 20   #super Senior 80 or higher
print("price = ", price)

# removing prefix or suffix
town = "Fairfield"
newtown = town.removesuffix("field")
print(newtown)   #Fair
farm = town.removeprefix("Fair")
print(farm)   #field




