"""List comprehension"""
squares = [value**2 for value in range (1,21)]
print(squares)

#equivalent code
squares = []
for value in range(1,21):
    squares.append(value**2)
print (squares)

#conditional comprehension
nlist = [x for x in range(20) if x%2==0]
print (nlist)