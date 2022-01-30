""" This is a revised version of this class.
Actually Python does not allow multiple methods with the same name
since it uses a one-pass compiler. So the intended polymorphism doesn't actually work.

This example uses the match operator to decide on which operation to carry out.
Note that the list can be any length
"""

class Summer():

    def calcNums(self, oper, f, s)->float:
        fsum = 0
        match oper:
            case '+':
                fsum = float(f) + float(s)
            case '-':
                fsum = float(f) - float(s)
        return fsum


#----------------------------------
def main():
    sumr = Summer()
    print(sumr.calcNums('+', 12.0, 2.3))
    print(sumr.calcNums('-', 22.3, "13.5"))



###  Here we go  ####
if __name__== "__main__":
    main()