#include <iostream>
using namespace std;
#include <string>

int main() {
    char c = 'a';
    //get the first character of whatever is entered
    while (c != 'q')  {
        cout << "Enter age group: (c, y, a, s, o) : ";
        string ageGroup= "a";
        int price = 0;

        cin >> ageGroup;
        if (ageGroup.length()>=0) {     //conver to lowercase
            c = tolower(ageGroup [0]);
        }
        switch (c) {
            case 'c':       //child is free
                price=0;
                break;
            case 'a':       //adult
                price = 35;
                break;
            case 'y':       //youth
                price=15;
                break;
            case 's':       //senior
                price = 30;
                break;
            case 'o':       //octogenarian
            case '8':
                price = 20;
                break;
            default:        //everyone else
                price = 35;
        }
        cout << "Price=" << price << endl;
    }

    //prototype switch statement
    int ap = 7;
    switch (ap) {
        case 5:
            cout <<"not a half dozen" <<endl;
            break;
        case 6:
            cout << "half dozen"<<endl;
            break;
        default:
            cout << "all those apples!"<<endl;
    }
    return 0;
}
