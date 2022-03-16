""" This is a revised version of this class.
Actually Python does not allow multiple methods with the same name
since it uses a one-pass compiler. So the intended polymorphism doesn't actually work
without the use of the multimethod library as shown below.
"""
from multimethod import multimeta

class Summer(metaclass=multimeta):
    def addNums(self, x: float, y: float) ->float:
        print("f,f")
        return x + y

    def addNums(self, f: float, s: str)->float:
        print('f,s')
        fsum = f + float(s)
        return fsum

    def addNums(self, s1: str, s2: str)->float:
        print('s,s')
        return float(s1) + float(s2)
#----------------------------------
def main():
    sumr = Summer()
    print(sumr.addNums(12.0, 2.3))
    print(sumr.addNums(22.3, "13.5"))
    # This will fail, but this version could be added
    val = sumr.addNums('22.5', '13.5')
    print(val)

###  Here we go  ####
if __name__== "__main__":
    main()