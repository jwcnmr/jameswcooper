import tkinter as tk
from random import randint
from tkinter import *
from tkinter.ttk import *

class ChoiceButton(Radiobutton):
    gvar = None  # will be set to an IntVar

    def __init__(self, rt, label, index):
        super().__init__(rt, text = label,
                         variable =ChoiceButton.gvar,
                         value=index)
        self.text = label
        self.index=index

class Player():
    moves=("P", "R", "S")   #tuple of legal play characters

    def __init__(self, name):
        self.name = name
        self.quit = False
        self.wincount = 0   #counter of wins

    # play one game
    def playit(self):
        playval = ChoiceButton.gvar.get()
        index  = int(ChoiceButton.gvar.get())
        self.play = Player.moves[index]

    def countWin(self):
        self.wincount += 1

class AutoPlayer(Player):
    def __init__(self, name, list):
        super().__init__(name)
        self.list = list

    def playit(self):
        playval = randint(0, 2)
        self.play = Player.moves[playval]
        self.list.insert(END, self.name + " selects " + self.play)
        self.list.yview(END)

class Winner():
    game= {"RS": "rock breaks scissors",
           "SP": "scissors cuts paper",
           "PR": "paper covers rock"
           }

    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def checkWin(self, p1, p2):
        match1 = p1.play + p2.play
        match2 = p2.play + p1.play
        mesg = Winner.game.get(match1)
        if mesg != None:
            p1.countWin()
            return p1.name + " win -- "+mesg
        else:
            mesg = Winner.game.get(match2)
            p2.countWin()
            return p2.name + " win -- " + mesg

    def findWin(self):
        if self.p1.play == self.p2.play:
           return "Tie, no winner"
        else:
            return self.checkWin(self.p1,self.p2)


class Builder():

    # play one game
    def playgame(self):
       self.player1.playit()    # read buttons
       self.player2.playit()    # calc random play
       # compute winner
       winner = Winner(self.player1, self.player2)
       self.mesgList.insert(END, winner.findWin())  # print winner
       self.mesgList.yview(END) #move to bottom of list
       # show current score
       self.scoreLabel.config(text="You: "
                                +str(self.player1.wincount)+"--- Auto: "
                                +str(self.player2.wincount))

    def build(self):
        root = tk.Tk()
        root.geometry("300x200")
        root.title("Rock paper scissors")

        # create a label frame for the radio buttons
        lbf = LabelFrame(root, text="Plays")
        lbf.grid(row=0, column=0, rowspan=3, pady=10, padx=10)

        # create 3 radio buttons, but set none as selected
        ChoiceButton.gvar = IntVar()
        ChoiceButton.gvar.set(-1)   # none selected
        ChoiceButton(lbf, "Paper", 0).grid(row=0, column=0, sticky=W)
        ChoiceButton(lbf,"Rock", 1).grid(row=1, column=0,sticky=W)
        ChoiceButton(lbf, "Scissors", 2).grid(row=2,column=0, sticky=W)

        # create Play button - calls playgame method
        playButton = Button(root,text="Play", command=self.playgame)
        playButton.grid(row=3,column=0,pady=20)

        # create score label
        self.scoreLabel = Label(text="scores", foreground="blue")
        self.scoreLabel.grid(row=0, column=1)

        # create listbox
        self.mesgList = Listbox(root, width=30)
        self.mesgList.grid(row=1, column=1, rowspan=3)

        # create two players
        self.player1 = Player("You")
        self.player2 = AutoPlayer("Auto", self.mesgList)
        mainloop()


##  Here we go  ####
if __name__== "__main__":
    bld = Builder()
    bld.build()
