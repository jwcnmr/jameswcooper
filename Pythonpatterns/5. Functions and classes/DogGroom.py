"""Illustrates class inheritance using Dog classes"""
#Grooming interface
class Groomable:
    def groom(self):pass
    
# base Dog class
class Dog():
    def __init__(self, name, bark):
        self._name = name 
        self._bark = bark

    def bark(self):
        return self._bark
    

# create a Retriever class based on the simple Dog class
class GoldenRetriever(Dog, Groomable):
    def __init__(self):
        super().__init__("Golden Retriever", "Woof")
    def groom(self):
        print ("combing and brushing")    

# A Great Dane is a bigger dog
class GreatDane(Dog):
    def __init__(self):
        super().__init__("Great Dane", "WOOF")

# starts here
def main():
    my_pekinese = Dog("Pekinese", "yap")  #small dog
    my_retriever = GoldenRetriever()
    my_big_dog = GreatDane()

    print (my_pekinese.bark())
    print (my_retriever.bark())
    print (my_big_dog.bark())
    my_retriever.groom()

###  Here we go  ####
if __name__ == "__main__":
    main()
