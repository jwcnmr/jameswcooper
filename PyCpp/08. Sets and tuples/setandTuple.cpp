#include <iostream>
#include <set>
#include <tuple>
#include <string>

using std::cout;
using std::endl;
using std::set;
using std::tuple;
using std::get;
using std::string;

int main() {
    set<int> cset = { 2,5,12 };  //create a set set
    cset.insert(5);     //add a duplicate
    cset.insert(6);     //add a new number

    //print out set contents
    for (int s : cset) {
        cout << s << " ";
        cout << endl;
    }
    //check to see if set contains a 6
    int num = 6;
    auto it = cset.find(num);
    if (it != cset.end()) {
        cout << num << " is in the set" << endl;
    }
    else
        cout << num << "is NOT in the set" << endl;

    //demonstrate tuples
    tuple <int, string> breadTuple(12, "loaves");
    cout << get<0>(breadTuple) << " " << get<1>(breadTuple) << endl;
    auto newTuple = std::make_tuple("Sarah", "Snoody", 14, 'y');
    // You must access the tuples with a constant index, not a variable
    cout << get<0>(newTuple) << " ";
    cout << get<1>(newTuple) << " ";
    cout << get<2>(newTuple) << " ";
    cout << get<3>(newTuple) << " ";

    cout << endl;
    // or you can copy them into these variables with the tie function
    string frname, lname;
    int age;
    char honors;
    //copy the tuple members into the above variables
    // to make them easier to print out or use.
    std::tie(frname, lname, age, honors) = newTuple;
    cout << frname << " ";
    cout << lname << " ";
    cout << age << " ";
    cout << honors << endl;

    //only works in C++17 or later
    //note that auto determines the types of all 4 variables for you.

    auto [frname1, lname1, age1, honors1] = newTuple;
    cout << "auto" << endl;
    cout << frname1 << " ";
    cout << lname1 << " ";
    cout << age1 << " ";
    cout << honors1 << endl;


    return 0;
}
