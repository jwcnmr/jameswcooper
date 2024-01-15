#include <iostream>
using std::cout; using std::endl;

double sq(double x);
double cube(double x);
int sq(int x );
double power (double x, int pwr);

double sq1(double x) {
    x = x*x;
    return x;
}

int main() {
    double asqd = sq(12.0);
    double cubed = cube(12.0);
    cout << asqd <<" "<< cubed<< endl;
    cout << sq(34)<<endl;
    cout << power(5,4)<<endl;

    double x =12;
    double y = sq1(x);
    cout << "y="<<y<<" x="<<x<<endl;
    return 0;
}

//square the argument and return it
double sq(double x) {
    double y = x * x;   //create the square
    return y;           //and return it
}

//cube the argument and return it
double cube(double x) {
    double y = sq(x);
    y =  y * x;     //create the sube
    return y;       //and return it
}
int sq(int x ){
    return x*x;
}
double power (double x, int pwr) {
    double y=1;
    for (int i=1; i<= pwr; i++){
        y =y * x;
    }
    return y;
}


