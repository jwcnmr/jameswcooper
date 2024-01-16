#include <iostream>
#include <string>
using std::cout; using std::endl;
using std::string;

void changeArray(double *xa, size_t size){
    xa[4] = 42.0;
    *(xa+4) =43.0;
}
void changeAnArray(double xarray[]){
    xarray[3]=666;
}
void changeAnArray(double xarray[]){
    xarray[3]=666;
}
//call by value.
// Changes only within the function
void getReal(double x) {
    x=15;       //changes only inside function
}
//call by reference
// The pointer to the argument mean
// that you can change the calling parameter
void getPreal(double* px) {
    *px = 22;       //changes the calling parameter
}

int main() {
    string mtb = "meatball";
    string* pmeat = &mtb;   //pointer to string
    cout << *pmeat <<endl;  //print out the string text

    double xarray[] = {12,14,15,16,20};
    double* px = xarray;
    for (int i=0; i<5; i++) {
        cout << *px++ <<" ";    //pointer into array incremented
    }
    cout <<endl;
    changeArray(xarray,5);
    changeAnArray(xarray);

    px = xarray;
    for (int i=0; i<5; i++) {
        cout << *px++ <<" ";    //pointer into array incremented
    }
    cout<<endl;
    //illustrate changing values within a function
    double y {172.6};
    getReal(y);         //pass by value
    cout << "after getreal y="<<y<<endl;
    getPreal(&y);       //pass by reference
    cout << "after getPreal y="<<y<<endl;
    return 0;
}
