#include <iostream>
#include "NegList.h"
#include "ListInspector.h"
#include <string>
std::string ListInspector::inspect(NegList list){
    std::string answ="NegList size: ";
    answ+=std::to_string(list.getSize());
    return answ;
}