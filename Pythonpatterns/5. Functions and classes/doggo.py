'''Dog class'''
class Dog():
    def __init__(self, weight):  # the Dog starts here
        self.weight = weight     # copy weight into this instance
        self._bark = "yap"        # default is small dog
        # Decide what kind of bark to store
        if weight > 15 and weight < 100:
            self._bark = "woof"   #larger dog
        elif weight > 110:
            self._bark = "WOOF!"  #really big dog

    def getBark(self):           # returns type of bark
        return self._bark


'''------main program-------'''


def main():
    pekinese = Dog(10)        # create 3 Dog instances
    retriever = Dog(85)
    greatDane = Dog(175)

    print(pekinese.getBark())  # see how they bark
    print(retriever.getBark())
    print(greatDane.getBark())


###  Here we go  ####
if __name__ == "__main__":
    main()
