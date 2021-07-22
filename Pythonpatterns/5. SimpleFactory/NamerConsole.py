#base Namer class
class Namer():
    def __init__(self):
        self.last=""
        self.first=""

#derived namer class for First <space> Last
class FirstFirst(Namer):
    def __init__(self, namestring):
        super().__init__()
        i = namestring.find(" ")    #find space between names
        if i > 0 :
            names = namestring.split()
            self.first = names[0]
            self.last = names[1]
        else:
            self.last = namestring

#derived Namer class for Last <comma> First
class LastFirst(Namer):
    def __init__(self, namestring):
        super().__init__()
        i = namestring.find(",")  # find comma between names
        if i > 0 :
            names = namestring.split(",")
            self.last = names[0]
            self.first = names[1]
        else:
            self.last = namestring

"""The NameFactory returns an instance of the Namer class that separates first and last names
depending on whether a comma is present"""
class NamerFactory():
    def __init__(self, namestring):
        self.name = namestring
    def getNamer(self):
        i = self.name.find(",") # if it finds a comma
        if i>0:
            return LastFirst(self.name) # get the LastFirst class
        else:
            return FirstFirst(self.name) # else get the FirstFirst

class Builder:
    def compute(self):
        name = ""
        while name != 'quit':
            name = input("Enter name: ")  # get the name string
            # get the Namer Factory and then the namer class
            namerFact = NamerFactory(name)  # get namer factory
            namer = namerFact.getNamer()  # get namer
            print(namer.first, namer.last)

def main():
    bld = Builder()
    bld.compute()

###  Here we go  ####
if __name__ == "__main__":
    main()