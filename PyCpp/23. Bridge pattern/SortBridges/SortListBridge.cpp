<<<<<<< HEAD
#include "ListBridge.h"
#include "Products.h"
#include "VisList.h"

ListBridge::ListBridge(VisList* vl) {
	visList = vl;

}
void ListBridge::addData(Products* prod) {
	visList->addLines(prod);

}
=======
#include "ListBridge.h"
#include "Products.h"
#include "VisList.h"

ListBridge::ListBridge(VisList* vl) {
	visList = vl;

}
void ListBridge::addData(Products* prod) {
	visList->addLines(prod);

}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
