#include <iostream>
using namespace std;

int main() {
    double xarray[] ={5, 7, 4, 3, 9, 12 ,6};
    double sum = 0;
    for (double x: xarray) {
        sum += x;
        if (sum > 16) {
            break;
        }
    }
    cout << "Sum1 = " << sum <<endl;

    //alternate approaches
    bool quit = false;
    sum =0;
    int i = 0;
    while (! quit) {
        sum += xarray[i++];
        quit = sum > 16;
    }
    cout << "Sum2 = " << sum <<endl;

    sum =0; i=0;
    while (sum <=16) {
        sum += xarray[i++];
    }
    cout << "Sum3 = " << sum <<endl;

    //continue statement
    for (i=0; i< size(xarray); i++) {
        if (i ==4) continue;  //skips index 3
        cout << xarray[i]<<" ";
    }
    cout <<endl;

    //alternate without using continue
    for (double x: xarray) {
        if (x !=9) cout << x <<" ";
    }

    return 0;
}
