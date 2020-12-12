"""Illustration of Singleton
Derived, in part, from example on tutorialspoint.com"""
class SingletonException(Exception):
    def __init__(self, message):
        # Call the base class constructor with the parameters it needs
        super().__init__(message)

class Singleton:
    __instance = None

    # static method declared here
    @staticmethod
    def getInstance():
        if Singleton.__instance == None:
            Singleton()
        return Singleton.__instance

    def getName(self):
        return self.name

    def __init__(self, name):
        if Singleton.__instance != None:
            raise SingletonException("This class is a singleton!")
        else:
            Singleton.__instance = self
            self.name = name
            print("creating: "+ name)
#  ------------------
def main():
    try:
        al = Singleton("Alan")
        bo = Singleton("Bob")
    except SingletonException as e:
        print("two instances of a Singleton")
        details = e.args[0]
        print(details)
    else:
        print (al.getName())
        print(bo.getName())


###  Here we go  ####
if __name__ == "__main__":
    main()
