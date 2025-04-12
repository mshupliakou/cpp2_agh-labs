#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H
/// @brief describes a certain animal
class Animal{
    protected :std::string name; std::string sound;

    public:
    /// @brief constructor
    /// @param name 
    Animal(std::string name):name(name){}

    /// @brief virtual getter of an animal's sound
    /// @return animal's sound
    virtual std::string getSound() const = 0;

    virtual std::unique_ptr<Animal> clone() const = 0;

    /// @brief destructor
    virtual ~Animal() = default;

};

#endif