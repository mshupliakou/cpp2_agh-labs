#include <iostream>
#include "NegList.h"
void NegList::pop(){
    int * new_list =  new int[size-1];
    for(int i=0; i<size-1; i++){
        new_list[i]=list[i];
    }
    delete [] list;
    list = new_list;
    size--;
    }