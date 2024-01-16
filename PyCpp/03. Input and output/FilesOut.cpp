// FilesOut.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string FILENAME = "states.txt";
    const string OUTFILE = "mystates.txt";

    ifstream txtFile(FILENAME);  //open input file
    ofstream outFile(OUTFILE);   //open output file


    if (txtFile.is_open() && outFile.is_open()) {   //if it is open
        string line;
        while (getline(txtFile, line)) { //read it a line at a time
            cout << line << endl;       //print out each line
            outFile << line << endl;    //write to output file
        }
        txtFile.close();                //close both files
        outFile.close();
    }
}
