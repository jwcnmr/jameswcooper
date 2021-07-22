
j = 5                       #an integer
xyz = 273.16                #float type (always double)
TempName = "Celsius"        #a string
cmplx = complex(5.43, 2.22) #a complex  number
temperature = 92.8
hot = temperature > 80      #boolean
hot = "really hot"
gtnum = "lesser"            #now is a string

Π = 3.14159

PI = 3.14159  #float
PI = "cherry" #string 

x = 2
temp = 32.0
z = 9
y = 12
x = x + 3   #can also be written as:
x += 3      #add 3 to x; store result in x

#also with the other basic operations:
temp *= 1.80    #mult temp by 1.80
z -= 7      #subtract 7 from z
y /= 1.3        #divide y by 1.3

"""add 2 numbers together"""
a = 1.75        #assign values
b = 3.46
c = a + b       #add together
#print out sum
print("sum = ", c)

#shift operations
x = 1024
y = x <<2
print (x, y)

# Integer division
x = 4/2
print(x)
x = 5/2
print(x)
x= 5//2
print (x)



x = 12
if 0 < x and x <= 24:
     print ("Time is up")
 
y = 1
if  y > 0 :
    z = x / y
    print("z = ", z)
    
#Python substring using "in"
    if "sam" in "samuel":
        print ("sam is there")
    
#Python single-line comment
'''other Python comment style'''
""" also can go on
for any number of lines"""
    
    
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
    
town = "Fairfield"
newtown = town.removesuffix("field")
print(newtown)   #Fair
farm = town.removeprefix("Fair")
print(farm)   #field

# complex numbers
cmplx = complex(5.43, 2.22)
cmplx2 = 5.5 +2.2j
r = cmplx.real
ipart = cmplx.imag

print (cmplx, cmplx2)
print(r, ipart)
                
                
                
                
                
                
                
                
                
                
                
                
                