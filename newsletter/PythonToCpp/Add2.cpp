#include <iostream>
#include <string>
using namespace std;
// Simple program to add two numbers

//function to read in a number and convert to float.
float getnum(string message) {
	cout << message;
	string ans;
	cin >> ans;
	float val1 = stof(ans);
	return val1;
}
int main() {
	// get the first number
	float val1 = getnum( "Enter first number: ");
	
	// get the second number
	float val2 = getnum( "Enter second number: ");
	
	// add them and print out the result
	cout << "The sum is " << val1 + val2 << endl;
}