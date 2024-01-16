#include <iostream>
using std::cout;
using std::endl;
using std::string ;

//draws a rectangle on the console screen
class Rectangle{
    const string star="*  ";
    const string spaces ="   ";
protected:
    int width, height;
public:
    Rectangle(int w, int h): width{w}, height{h} {
    }
    //draws top and bottom lines
    void drawTop() {
        for (int i=0; i<width; i++) {
            cout <<star;
        }
        cout <<endl;
    }
    //draws both sides
    void drawSides() {
        for (int i=0; i<height-1; i++) {
            cout << star;
            for (int j=0; j<width-2; j++){
                cout << spaces;
            }
            cout << star << endl;
        }
    }

    //draws whole box
    void draw() {
        drawTop();
        drawSides();
        drawTop();
    }
};

//square derived from Rectangle
class Square:public Rectangle{
public:
    Square(int size):Rectangle(size,size){}
};

int main() {
    //create and draw a rectangle
    Rectangle rect(8,5);
    rect.draw();
    //create and draw a square
    Square sq(5);
    sq.draw();
    return 0;
}
