"""Some simple functions"""
# return a square of the input value
def sqr(x):
    y = x * x   #square ihe input
    return y    #and return it

def cube(a):
    b = sqr(a) * a  #compute the cube using the square
    return b

"""main program begins here"""
def main():
    xvar = 12
    print(xvar, sqr(xvar), cube(xvar))

###  This is the real entry point ####
if __name__ == "__main__":
    main()                  #call main() here
