<<<<<<< HEAD
#include "Product.h"
#include <string>
Product::Product(const string nstring) {
	size_t index = nstring.find("--");
	name = nstring.substr(0, index - 1);
	count = nstring.substr(index + 2, nstring.length());
}
string Product::getName() {
	return name;
}
string Product::getCount() {
	return count;
}
=======
#include "Product.h"
#include <string>
Product::Product(const string nstring) {
	size_t index = nstring.find("--");
	name = nstring.substr(0, index - 1);
	count = nstring.substr(index + 2, nstring.length());
}
string Product::getName() {
	return name;
}
string Product::getCount() {
	return count;
}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
