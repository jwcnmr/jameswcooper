import keyboard
import os
import time
from termcolor import colored, cprint

class Command:
    def comd(self):
        pass

# A series of Command objects
class Ckey(Command):
    def __init__(self):
        self.start =time.time() # start timer
    def comd(self):
        self.end = time.time()
        elapsed = self.end - self.start #compute elapsed time
        print('elapsed: ',elapsed)
        self.start = self.end # new starting time

# prints green on red message
class Rkey(Command)   :
    def comd(self):
        cprint('Hello, World!', 'green', 'on_red')

# print blue on yellow message
class Bkey(Command):
    def comd(self):
        cprint('Feeling blue', 'blue','on_yellow')

# exits from the program
class Qkey(Command):
    def comd(self):
        print('exiting')
        os._exit(0)

# manages the key stroke commands
class KeyModerator():
    def __init__(self):
        # create instances of each command class
        self.rkey = Rkey()
        self.bkey = Bkey()
        self.qkey = Qkey()
        self.ckey = Ckey()
        self.funcs = {'r': self.rkey,
                   'b': self.bkey,
                   'q': self.qkey,
                   'c': self.ckey }

    def getKey(self, keyval):
        # call any command object using the dictionary
        # to fetch the right function
        func = self.funcs.get(keyval.name)
        func.comd()

# program starts here
kmod = KeyModerator()   # set up command classes

# wait for key presses
keyboard.on_press(callback=kmod.getKey, suppress=True)

#Wait for keys but relinquish time when not used
print("Enter commands: r, b, c or q")
while True:
    time.sleep(1000)

