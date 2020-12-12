""" Creates a 3-button window
Left  button creates waves
Middle button is disabled until waves are created, and then performs an FFT on that data and displays result
right button exits the program

"""

import tkinter as tk
from tkinter import *
from tkinter import ttk

import matplotlib.pyplot as plt
import math
import numpy

ASIZE = 16384


# --------------------------
#Creates the array of two coadded cosine wave with exponential decay
class WaveMaker():

    def __init__(self, wsize: int) -> object:
        self.size = wsize
        self.swaves = []

    #creates the array of two cosine waves
    def maker(self):
        for x in range(0, self.size):
            self.swaves.append(math.exp((self.size - x) / self.size) * (math.cos(x / 100.0) + math.cos(x / 5.0)))


   #plot the cosine waves
    def plot(self):
        fig, ax = plt.subplots()
        ax.plot(self.swaves)
        plt.show()

    def getWaves(self):
        return self.swaves
# -----------------
class BuildUI():
    def __init__(self, asize: int):
        self.tk = tk
        self.size = asize
        self.real = []
        self.freqdata = []

    def build(self):
        self.wmaker = WaveMaker(self.size)
        root = tk.Tk()
        root.title("Waves and Fourier transform")
        root.geometry("300x100")
        # create 3 buttons for Waves, FFT and Quit
        r=0
        self.lbutton = ttk.Button(text="Waves", command=self.makeWaves, width=15)
        self.lbutton.grid(row=r, column=0, padx=5)
        self.rbutton = ttk.Button(text="FFT", state="disabled", command=self.doFFT, width=10)
        self.rbutton.grid(row=r, column=1, padx=5)
        self.qbutton = ttk.Button(text="Quit", command=quit, width=15)
        self.qbutton.grid(row=r, column=2, padx=5)

        root.mainloop()

    def doFFT(self):
        # calc FFT on the waves array
        self.freqdata = numpy.fft.fft(self.wmaker.getWaves(), self.size)

        # copy the real part of transform into new array
        for x in range(0, int(self.size / 2)):
            self.real.append(self.freqdata[x].real)

        # create figure and axis
        fig, ax = plt.subplots()
        ax.plot(self.real)  # plot the transformed data
        plt.show()

    def makeWaves(self):
        self.wmaker.maker()  # create the cosine waves
        self.rbutton.configure(state='normal')
        self.wmaker.plot()  # plot the cosine waves


# main begins here
def main():
    builder = BuildUI(ASIZE)
    builder.build()


###  Here we go  ####
if __name__ == "__main__":
    main()
