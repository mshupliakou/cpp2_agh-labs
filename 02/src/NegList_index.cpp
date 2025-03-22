#include <iostream>
#include "NegList.h"

int& NegList::operator[](int i){
    return list[-i-1];
}