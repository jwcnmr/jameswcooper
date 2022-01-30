class Summer():
    def addNumsf(self, x: float, y: float) ->float:
        return x + y

    def addNums(self, f: float, s: str)->float:
        if type(s) is float:
            return self.addNumsf(f,s)
        else:
            fsum = f + float(s)
            return fsum

#----------------------------------
def main():
    sumr = Summer()
    print(sumr.addNums(12.0, 2.3))
    print(sumr.addNums(22.3, "13.5"))
    # This will fail
   # val = sumr.addNums('22.3', '13.5')
    #print(val)

###  Here we go  ####
if __name__== "__main__":
    main()
class Summer:
    def __init__(self, x, y):
        self.sum = 0
        self.x = x
        self.y = y
    def add(self):
        pass

"""Adds two numbers (int or float)"""
class SummerNum(Summer):
    def __init__(self, x, y):
        super().__init__(x, y)

    def add(self):
        self.sum = self.x + self.y
        return self.sum
"""Adds any values it can convert to floats"""
class SummerMix(Summer)   :
    def __init__(self, x, y):
        super().__init__(x, y)

    def add(self):
        self.sum = float(self.x) + float(self.y)
        return self.sum

"""Decides which addition class to return"""
class WhichSum:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def isNumber(self, z):
        return (str(z).isnumeric())

    def getSummer(self)->Summer:
        if self.isNumber(self.x) \
                and self.isNumber((self.y)):
            return SummerNum(self.x, self.y)
        else:
            return SummerMix(self.x, self.y)

sf = WhichSum(12.2, '13.4')
adder = sf.getSummer()
print(adder.add())

sf = WhichSum(123, 45.6)
print(sf.getSummer().add())
