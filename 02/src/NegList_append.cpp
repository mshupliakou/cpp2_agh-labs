#include <iostream>
#include "NegList.h"
void NegList::append(int number){
    int * new_list =  new int[size+1];
    for(int i=0; i<size; i++){
        new_list[i]=list[i];
    }
    new_list[size]=number;
    delete [] list;
    list = new_list;
    size++;
    }