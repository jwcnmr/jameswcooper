
#include "Products.h"
#include "VisList.h"
#include "GridBridge.h"

//bridge betwen grid and products
GridBridge::GridBridge(VisList* vl) {
	visList = vl;

}
void GridBridge::addData(Products* prod) {
	visList->addLines(prod);

}
