""" Ranked Voting demonstration"""
import random
from dataclasses import dataclass

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

# Builder creates the voters
class Builder:
    def __init__(self):
        # create candidate list
        self.candList = CandList(10)

    def makeVoters(self,max):
        self.voters=[]
        for i in range(0, max):
            v = Voter(self.candList)
            v.pickCands(10)
            self.voters.append(v)

    # get the array of voters
    def getVoters(self):
        return self.voters

    def vcount(self, v:Vote):
        return v.count

    # count the number of first place votes for each candidate
    def countVotes(self):
        self.voteList = []
        for v in self.voters:
            c = v.getCand(0)
            j=0
            found =  False
            while j < len(self.voteList) and not found:
                found = c== self.voteList[j].name
                if not found:
                    j += 1
            if found:
                vote = self.voteList[j]
                vote.count +=1
            else:
                v = Vote(c,1)
                self.voteList.append(v)
            self.voteList.sort(key=self.vcount, reverse=True)
        for v in self.voteList:
            print(v.name, v.count)
        return self.voteList

    # remove candidate from all voter'sl ists
    def removeVote(self, vname):
        for v in self.voters:
            found = False
            j = 0
            cands = v.cands
            while j < len(cands) and not found:
                found = cands[j] == vname
                if not found:
                    j += 1
            if found:
                cands.pop(j)    # remove a candidate


def main():
    MAXVOTERS=1000
    bld = Builder()
    bld.makeVoters(MAXVOTERS)   # create the list of voters
    voters = bld.getVoters()
    vlist = bld.countVotes()    #count the votes
    print()
    # now reduce the condidates until one of them has a majority
    while vlist[0].count < MAXVOTERS/2:
        bld.removeVote(vlist[len(vlist)-1].name) #remove least vote getter
        #bld.removeVote(vlist[0].name) # remove top vote getter
        vlist = bld.countVotes()
        print()


###  Here we go  ####
if __name__ == "__main__":
    main()







