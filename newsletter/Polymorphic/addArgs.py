""" This is a revised version of this class.
Actually Python does not allow multiple methods with the same name
since it uses a one-pass compiler. So the intended polymorphism doesn't actually work.

This example uses an argument list and the float operation to convert them all to floats
Note that the list can be any length
"""

class Summer():

    def addArgs(self, *args):
        fsum = 0
        for num in args:
            fsum += float(num)
        return fsum

#----------------------------------
def main():
    sumr = Summer()
    print(sumr.addArgs(12.0, 2.3))
    print(sumr.addArgs(22.3, "13.5"))
    print (sumr.addArgs(31,"13", 22.4, True))


###  Here we go  ####
if __name__== "__main__":
    main()