#include <iostream>
using namespace std;

int main() {
    // if else demo using ticket prices
    int age = 22;       //start with a non zero age.
    while (age > 0) {
        cout << "Enter age :";
        cin >>age;
        int price = 35;
        if (age <= 6)
            price = 0;  //toddlers are free
            else if ((age > 6) && (age <18))
                price=15;   //student price
            else if ((age >=18) && (age < 60))
                price = 35; //adult
            else if ((age >=60) && (age <80))
                price = 30; //senio
            else
                price = 20;  //super senior

            cout << "Price is :"<<price <<endl;
    }
    return 0;
}
