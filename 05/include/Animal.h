#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H
/// @brief describes a certain animal ABSTRACT CLASS
class Animal{
    protected :std::string name; std::string sound;

    public:
    /// @brief constructor
    /// @param name 
    Animal(std::string name):name(name){}

    /// @brief virtual getter of an animal's sound
    /// @return animal's sound
    virtual std::string getSound() const = 0;

    /// @brief virtual function which creates a clone for an animal
    /// @return animal's clone
    virtual std::unique_ptr<Animal> clone() const = 0;

    //simple getter of a type of an animal
    virtual std::string getType() const =0;

    //simple getter of a name of an animal
    virtual std::string getName() const =0;
    
    /// @brief destructor
    virtual ~Animal() = default;

};

#endif