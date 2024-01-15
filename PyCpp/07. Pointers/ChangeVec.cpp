// SimpleVec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

//print out contents of vector
void printvec(vector<int> z) {
    for (auto k : z) {
        cout << k << " ";
    }
    cout << endl;
}
void changeVec(vector<int>& px) {
//void changeVec(vector<int>px) {
    if (2 < px.size()) {        
        px[2] = 123;       
    }
    printvec(px);
}

int main(){
    vector <int> v = { 3,6,7,8,12 };
    changeVec(v);
    printvec(v);  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
