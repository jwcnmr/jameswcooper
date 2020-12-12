"""Illustrates class inheritance using Dog classes"""

# base Dog class
class Dog():
    def __init__(self, name, bark):
        self._name = name
        self._bark = bark

    def bark(self):
        return self._bark

# create a Retriever class based on the simple Dog class
class Retriever(Dog):
    def __init__(self):
        super().__init__("Retriever", "Woof")

# A Great Dane is a bigger dog
class GreatDane(Dog):
    def __init__(self):
        super().__init__("Great Dane", "WOOF")

# starts here
def main():
    myPekinese = Dog("Pekinese", "yap")  #small dog
    myRetriever = Retriever()
    myBigDog = GreatDane()

    print (myPekinese.bark())
    print (myRetriever.bark())
    print (myBigDog.bark())

###  Here we go  ####
if __name__ == "__main__":
    main()
