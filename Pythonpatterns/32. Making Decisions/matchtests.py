"""Testing of match features
Requires Python 3.10"""
tval = 12
match tval:
     case 2:            # if 2
        print("two")
     case 3 | 12:       # 3 or 12
        print("3 or 12")
     case _:            # anything else
        print('all the rest')

name = 'fred'
match name:
    case 'sam':
        print('sam')
    case 'fred':
        print('fred')
    case 'sally':
        print('sally forth')

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y

def location(point):
    match point:
        case Point(x=0, y=0):
            print("Point is at the origin.")
        case Point(x=0, y=y):
            print(f"Y={y} and the point is on the y-axis.")
        case Point(x=x, y=0):
            print(f"X={x} and the point is on the x-axis.")
        case Point():
            print("The point is located somewhere else on the plane.")
        case _:
            print("Not a point")

p = Point(100, 0)
location(p)