#include <iostream>
#include "File.h"
#pragma once
using namespace std;

/// class ScriptFile represents a script. File which can be executed. Extands class File and implements Executable
/// solving an example of a dimond problem c++
class ScriptFile : public File, public Executable{
    public:

    // constructor
    ScriptFile(string name):File(name){}

    // overriding finction execute
    void execute() override{
        std::cout<<"Uruchamianie skryptu: "<<name<<std::endl;
    }

};