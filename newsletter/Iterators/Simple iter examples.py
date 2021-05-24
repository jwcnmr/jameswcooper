# Iterate through an array
people = ["Fred", "Mary", "Sam"]
for p in people:
    print (p)

# Create your own iterator using iter()
pIter = iter(people)

try:
    while p != None:
        p = next(pIter)
        print (p)
except StopIteration:
    pass

# iterate to get elements and store them
person = ["Fred", "Smith", "80901210"]
pIter = iter(person)

frname = next(pIter)
lname = next(pIter)
serial = next(pIter)
print(frname, lname, serial)