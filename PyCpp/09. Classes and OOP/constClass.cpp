#include <iostream>
using std::cout;
using std::endl;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h):width{w}, height{h}{}
    //void setWidth(double w){width = w;}
    //void setHeight(double h) {height=h;    }
    double getwidth() const {return width;}
    double getHeight() const {return height;}
    double getArea() const {return width * height;}
};

int main() {
    const Rectangle rect{22,34};
  //  rect.setWidth(33);
    cout << rect.getArea()<<" "<< rect.getwidth()<<" "<<rect.getHeight()<<endl;
    return 0;
}
