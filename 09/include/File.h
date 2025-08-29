#include <iostream>
#include "FSItem.h"
#pragma once
using namespace std;

/// class File represents a file and extands FSItem
class File : virtual public FSItem{
    protected : string name;

    public:

    // constructor 
    File(string name):name(name){}

    // name getter overriding
    string getName() override{
        return name;
    }

    void printInfo() override{
        std::cout<<"This is file "<<name<<std::endl;
    }
};

/// interface Executable for items which can be executed
class Executable : virtual public FSItem{
    public:

    ///@brief function to execute an item(script for example)
    virtual void execute()=0;

};