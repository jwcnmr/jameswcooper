class Adder:

    # save first value in the initializer
    def __init__(self, aval: int):
        self.aval = aval    # save as instance variable

    # second value entered in add method
    def add(self, bval:int)->float:
        self.bval=bval      # save 2nd as instance variable
        return self.aval+self.bval  #return sum

addr =  Adder(20)       # create the Adder class
theSum = addr.add(30)   # call add with 2nd argument- sum returned
print(theSum)