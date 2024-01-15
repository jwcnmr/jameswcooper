#include <iostream>
using std::cout; using std::endl;

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
    if (pwr ==2)
        return sq(x);
    else if (pwr ==3)
        return cube(x);
    else{
        double y=1;
        for (int i=1; i<= pwr; i++){
            y =y * x;
        }
        return y;
    }


}
int main() {
    double asqd = sq(12.0);
    double cubed = cube(12.0);
    cout << asqd <<" "<< cubed<< endl;
    cout << sq(34)<<endl;
    cout << power(5,4)<<endl;
    return 0;
}


