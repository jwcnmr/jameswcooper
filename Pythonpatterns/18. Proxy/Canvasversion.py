"""Simple display of image, using the PIL library
to read and scale the image"""
import tkinter as tk
from tkinter import Canvas, NW
from PIL import ImageTk, Image

class ImageCanvas():

    def build(self):
        root = tk.Tk()
        root.title("Edward")
        w = 516
        h = 400
        root.configure(background='grey')
        path = "Edward.jpg"

        # Creates a Tkinter-compatible photo image,
        # using PIL to read the JPG file
        img = Image.open(path)
        img = img.resize((w, h), Image.ANTIALIAS)
        self.photoImg = ImageTk.PhotoImage(img)

        #draw on the canvas
        self.canv = Canvas(root, width = w+40, height = h+40)
        self.canv.pack(side="bottom", fill="both", expand="yes")
        self.canv.create_rectangle(20,20,w+20,h+20, width=3)
        self.canv.create_image(20,20, anchor=NW, image=self.photoImg)

        tk.mainloop()

def main():
    ImageCanvas().build()


###  Here we go  ####
if __name__== "__main__":
    main()