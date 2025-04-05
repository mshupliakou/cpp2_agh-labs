#include <iostream>
#include <functional>
#include <vector>
#ifndef INTPROCESS_H
#define INTPROCESS_H

///@brief class describes a  processor of integers
class IntProcessor{
    std::vector<int> ints;
    std::vector<std::function<int(int)>> functions;

    public:
    
    ///@brief adds a function to a collection of functions
    ///@param function the object of std::function<>
    void addAlgorithm(std::function<int(int)> s);

    // operator += to add a number to collection
    int operator+=(int value);

    ///@brief function which enablea a built in function
    ///@param str name of function
    void enableAlgorithm(std::string str);

    // overloading operator ()
    int operator()();

    //overloading of operator <<
    friend std::ostream& operator<<(std::ostream& os, IntProcessor& processor ){
        os<<"Collection : ";
        for(int i: processor.ints){
            os<<i<<" ";
        }
        os<<std::endl;
        return os;
    }

    ///@brief function which counts the sum of al numbbers in collection
    ///@return sum of all numbers
    int computeTotal();

};





#endif