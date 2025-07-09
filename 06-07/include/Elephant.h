#include <iostream>
#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "Animal.h"
#include <memory>

/// @brief describes an elephant(a type of animals)
class Elephant final: public Animal{
    public:
    Elephant(std::string name):Animal(name){
        sound = "PAAAAWOOO!";
    }
    std::string getSound() const override{
        return "Elephant "+name+" trumpets:"+sound;
    }

    std::unique_ptr<Animal> clone() const override{
        return std::make_unique<Elephant>(*this);
    }
    std::string getType() const{
        return "Elephant";
    }
    std::string getName() const{
        return name;
    }
};



#endif