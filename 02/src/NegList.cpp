#include <iostream>
#include "NegList.h"
int NegList::getSize()const{
    return size;
}
void NegList::setInspector(ListInspector * l){
    list_inspector=l;
}

NegList::~NegList(){}