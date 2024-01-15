#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void errmsg(string text ="error in program") {
    cout <<text<<endl;
}

double area(double x, double y =0){
    double retval = 0;

    if (y !=0) retval= x*y;
        else  retval= x*x;

    errmsg();
    if (x==0 && y==0)
        errmsg("both arguments are zero");
    return retval;
}


int main() {
    cout << area(12,14) << endl; //product
    cout << area(12) << endl;       //square
    cout << area(0,0) <<endl;
    return 0;
}
