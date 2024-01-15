#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a = "apple";         //create a string
    string b("blueberry");  //create another string
    cout << a <<" "<< b << endl;
    //print out the 3rd character of a and the 4th of b
    cout<< a[2] << b[3] <<endl;

    string fruits = a + " " + b;
    cout << fruits <<endl;

    //change blueberry to blackberry
    fruits[8] = 'a'; fruits[9]='k';
    fruits.insert(9,"c");
    cout << fruits << endl;

    // to upper case
    for(int i=0; i< fruits.length(); i++) {
        fruits[i] = toupper(fruits[i]);
    }
    cout<<fruits<<endl;

    //reverse string
    fruits = a + " " + b;
    reverse(fruits.begin(), fruits.end());
    cout << fruits <<endl;

    //or do it yourself
    fruits = a + " " + b;
    string revString = fruits;  //create the output variable

    //and copy one from the front to the other from the back
    for(int i=0, j=fruits.length()-1; i< fruits.length(); i++, j--) {
        revString[j] = fruits[i];
    }
    cout << revString<<endl;


    return 0;
}
