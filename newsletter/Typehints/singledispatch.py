from functools import singledispatchmethod

class Adder:
    @singledispatchmethod
    def __init__(self, aval: float):  # init with a float
        self.aval = aval
        self.bval = 0

    @__init__.register(str)           # init with a string
    def _from_str(self, str):
        self.aval = float(str)

    @singledispatchmethod
    def add(self, bval: float)->float:  # add a float
        self.bval=bval
        return self.aval+self.bval

    @add.register
    def _(self, sval: str)->float:      # add a string
        self.bval = float(sval)
        return self.aval + self.bval

addr =  Adder(20)
theSum = addr.add(30)
print(theSum)

addr =  Adder("21")
theSum = addr.add(30)
print(theSum)

addr =  Adder("22")
theSum = addr.add("32")
print(theSum)
