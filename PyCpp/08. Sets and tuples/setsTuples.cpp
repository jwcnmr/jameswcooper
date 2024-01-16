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
using std::iterator;

int main() {
    set<int> cset={2,5,12};  //create a set
    cset.insert(5);     //add a duplicate
    cset.insert(6);     //add a new number

    //print out set contents
    for(int s: cset){
        cout << s <<" ";
    }
    cout << endl;
    //check to see if set contains a 6
    int num = 6;
    auto it = cset.find(num);
    if (it != cset.end()){
        cout << num <<" is in the set"<<endl;
    }
    else
        cout << num << "is NOT in the set" <<endl;

    //strings in sets
    set<string> stSet{"Fred", "Nora", "Zoltan"};
    for (string st: stSet){
        cout <<st<<" ";
    }
    cout <<endl;
    set <double> dSet {22.4, 6.02e23,1.008};
    dSet.insert(22.4);
    for (double d: dSet){
        cout <<d <<" ";
    }
    cout <<endl;

    //set merge into new set
    set <string> fruits{"apples", "pears", "cherries"};
    set <string> piestuff{"nuts", "berries", "apples"};
    set <string> pie = fruits ;
    pie.insert(piestuff.begin(), piestuff.end());
    for (string s:pie){
        cout <<s <<" ";
    }
    cout <<endl;

    //demonstrate tuples
    auto newTuple = std::make_tuple ("Sarah", "Snoody", 14, 'y');

    // You must access the tuples with a constant index, not a variable
    cout<< get<0>(newTuple) <<" ";
    cout<< get<1>(newTuple) <<" ";
    cout<< get<2>(newTuple) <<" ";
    cout<< get<3>(newTuple) <<" ";

    cout << endl;
    // or you can copy them into these variables with the tie function
    string frname, lname;
    int age;
    char honors;
    //copy the tuple members into the above variables
    // to make them easier to print out or use.
    std::tie(frname, lname, age, honors) = newTuple;

    //or you can copy them directly starting in C++ 17:
    auto [frname1, lname1, age1, honors1] =  newTuple;

    cout << frname <<" ";
    cout <<lname <<" ";
    cout <<age <<" ";
    cout << honors <<endl;

    return 0;
}
