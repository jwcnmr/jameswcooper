
// fmtrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <format>
using namespace std;

int main() {
    double x = 4.5 / 3.22;
    cout << x << endl;
    double z = 0.1 + 0.2;
    cout << z << endl;
    int a = 12;
    cout << format("a= {:>8}", a);

    int y = 9127;
    cout << format("y= {:8x} {:8X} {:#8x} {:b} \n", y, y, y, y);

    //this one contains an error and will crash:
    try {
        cout << "trying to fail \n";
        cout << format("y= {:8.2f}", y);
    }
    catch (format_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}

=======
// fmtrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <format>
using namespace std;

int main() {
    double x = 4.5 / 3.22;
    cout << x << endl;
    double z = 0.1 + 0.2;
    cout << z << endl;
    int a = 12;
    cout << format("a= {:>8}", a);

    int y = 9127;
    cout << format("y= {:8x} {:8X} {:#8x} {:b} \n", y, y, y, y);

    //this one contains an error and will crash:
    try {
        cout << "trying to fail \n";
        cout << format("y= {:8.2f}", y);
    }
    catch (format_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}

