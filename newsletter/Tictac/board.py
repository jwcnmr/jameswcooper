import sys
import tkinter as tk
from tkinter import  mainloop, messagebox
""" Tic-tac-toe program using a 3x3 array of tkinter Buttons.
The button labels start as blank (a space) and when clicked 
change to the symbol of the currnent player (X or O)
The buttons are then disabled so they cannot be changed.
After each button click, three methods in the TicBoard class
check for rows, columns and diagonal wins.  
If no wins are found, the program allows more entries,
switching between X and O. When a win is detected a messagebox describes
where that row, column or diagonal is."""

# abstract DButton class contains the comd method
class DButton(tk.Button):
    def __init__(self, master=None, **kwargs):
        super().__init__(master,  command=self.comd, **kwargs)

    def comd(self): pass

# this class represents the 3x3 array of plays as characters
# space, X or O
class Board:
    def __init__(self):
        self.createBoard()

    # create blank board
    def createBoard(self):
        self.board = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]

    # set an element to an X or an O
    def set(self, play, x, y):
        self.board[x][y] = play

    # check all rows for 3 matching plays
    def checkRows(self):
        found = False
        col = 1
        r = 0
        # if the first row element is not a space
        # check to see if the other two match it
        while r <3 and not found:
            play = self.board[r][0]
            if play != ' ':
                found = self.board[r][1] == play and self.board[r][2] == play
            if not found:
                r += 1
        if found:
            return r    #return number of winning row
        else:
            return -1   #or return -1

    # check all columns
    def checkCols(self):
        found = False
        row = 1
        c = 0
        # if the first column element is not a space
        # check to see if the other two match it
        while c <3 and not found:
            play = self.board[0][c]
            if play != ' ':
                found = self.board[1][c] == play and self.board[2][c] == play
            if not found:
                c+= 1
        if found:
            return c    # return number of winning column
        else:
            return -1   # or -1

    # check the left and right diagonal
    def checkDiags(self):
        found = False
        play = self.board[0][0]
        if play != ' ':
            found = play == self.board[1][1] and play == self.board[2][2]
        if found:
            return 1    # left diagonal
        else:
            play = self.board[0][2]
            if play != ' ':
                found = self.board[1][1] == play and self.board[2][0] == play
            if found:
                return 2    # right diagonal
            else:
                return -1   # none fount

# Mediator controls interactions among UI elements
class Mediator:
    def __init__(self, root, buttons, bd):
        self.root = root
        self.buttons = buttons  # button array
        self.board = bd         # board array

    # set to X or O
    def setPlayLabel(self, playlabel):
        self.plabel = playlabel

    def setPlayer(self, txt):
        self.player = txt

    # player switches after each play
    def switchPlayer(self):
        if self.player =='X':
            self.player = 'O'
        else:
            self.player = 'X'
        # show current player in label
        self.plabel.configure(text='Player: '+self.player)

    # make all squares disabled after win is found
    def disableBoard(self):
        for r in range(3):
            for c in range(3):
                butn = self.buttons[r][c]
                butn.disable()
    # start new game by clearing button labels
    # enabling the buttons and
    # setting the board array to all spaces
    def resetBoard(self):
        self.board.createBoard()
        for r in range(3):
            for c in range(3):
                butn = self.buttons[r][c]
                butn.enable()
                butn['text'] = ' '
    # display winning message
    def mesgWin(self, player, text):
        messagebox.showinfo(player+" wins", text)
        self.disableBoard()

    # a button is clicked
    def btClick(self, butn):
        butn['text'] = self.player  # set  button text
        # set board array element to an X or O
        self.board.set(self.player, butn.x, butn.y)

        won = False
        found = self.board.checkRows()
        if found >= 0:
            self.mesgWin(self.player, "Row " + str(found) + ' wins')
            won = True
        if found < 0:
            found = self.board.checkCols()
            if found >=0:
                self.mesgWin(self.player, "Column " + str(found) + ' wins')
                won = True
        if found <0 :
            found = self.board.checkDiags()
            if found == 1:
                self.mesgWin(self.player, 'Left diagonal wins')
                won = True
            if found == 2:
                self.mesgWin(self.player, 'Right diagonal wins')
                won = True
        # disable further play if winning row
        if won:
            self.disableBoard()
        # otherwise switch players
        else:
            self.switchPlayer()

# PlayButton for each of the 9 cells
class PlayButton(DButton):
    def __init__(self, root, med,  x: int, y: int):
        super().__init__(root, width=2)
        self.x = x  # save the coordinates inside the button instance
        self.y = y
        self.med = med
        self.config(font=('Helvetica bold', 26))
    def  disable(self):
        self.configure(state='disabled')
    def enable(self):
        self.configure(state='normal')
    def comd(self):
        self.med.btClick(self)
        self.disable()      # disable each button once it is clicked

# Reset button for new game
class ResetButton(DButton):
    def __init__(self, root, med):
        super().__init__(root, text = 'Reset', width=6)
        self.med = med
    def comd(self):
        self.med.resetBoard()

# creates the user interface
class Builder:
    def __init__(self, root):
        self.root = root
        self.root.geometry("250x350")
        self.root.title('Tic Tac Toe')

        #place holder: they all become PlayButton instances
        self.buttons = [[0,0,0],[1,1,1],[2,2,2]]
        self.bd = Board()
        med = Mediator(root, self.buttons, self.bd)
        med.setPlayer('X')      # start with X as first player
        # create buttons and put in buttons 3x3 array
        for row in range(0,3):
            for col in range(0,3):
                b= PlayButton(root, med, row,col)
                b.grid(row =row,column=col, ipadx=15, ipady=15)
                self.buttons[row][col]=b
        playLabel = tk.Label(root, text="Player: X")
        playLabel.grid(row=4, column=1)
        med.setPlayLabel(playLabel) # show which player is up
        rb =ResetButton(root, med)  # putreset button beside it
        rb.grid(row=4, column=2)
# ----------------------------
def main():
    root = tk.Tk()
    bld = Builder(root)
    mainloop()


###  Here we go  ####
if __name__ == "__main__":
    main()