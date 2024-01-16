// Rectangle.cpp :
//


#include <iostream>
#include <format>
#include <numbers>
using std::numbers::pi;
using namespace std;

//Base Rectangle class
class Rectangle {
  
    // The dimensions can be accessed by child classes
    protected:
        float width, height;

    public:
        //copy arguments into width and height
        Rectangle(float w, float h) : width{ w }, height{ h } {
       
        }
       /* Rectangle(float w, float h) {
            width = w;
            height = h;
        }*/
        float area() {
            return height * width;
        }
};

// Derived Square class uses area method in parent class
class Square : public Rectangle {

    public:
        Square(float w) : Rectangle(w, w) {}
};


// Derived Semicircle overrides area method
class Semicircle : public Square {
    public:
        Semicircle(float radius):Square(radius) {}
    public:
        float area() {
            return (pi * width * width) / 2;
        }

};

int main() {
    Rectangle rect(5, 4);
    //Rectangle rect = Rectangle(5, 4);
    cout << "Rectangle: " << rect.area() << endl;

    Square sq(6);
    cout << "Square: " << sq.area() << endl;

    Semicircle semi(3);
    //std::cout << "Semicircle: " << semi.area() << std::endl;
    cout << format("Semicircle: {:3.2f}", semi.area());

}
