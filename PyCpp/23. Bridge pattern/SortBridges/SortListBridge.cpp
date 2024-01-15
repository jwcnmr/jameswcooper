#include "ListBridge.h"
#include "Products.h"
#include "VisList.h"

ListBridge::ListBridge(VisList* vl) {
	visList = vl;

}
void ListBridge::addData(Products* prod) {
	visList->addLines(prod);

}
