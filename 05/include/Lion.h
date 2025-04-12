#include <iostream>
#ifndef LION_H
#define LION_H
#include "Animal.h"
#include <memory>

/// @brief describes a lion(a type of animals)
class Lion: public Animal{
    public:
    Lion(std::string name):Animal(name){
        sound = "ROOAAAR!";
    }
    std::string getSound() const override{
        return "Lion "+name+" roars:"+sound;
    }

    std::unique_ptr<Animal> clone() const override{
        return std::make_unique<Lion>(*this);
    }

};

#endif