#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Adder {
public:
    //static methods do not need a class instance
    static double addNums(double x, double y) {
        return x + y;
    }
    static double addNums(string x, double y) {
        return stod(x) + y;
    }
    static double addNums(string x, string y) {
        return stod(x) + stod(y);
    }
    static double addNums(double x, string y) {
        return x + stod(y);
    }
    static double addNums(double x, double y, double z){
        return x + y + + z;
    }
};

int main() {
    cout << Adder::addNums(12.1, 14) << endl;
    cout << Adder::addNums("22.4", "1.008") << endl;
    cout << Adder::addNums(123.4, "6.02") << endl;
    cout << Adder::addNums(122.3,303.4,45.6) << endl;
    return 0;
}
