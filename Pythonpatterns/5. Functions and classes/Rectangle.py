from tkinter import Tk, Canvas, Frame, BOTH

#Rectangle draws on canvas
class Rectangle():
    def __init__(self, canvas):
        self.canvas = canvas

    def draw(self, x, y, w, h):
        # canvas rectangle uses x1,y1, x2,y2
        self.canvas.create_rectangle(x, y, x+ w, y+h)

#Square derived from Rectangle
class Square(Rectangle):
    def __init__(self, canvas):
        super().__init__(canvas)

    def draw(self, x, y, w):
        super().draw( x, y, w, w) #draw a square

def main():
    root = Tk()             #the graphics lbray
    canvas = Canvas(root)   #create a Canvas instance
    rect1 = Rectangle(canvas)   #and a Rectangls
    rect1.draw(30, 10, 120, 80)  #draw a rectangle

    square = Square(canvas)     #create a Square
    square.draw(200, 50, 60)    #and draw a square

    canvas.pack(expand=1)
    root.mainloop()


###  Here we go  ####
if __name__ == "__main__":
    main()

