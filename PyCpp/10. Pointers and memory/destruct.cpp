#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
    //create an array on the stack
    const size_t DIM=5000;
    double bigArray [DIM];    //huge static array

    //create a dynamic array on the heap
    double* pbig {new double [DIM]{}};
    double d =0;
    for (size_t i=0; i< DIM; i++) {
        pbig[i] = d++; //convert to a double
    }
    for (size_t j=0; j<5; j++) {
        cout << pbig[j] <<endl;
    }
    //create a dynamic array in a vector
    vector <double *> dubbles;
    for (size_t i=0; i< DIM; i++) {
        double* px =  new double;
        *px = i*10.0;
        dubbles.push_back(px);      //add number into vector
    }
    for (size_t k=0; k<5; k++) {
        cout << k<<" "<< *dubbles[k]<<endl;
    }
    //release double array
    delete [] pbig;
    //release memory from dynamic array
    for (double* db:dubbles){
        delete db;
    }
    return 0;
}
