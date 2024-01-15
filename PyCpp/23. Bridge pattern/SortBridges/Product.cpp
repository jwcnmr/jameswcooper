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
