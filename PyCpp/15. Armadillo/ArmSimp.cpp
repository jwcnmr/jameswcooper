// ArmSimp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <armadillo>
#include <iostream>

using std::cout;
using std::endl;
using namespace arma;

int main()
{
    cout << "Armadillo version: " << arma_version::as_string() << endl;

    //conxtructing a matrix
    Mat<double> A (3,4);
    //or better, use the type defs:
    mat B(3, 4);

    // you can also fill the matrix
    mat C(2, 3, fill::zeros);
    mat D(5, 5, fill::randu); //uniform random distribution
    D.print();
    cout << endl;

     //extract a column and print it
     colvec q = D.col(0);
     q.print();
    
    cout << "D + D=" << endl;
    mat E = D + D ;
    E.print();

    // .n_rows and .n_cols are read only
    cout << "A.n_rows: " << A.n_rows << endl;
    cout << "A.n_cols: " << A.n_cols << endl;

   
  /*  mat = Mat<double>
    dmat = Mat<double>
    fmat = Mat<float>
    cx_mat = Mat<cx_double>
    cx_dmat = Mat<cx_double>
    cx_fmat = Mat<cx_float>
    umat = Mat<uword>
    imat = Mat<sword>*/
}




