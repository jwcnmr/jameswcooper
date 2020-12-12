# base Dog class
class Dog():
    def __init__(self, name, bark):
        self._name = name
        self._bark = bark

    def bark(self):
        return self._bark

# derived class that modifies getBark
class NameDog(Dog):
    def __init__(self, name, bark):
        super().__init__(name, bark)
    def bark(self):
        return self._name +": "+self._bark

# create a dog and print its bark
myNewDog = NameDog("Pekinese", "yap")
print(myNewDog.bark())