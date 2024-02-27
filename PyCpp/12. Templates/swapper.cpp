#include <iostream>
#include <string>
//using std::swap;
using std::cout;
using std::endl;
using std::string;

//our own swap template function
template <typename myType>
void myswap(myType a, myType b) {
    myType temp = a;
    a = b;
    b = temp;
}

int main() {
    double a =123; double b = 456;
    myswap(a,b);
    cout << "a="<< a <<" b="<< b <<endl;

    string fruit1 = "banana"; string fruit2 = "orange";
    myswap(fruit1, fruit2);
    cout << "fruit1="<< fruit1 <<" fruit2="<<fruit2<<endl;
    double x=123.45;

    return 0;
}
