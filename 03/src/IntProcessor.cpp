#include <iostream>
#include "IntProcessor.h"
#include <functional>

int decrement(int val) { return val - 1; }

int IntProcessor::operator()(){
    for(int j=0; j< functions.size(); j++){
        for(int i=0; i< ints.size(); i++){
            int k=functions[j](ints[i]);
            ints[i]=k;
        }
    }
    return 0;
}

void IntProcessor::enableAlgorithm(std::string str){
    functions.clear();
    if(str=="decrement"){
        std::cout<<"Enabling built-in algorithm: decrement"<<std::endl;
        addAlgorithm(decrement);

    }
}

void IntProcessor::addAlgorithm(std::function<int(int)> s){
    functions.push_back(s);
}

int IntProcessor::operator+=(int value){
    ints.push_back(value);
    return 0;
}

int IntProcessor::computeTotal(){
    int sum=0;
    for(int i: ints){
        sum+=i;
    }
    return sum;
}