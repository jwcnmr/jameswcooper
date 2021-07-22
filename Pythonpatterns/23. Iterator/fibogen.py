""" Fibonacci iterator using a generator """

def fibo(max=0):
    current, prev = 0, 1    # initialize variables

    while current < max:   #but stops at max
        secondLast, prev = prev, current
        # compute next x as sum of previous 2
        current = prev + secondLast
        yield current       # returns next value in series

fb = fibo(100)
for f in fb:
    print(f, end=', ')
