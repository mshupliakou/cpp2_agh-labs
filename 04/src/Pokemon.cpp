#include <iostream>
#include "Pokemon.h"

void Pokemon::printInfo() const{
    std::cout<<"Pokemon:"<<m_name<<" (Type: "<<m_type<<")"<<std::endl;
   
}