#include <iostream>
#include <memory>
#pragma once
using namespace std;

/// class FSItem represents an item and stans for File System Item 
class FSItem{
    public:

    ///@brief virtual getter of a name of an item
    ///@return name
    virtual string getName()=0;

    ///@brief displays information about an item
    virtual void printInfo()=0;
};