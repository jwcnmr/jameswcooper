import math
"""Simple inheritance demonstration using 
   Rectangle, Square and Semicircle"""

# The Rectangle base class
class Rectangle:
    def __init__(self, width, height):
        self.width = width      # save the dimensions
        self.height = height
    def area(self):             # compute the area
        return self.height * self.width

#  a Square is derived from Rectangle and has only one dimension
class Square(Rectangle):
     def __init__(self, side):
         super().__init__( side, side)  #pass both dimensions to parent class

# Semicircle is derived from Square and needs only the radius
class SemiCircle(Square):
     def __init__(self, radius):
         super().__init__( radius)

    # area computation is different in this derived class
     def area(self):
         return (math.pi * self.width * self.width)/2

def main():
     rect= Rectangle(5, 4)
     print("Rectangle,", rect.area())

     sq = Square(6)
     print("Square,", sq.area())

     semi = SemiCircle(3)
     print(f'Semicircle, {semi.area():5.2f} ')

     ###  Here we go  ####


if __name__ == "__main__":
    main()