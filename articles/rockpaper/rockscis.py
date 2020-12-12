# Rock paper scissors
from random import randint
"""
base Player class allows keyboard entry
of R, P or S for Rock, Paper or Scissors
or Q to quit.
"""
class Player():
    moves=("P", "R", "S")   #tuple of legal play characters

    def __init__(self, name):
        self.name = name    #initialize name,quit, and count
        self.quit = False
        self.wincount = 0   #counter of wins

    def playit(self):
        legal = False
        while not legal:
            self.play = input("enter play (P, R, S): ").upper()
            if self.play=="Q":
                self.quit = True
            legal = self.play in Player.moves or self.quit
    # the number of wins is counted here
    def countWin(self):
        self.wincount += 1

"""
AutoPlayer derived from Player
The playit method creates a random number
between 0 and 2 for Paper, Rock or Scissors
"""
class AutoPlayer(Player):
    def __init__(self, name):
        super().__init__(name) # pass the name into the parent class

    def playit(self):
        playval = randint(0, 2)     # select 0, 1 or 2
        self.play = Player.moves[playval] # get that play from the tuple
        # print out what it has selected
        print(self.name + " selects " + self.play)

"""
The Winner class checks for ties and looks up the wins
in the game tuple. It checks first the player and then
the AutoPlayer. It also increments the win count for each player
"""
class Winner():
    game= {"RS": "rock breaks scissors",
           "SP": "scissors cuts paper",
           "PR": "paper covers rock"
           }

    def __init__(self, p1, p2):
        # copy variables into class
        # to make this simpler to read
        self.p1 = p1
        self.p2 = p2

    # A winner matches on of the three
    # game dictionary entries abouve
    # we check p1+2 and p2+p1
    def checkWin(self, p1, p2):
        # here are the two outcomes
        # for both player orders
        match1 = p1.play + p2.play
        match2 = p2.play + p1.play
        mesg = Winner.game.get(match1)
        if mesg != None:
            p1.countWin()
            output = p1.name + " win -- "+mesg
        else:
            mesg = Winner.game.get(match2)
            p2.countWin()
            output =  p2.name + " win -- " + mesg
        return output

    def findWin(self):
        if self.p1.play == self.p2.play:
           return "Tie, no winner"
        else:
            return self.checkWin(self.p1,self.p2)

# ---Game starts here
def main():
    # Creates an instance of the Player class (you)
    # abd the AutoPlayer class (me)
    # and runs the game until quit is detected
    # it prints then out the wins for each player
    player1 = Player("You")
    player2 = AutoPlayer("Auto")
    while not player1.quit: #loop until a 'Q' is entered
        player1.playit()
        if not player1.quit:
            player2.playit()
            # compute the winner
            winner = Winner(player1, player2)
            print(winner.findWin()) # print winner

    # print out the wins for each player
    # when you type "q" for quit
    print(player1.name, player1.wincount)
    print(player2.name, player2.wincount)

###  Here we go  ####
if __name__== "__main__":
    main()

