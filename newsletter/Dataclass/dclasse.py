class Employee:
    def __init__(self, frname:str, lname:str, idnum:int):
        self.frname = frname
        self.lname = lname
        self.idnum = idnum

    def nameString(self):
        return self.frname+" "+self.lname\
               +" "+str(self.idnum)

class Employee2:
    def __init__(self, frname: str, lname: str, idnum: int,
                 town='Stamford', state = 'CT', zip='06820'):
        self.frname = frname
        self.lname = lname
        self.idnum = idnum
        self.town = town
        self.state = state
        self.zip = zip

    def nameString(self):
        return self.frname + " " + self.lname \
               + " " + str(self.idnum)

def main():
    emp = Employee('Sarah', 'Smythe', 123)
    print(emp.nameString())

    bill = Employee2('Bill', 'Bogus', 456)
    print(bill.nameString(), bill.town, bill.zip)

    sandy= Employee2('Sandy', 'Zwyzzo', 123, 'Bridgeport')
    print(sandy.nameString(), sandy.town, sandy.zip)

    robert = Employee2('bob', 'simpson', 345, zip= '06840')
    print(robert.nameString(), robert.zip)

if __name__ == '__main__':
    main()
