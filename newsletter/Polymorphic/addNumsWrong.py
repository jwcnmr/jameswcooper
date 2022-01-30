"""This example appears to illustrate polymorphic calls to addNums
But it is misleading. Python does not allow tow methods with the same name
and it just keeps the last one it sees.
This looks like polymorphism, but it actually only calls
the second method, which works because float(string) and float(float)
both return floats."""

class Summer():
    def addNums(self, x: float, y: float) ->float:
        return x + y

    def addNums(self, f: float, s: str)->float:
            fsum = f + float(s)
            return fsum
#----------------------------------
def main():
    sumr = Summer()
    print(sumr.addNums(12.0, 2.3))
    print(sumr.addNums(22.3, "13.5"))

###  Here we go  ####
if __name__== "__main__":
    main()