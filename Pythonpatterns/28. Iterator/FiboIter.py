"""Creates Iterator for Fibonacci series"""

class FiboIter():
    def __init__(self):
        self.current = 0    # initialize variables
        self.prev = 1
        self.secondLast = 0

    def __iter__(self):
        return self         # must return self

    # each iteration computes a new value
    def __next__(self):
        if self.current < 1000:   #but stops at 1000
            self.secondLast = self.prev  # copy n-1st to secondLast
            self.prev = self.current     # copy nth to prev

            # compute next x as sum of previous 2
            self.current = self.prev + self.secondLast
            return self.current
        else:
            raise StopIteration


class Starter():
    def start(self):
        fbi = FiboIter()    # create iterator

        # print out values until 1000 is exceeded
        for val in fbi:
            print(val, end=" ")
        print("\n")

        val = 0
        fbi = FiboIter()
        fbit = iter(fbi)
        while val<1000:
            val = next(fbit)
            print(val, end=" ")


#----------------------------
def main():
    Starter().start()

###  Here we go  ####
if __name__ == "__main__":
    main()