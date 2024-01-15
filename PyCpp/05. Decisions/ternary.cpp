#include <iostream>
using std::cout;
using std::endl;

int main() {
    int berries =100;
    int beans = 50;

    int produce =  (berries > beans) ? berries : beans;
    cout <<"produce is: "<< produce << endl;

    if (berries > beans)
        produce = berries;
    else
        produce =  beans;

    cout <<"produce is: "<< produce << endl;

    return 0;
}
