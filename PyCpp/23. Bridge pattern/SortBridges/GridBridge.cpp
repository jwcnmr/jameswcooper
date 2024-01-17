<<<<<<< HEAD

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
=======

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
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
