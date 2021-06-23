from dataclasses import dataclass

@dataclass
class Employee:
    frname: str
    lname: str
    idnum: int

    def nameString(self):
        return self.frname+" "+self.lname\
               +" "+str(self.idnum)

@dataclass
class Employee2:
    frname: str
    lname: str
    idnum: int
    town: str = "Stamford"
    state: str = 'CT'
    zip: str = '06820'

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


