from datetime import datetime
"""Simple examples from Python Design Patterns"""

squares = [value**2 for value in range (1,11)]
print(squares)

squares = []
for value in range(1,11):
    squares.append(value**2)
print (squares)

nlist = [x**2 for x in range(11) if x%2 == 0]
print (nlist)


start = datetime.now()
for i in range(0, 1_000_000):
    squares = [value ** 2 for value in range(1, 21)]
endt = datetime.now()
print("time=", endt - start)
diff1 = endt - start
print(squares)

# equivalent code
start = datetime.now()
for i in range(0, 1_000_000):
    squares = []
    for value in range(1, 21):
        squares.append(value ** 2)

endt = datetime.now()
print("time=", endt - start)
diff2 = endt - start
print(squares)

"""Examples taken from Programmiz.com"""
start = datetime.now()
#transposed = []
for k in range (0, 1_000_000):
    transposed = []
    matrix = [[1, 2, 3, 4], [4, 5, 6, 8]]

    for i in range(len(matrix[0])):
        transposed_row = []

        for row in matrix:
            transposed_row.append(row[i])
        transposed.append(transposed_row)


endt= datetime.now()
elapsed =  endt-start
print(elapsed)
print(transposed)


start = datetime.now()
for i in range (0, 1_000_000):
    matrix = [[1, 2, 3, 4], [4, 5, 6, 8]]
    transpose = [[row[i] for row in matrix] for i in range(4)]

endt= datetime.now()
elapsed =  endt-start
print(elapsed)
print (transpose)