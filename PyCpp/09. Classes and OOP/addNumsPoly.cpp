#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Adder {
public:
    double addNums(double x, double y) {
        return x + y;
    }
    double addNums(string x, double y) {
        return stod(x) + y;
    }
    double addNums(string x, string y) {
        return stod(x) + stod(y);
    }
    double addNums(double x, string y) {
        return x + stod(y);
    }
    double addNums(double x, double y, double z){
        return x + y + + z;
    }
};

int main() {
    Adder adder;    //create instance of Adder
    cout << adder.addNums(12.1, 14) << endl;
    cout << adder.addNums("22.4", "1.008") << endl;
    cout << adder.addNums(123.4, "6.02") << endl;
    cout << adder.addNums(122.3,303.4,45.6) << endl;
    return 0;
}
