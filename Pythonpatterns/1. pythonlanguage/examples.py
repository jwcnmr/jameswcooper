
PI = 3.14159  #float
PI = "cherry" #string 


# strings can be enclosed in single
# or double or triple quotes
fstring = "fred"
astring = 'sam'

longstring = """this can even go on for
            several lines"""
print(fstring, astring, longstring)


j = 5                       #an integer
xyz = 273.16                #float type (always double)
TempName = "Celsius"        #a string
cmplx = complex(5.43, 2.22) #a complex  number
temperature = 92.8
hot = temperature > 80      #boolean
hot = "really hot"
gtnum = "lesser"            #now is a string

# Complex numbers
cmplx = complex(5.43, 2.22)
cmplx2 = 5.5 + 2.2j
print(cmplx, cmplx2)

r = cmplx.real
ipart = cmplx.imag
print(r, ipart)


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
if (0 < x) and ( x <= 24):
     print ("Time is up")
 
y = 1
if ( y > 0 ):
    z = x / y
    print("z = ", z)
    
#Python substring using "in"
    if "sam" in "samuel":
        print ("sam is there")
    
#Python single-line comment
'''other Python comment style'''
""" also can go on
for any number of lines"""
    
    
