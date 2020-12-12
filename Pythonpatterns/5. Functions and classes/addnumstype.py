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
    # This will fail
    val = sumr.addNums('22.3', '13.5')
    print(val)

###  Here we go  ####
if __name__== "__main__":
    main()