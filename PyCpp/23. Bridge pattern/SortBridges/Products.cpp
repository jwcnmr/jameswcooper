<<<<<<< HEAD
#include "Products.h"
#include <iostream>
#include <fstream>

using std::iostream;
using std::ifstream;

//constructor reads in the products file
//splitting the name from the count
//and storing each pair of values in a Product class
//and stores all the products in a vector.
Products::Products(const string filename) {
    //read in the data fiile
    ifstream txtFile(filename);         //open the file
    if (txtFile.is_open()) {            //if it is open
        string line;
        while (getline(txtFile, line)) { //line at a time
            prods.push_back(new Product(line));      //print out line
        }
        txtFile.close();                //close the file
    }
}
//return a vector of Product instances
vector<Product*> Products::getProducts() {
    return prods;
}
=======
#include "Products.h"
#include <iostream>
#include <fstream>

using std::iostream;
using std::ifstream;

//constructor reads in the products file
//splitting the name from the count
//and storing each pair of values in a Product class
//and stores all the products in a vector.
Products::Products(const string filename) {
    //read in the data fiile
    ifstream txtFile(filename);         //open the file
    if (txtFile.is_open()) {            //if it is open
        string line;
        while (getline(txtFile, line)) { //line at a time
            prods.push_back(new Product(line));      //print out line
        }
        txtFile.close();                //close the file
    }
}
//return a vector of Product instances
vector<Product*> Products::getProducts() {
    return prods;
}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
