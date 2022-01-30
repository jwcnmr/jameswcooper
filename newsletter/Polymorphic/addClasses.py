#base adder class
class Summerf():
    def addNums(self, x: float, y: float) ->float:
        return x + y

class Summers():
    def addNums(self, s1: str, s2: str) -> float:
        fsum = float(s1) + float(s2)
        return fsum

#----------------------------------
def main():
    sumrf = Summerf()
    sumrs = Summers()

    print(sumrf.addNums(12.0, 2.3))
    print(sumrs.addNums(22.3, "13.5"))

###  Here we go  ####
if __name__== "__main__":
    main()
