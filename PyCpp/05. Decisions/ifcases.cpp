#include <iostream>
using namespace std;

int main() {
    int apples = 5, berries=7;
    int fruit = apples + berries;
    if (berries < apples) {
        cout << "add more berries"<<endl;
    }
    else if (apples == berries) {
        cout << "still need more berries" << endl;
    }
    else {
        cout << "how about them apples?"<< endl;
    }
    if (berries < apples)
        cout << "add more berries"<<endl;
    else if (apples == berries)
        cout << "still need more berries" << endl;
    else
        cout << "how about them apples?"<< endl;

    int pears = 2;

    if ((apples > berries) || (pears < berries))
        cout <<"enough fruit" <<endl;

    if (pears <= 2)
        cout << "have you a pair of pears?"<<endl;

    //incorrect use of = sign
    if (apples = berries)
        cout << "false positive" <<endl;

    // Comparing strings
    string apple = "apple";
    string moreapples = "apples";
    if (moreapples > apple)
        cout << "bigger"<<endl;


    return 0;
}
