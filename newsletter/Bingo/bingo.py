import random
import tkinter

# Bingo column class
class BingoCol():
    def __init__(self, name, min, max):
        self.name = name     # save the column name
        bset=set()           # create an empty set
        while len(bset) < 5: # add  random numbers
            num = random.randint(min,max)
            bset.add(num)
        self.bara = list(bset)    # convert to list
        random.shuffle(self.bara) # and shuffle the numbers

    # return a string value for each entry
    def getRowval(self, i):
         return str(self.bara[i])

class NBingoCol(BingoCol):
    def __init__(self, name, min,max):
        super().__init__(name,min,max)

    # return number except for row 2
    def getRowval(self, i):
        if(i==2):
            return "Free"
        else:
            return str(self.bara[i])
def main():

    cols=[]
    cols.append(BingoCol("B", 1, 15))
    cols.append(BingoCol("I", 16, 30))
    cols.append(NBingoCol("N", 31, 45))
    cols.append(BingoCol("G", 46, 60))
    cols.append(BingoCol("O", 61, 75))

    for r in cols:
        print(f"{r.name:>8s}", end="")
    print()
    for i in range(0,5):
        for r in cols:
            print(f"{r.getRowval(i):>8s}", end="")
        print()


# starts here
if __name__ == '__main__':
    main()