"""Draws two co-added cosine waves on a canvas,
with a slight exponential decay"""

import tkinter as tk
import math

top = tk.Tk()
top.title("Cosine waves")
waves=[]            #array stored here
ASIZE=16384         #array size
WIDTH=1500          #window width
HEIGHT=1000         #and height

i=0
for x in range(0, ASIZE):
    yval = (math.cos(x/100.0) + math.cos(x/5.0)) #add cosine waves
    yval = math.exp((ASIZE-x)/ASIZE) * yval      #exponential decay
    
    y = int(yval * 40) + 400                     #wave height
    xcoord=int(i*(WIDTH/ASIZE)) +10  #x coord
    
    waves.append(xcoord)            #append x
    waves.append(y)                 #and y to waves array
    i+=1                            #keep count

#create Canvas
canv = tk.Canvas(top, height=HEIGHT, width=WIDTH)
canv.config(bg="white")

#and draw the line from the x,y pairs
line = canv.create_line(waves)
canv.pack()

top.mainloop()