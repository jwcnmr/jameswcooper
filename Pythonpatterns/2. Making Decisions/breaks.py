xarray= [5,7,4,3,9,12,6]
sum = 0 
for x in xarray:
    sum += x
    if sum > 16:
        break     #leave loop 
    print (sum)
    
# same code without break    
sum = 0 
for x in xarray:
    sum += x
    if sum <= 16:
        print (sum)    
   
# using quit flag   
sum = i = 0
quit = False
while sum <=16 and not quit:
    sum += xarray[i]
    i += 1
    quit = sum >= 16
    print (sum)
   
# reset quit on sum   
sum = i = 0
quit = False
while not quit:
    sum += xarray[i]
    print(sum)
    i += 1
    quit = sum >= 16

# use iterator
xiter = iter(xarray)
sum=0
while sum < 16:
    sum += next(xiter)
    print(sum)