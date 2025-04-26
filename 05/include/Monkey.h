#include <iostream>
#ifndef MONKEY_H
#define MONKEY_H
#include "Animal.h"
#include <memory>

///@brief class Monkey describes a monkey(type of an Animal)
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
    std::string getType() const{
        return "Monkey";
    }
    std::string getName() const{
        return name;
    }

};

#endif