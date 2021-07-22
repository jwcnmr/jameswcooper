"""Print out Fibonacci series"""
current=0
prev=1
secondLast=0

while current < 1000:  
    print (current, end=" ") #without newline characters
    secondLast = prev        #copy n-1st to secondLast
    prev = current           #copy nth to prev
    current = prev + secondLast #compute next x as sum of previous 2
     