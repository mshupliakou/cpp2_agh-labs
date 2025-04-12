#include <iostream>
#ifndef MONKEY_H
#define MONKEY_H
#include "Animal.h"
#include <memory>
class Monkey: public Animal{
    public:
    Monkey(std::string name):Animal(name){
        sound = "Ooh-ooh-aah-aah!";
    }
    std::string getSound() const override{
        return "Monkey "+name+" says:"+sound;
    }

    std::unique_ptr<Animal> clone() const override{
        return std::make_unique<Monkey>(*this);
    }


};

#endif