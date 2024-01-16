#include <iostream>
#include <numbers>

using std::cout;
using std::endl;
using namespace std::numbers;

//Rectangle class
class Rectangle {
private:
    double width;
    double height;
public:
    //constructor
    Rectangle(double w, double h):width{w},height{h}{
    }
    //default constructor
    Rectangle(){}
    double area() {
        return width * height;
    }
};

class Semicircle {
private:
    double radius=0;
public:
    //constructor
    Semicircle(double rad):radius{rad}   {
}
    //default constructor
    Semicircle(){}
    double area() {
        return radius * radius * pi/2;
    }
};

//gets the area of any class
//with a getArea method
template <class T>
class DoArea {
private:
    T shape ;
public:
    DoArea (T tshape ):shape{tshape} {
    }
    double getArea() {
        return shape.area();
    }
};

int main() {
    //create 2 shapes
    Rectangle rect = Rectangle(5,6);
    Semicircle semi = Semicircle(7);

    //get area of semicircle
    DoArea doarea = DoArea(semi);
    cout << "Semicircle "<< doarea.getArea() << endl;

    //get area of rectangle
    cout << "Rectangle "<< DoArea(rect).getArea() << endl;

    return 0;
}
