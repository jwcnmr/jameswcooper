""" Ranked Voting demonstration using tkinter GUI display"""
import random
from dataclasses import dataclass
import tkinter as tk
from tkinter import *
from tkinter.ttk import *

# Command interface
class Command():
    def comd(self):pass

#derived button class with an abstract comd method
class DButton(Button, Command):
    def __init__(self, master,  **kwargs):
        super().__init__(master, command=self.comd,  **kwargs)

# The list of candidates is enclosed
# in this class, and a method for getting one at random
class CandList:
    def __init__(self, num):
        self.num = num
        self.candList = ["Alf", 'Betty','Chaz', 'Dani', 'Edward',
                         'Flossy', 'George', 'Helen','Isaac', 'Jim']

    def getCand(self):
        index = random.randint(0, len(self.candList)-1)
        return self.candList[index]

# Each voter selects up to 10 candidates in rank order
# Here they are chosen at random,
# using a Set to make sure there are no duplicates
class Voter:
    def __init__(self, candList:CandList):
        self.cands = []
        self.candList = candList

    # pick candidates and add them to an array if they
    # are not already in the accompanying Set
    def pickCands(self, num):
        self.num = num
        self.candSet = set()  #empty set
        # get candidates until you have a full list
        while len(self.candSet) < self.num:
            thisCand = self.candList.getCand()
            if thisCand not in self.candSet:
                self.candSet.add(thisCand)
                self.cands.append(thisCand)
    # get a candidate by array index
    def getCand(self, index):
        return self.cands[index]

# the Vote class holds a candidate's name and the vote count
@dataclass
class Vote():
    name: str
    count: int

"""The Mediator controls the interaction between the buttons, 
the Treeview and the Listbox."""
@dataclass
class Mediator:
    candList:CandList
    tree:Treeview

    def setclearButton(self, clearButton:DButton):
        self.clearButton = clearButton

    def setList(self, vlist):
        self.votesList = vlist

    # create list of voters
    def makeVoters(self,max):
        self.voters=[]
        for i in range(0, max):
            v = Voter(self.candList)
            v.pickCands(10)
            self.voters.append(v)

    # get the array of voters
    def getVoters(self):
        return self.voters

    # used in the sort below
    def vcount(self, v:Vote):
        return v.count

    # count the number of first place votes for each candidate
    def countVotes(self):
        self.voteList = []
        for v in self.voters:
            c = v.getCand(0)  # name of 1st choice
            found = False
            for index, v in enumerate(self.voteList):
                if c == v.name:  # if found add to count
                    found = True
                    vote = self.voteList[index]
                    vote.count += 1
            if not found:  # otherwise create a new vote
                v = Vote(c, 1)
                self.voteList.append(v)
            # sort vote list based on count
            self.voteList.sort(key=self.vcount, reverse=True)
        # clear list box
        self.votesList.delete(0,END)
        for v in self.voteList:
            self.votesList.insert(END, v.name+' '+str(v.count))
        return self.voteList

    # reloads the Treeview with new voters and votes
    # and reloads the listbox with total vote count
    def clearClicked(self):
        MAXVOTERS = 200
        self.tree.delete(*self.tree.get_children())
        self.makeVoters(MAXVOTERS)  # create the list of voters
        voters = self.getVoters()
        vlist = self.countVotes()  # count the votes
        self.loadTree()

    # loads the Tree
    def loadTree(self):
        voters = self.getVoters()
        index = 0

        for v in voters:
            #print(v.cands)
            self.tree.insert("", index,
                             text=str(index),
                             values=(v.cands))
            index += 1
        self.countVotes()

    # remove candidate from all voter's lists
    def removeVote(self, vname):
        for v in self.voters:
            cands = v.cands
            for index, c in enumerate(cands):
                if c == vname:
                    cands.pop(index)  # remove that candidate

    # removes the last candidate from all voter's lists
    def nextClicked(self):
        voters = self.voteList
        self.removeVote(voters[len(voters) - 1].name)  # remove least vote getter
        #vlist = self.countVotes()
        self.loadTree()

# clears the screen and reloads
class ClearButton(DButton):
    def __init__(self, root, med, **kwargs):
        super().__init__(root, text="Reload", width=10)
        self.med = med

    def comd(self):
        self.med.clearClicked()

class NextButton(DButton):
    def __init__(self, root, med, **kwargs):
        super().__init__(root, text="Next", width=10)
        self.med = med

    def comd(self):
        self.med.nextClicked()


# Builder creates the GUI
class Builder:
    def __init__(self):
        # create candidate list
        self.candList = CandList(10)

    def build(self):
        root = tk.Tk()
        root.geometry("850x500")
        root.title("Ranked voting")
        frame = Frame(root)
        candList = CandList(10)

        self.mainTree = Treeview(root, height=20)
        self.mainTree["columns"] = ("1", "2", "3", "4", "5", "6", "7", "8", "9", '10')
        self.mainTree.column("#0", width=40, minwidth=20, stretch=NO)  # first name
        self.mainTree.column("1", width=60, stretch=NO)
        self.mainTree.column("2", width=60, stretch=NO)
        self.mainTree.column("3", width=60, stretch=NO)
        self.mainTree.column("4", width=60, stretch=NO)
        self.mainTree.column("5", width=60, stretch=NO)
        self.mainTree.column("6", width=60, stretch=NO)
        self.mainTree.column("7", width=60, stretch=NO)
        self.mainTree.column("8", width=60, stretch=NO)
        self.mainTree.column("9", width=60, stretch=NO)
        self.mainTree.column("10", width=60, stretch=NO)

        self.mainTree.heading('#0', text="key")
        self.mainTree.heading("1", text="1")
        self.mainTree.heading("2", text="2")
        self.mainTree.heading("3", text="3")
        self.mainTree.heading("4", text="4")
        self.mainTree.heading("5", text="5")
        self.mainTree.heading("6", text="6")
        self.mainTree.heading("7", text="7")
        self.mainTree.heading("8", text="8")
        self.mainTree.heading("9", text="9")
        self.mainTree.heading("10", text="10")

        #med.setMainTree(self.mainTree)
        self.mainTree.grid(row=1, column=0, columnspan=4)

        med=Mediator(candList, self.mainTree)
        self.voteList = Listbox(root, height=20)
        self.voteList.grid(row=1, column=5, pady=10, sticky=E)
        med.setList(self.voteList)

        addButton = NextButton(root, med)
        addButton.grid(row=2, column=1, padx=5, pady=10, sticky=E)
        clearButton = ClearButton(root, med)
        clearButton.grid(row=2, column=2, padx=5, pady=10, sticky=W)
        med.setclearButton(clearButton)


def main():

    bld = Builder()
    bld.build()
    mainloop()


###  Here we go  ####
if __name__ == "__main__":
    main()







