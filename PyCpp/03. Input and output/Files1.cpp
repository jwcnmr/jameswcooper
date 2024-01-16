// Files1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const string FILENAME = "states.txt";

    ifstream txtFile(FILENAME);         //open the file
    if (txtFile.is_open()) {            //if it is open
        string line;
        while (getline(txtFile, line)) { //read it a line at a time
            cout << line << endl;       //print out each line
        }
        txtFile.close();                //close the file
    }
}
