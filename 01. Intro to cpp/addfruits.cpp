#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

//Add up the amount of fruit you have
int main() {
    int apples, oranges;

    //get numbers of apples and oranges from keyboard
    cout << "Enter number of apples :";
    cin >> apples;
    cout << "Enter number of oranges :";
    cin >> oranges;

    //add them together
    int fruits = apples + oranges;

    // print out the sum
    cout << "Total fruit " << fruits << endl;
    return 0;
}