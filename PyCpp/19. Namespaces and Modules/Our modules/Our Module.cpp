// Our Module.cpp :
// Calling program to use the Minimath module (Note capitalization)
//

#include <iostream>
using std::cout;
using std::endl;

import Minimath;    //import the Minimath module

int main() {
    double x = 12;
    cout << "x^2 =" << square(x) << endl;
    cout << "x cubed is" << cube(x) << endl;
}

