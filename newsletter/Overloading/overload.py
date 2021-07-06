from dataclasses import dataclass

@dataclass
class Point:
    x:int   # both become part of init
    y:int

    # generate string output representation
    def __str__(self):
        return f'({self.x}, {self.y})'

    # overload + operator
    def __add__(self, other):
        x1 = self.x + other.x   # add the two coordinates
        y1 = self.y + other.y
        return Point(x1, y1)    # return a new Point

    # overload - operator
    def __sub__(self, other):
        x1 = self.x - other.x   # subtract coordinates
        y1 = self.y - other.y
        return Point(x1, y1)    # return a new Point




p1 = Point(20,40)   # create a point
print(p1)           # show string output
p2 = Point(50,70)   # create another point
p3 = p1 + p2        # overload + sign
p4 = p2 - p1        # overload - sign
print(p3, p4)