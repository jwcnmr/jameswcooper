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

