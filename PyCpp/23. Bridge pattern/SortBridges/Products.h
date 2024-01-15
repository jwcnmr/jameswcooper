#pragma once
#include <vector>
#include <string>

#include "Product.h"
using std::string;
using std::vector;
//holds a collection of products in a vector

class Products {
private:
	vector<Product*> prods;	// list of products
public:
	Products(const string filename);	//read the file
	vector <Product*> getProducts();	//return the vector
};

