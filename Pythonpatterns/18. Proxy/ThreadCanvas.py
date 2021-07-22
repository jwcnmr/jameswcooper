"""Demonstration of Proxy pattern using display of an image
The rectangle is drawn in the main thread,
and the time-consuming image is drawn in the thread
with a delay of 2 seconds.
"""

import tkinter as tk
from tkinter import Canvas, NW
from PIL import ImageTk, Image
import logging
import threading
import time

class ThreadCanvas():

    def thread_image(self,*args):
        name = args[0]      #thread identifier
        time.sleep(2)       # here is the delay
        # open the image, and scale it
        img = Image.open(args[1])   #image location
        img = img.resize((self.w, self.h), Image.ANTIALIAS)
        self.photoImg = ImageTk.PhotoImage(img)
        self.canv.create_image(20, 20, anchor=NW,
                               image=self.photoImg)

# creates the canvas and draws the rectangle on it
    def build(self):
        root = tk.Tk()
        root.title("Edward")
        self.w = 516
        self.h = 400
        root.configure(background='grey')

        path = "Edward.jpg"

        # Creates a Tkinter-compatible photo image,
        # which can be used everywhere Tkinter expects an image object.
        self.canv = Canvas(root, width = self.w+40, height = self.h+40)
        self.canv.pack(side="bottom", fill="both", expand="yes")
        self.canv.create_rectangle(20,20,self.w+20,self.h+20, width=3)

        # set up the imaging thread
        x = threading.Thread(target=self.thread_image, args=(1,path))
        x.start()       #start the thread here

        tk.mainloop()


def main():
    ThreadCanvas().build()
    ###  Here we go  ####
if __name__ == "__main__":
    main()
