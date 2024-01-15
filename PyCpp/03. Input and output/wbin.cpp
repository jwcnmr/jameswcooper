#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double temps[] = {22.3,35.7,44.8,55.2,61.6,73.8,89.3};

    //write entire file at once
    ofstream outfile;
    outfile.open("temps.dat", ios::binary | ios::out);
    outfile.write((const char*)&temps, sizeof(temps));
    outfile.close();

    //write a byte at a time
    outfile.open("tempsb1.dat", ios::binary |ios::out);
    for (int i=0; i< size(temps); i++){
        outfile.write((const char*)&temps[i], sizeof(temps[i]));
    }
    outfile.close();

    double newtemps[7];     //create empty array
    ifstream infile;
    // read in data all at once
    infile.open("tempsb1.dat", ios::binary | ios::in);
    infile.read((char*)&newtemps, sizeof(newtemps)); // reads 56 bytes
    infile.close();

    //print out contents of new array
    for (double x:newtemps) {
        cout << x <<" ";
}
}

