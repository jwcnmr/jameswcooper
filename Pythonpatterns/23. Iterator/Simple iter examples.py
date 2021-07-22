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