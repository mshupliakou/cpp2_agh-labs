#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h"

/// @brief describes a certain zoo with a vector of animals
class Zoo{
    std::vector<std::unique_ptr<Animal>> animals;

    public:
    //default constructor
    Zoo(){}

    /// @brief the function adds a new animal tp an array of animals
    /// @param a the animal we would like to add
    void addAnimal(std::unique_ptr<Animal> a);

    /// @brief displays a sound of an animal
    /// @param number the number of an animal in array
    void makeAnimalSound(int number)const;

    /// @brief copy constructor
    /// @param other 
    Zoo(const Zoo& other);

    /// @brief overloading copy operator=
    Zoo operator =(const Zoo& other);

    /// @brief moving consructor
    /// @param other 
    Zoo( Zoo&& other) noexcept;

    /// @brief moving operator =
    Zoo& operator =( Zoo&& other) noexcept;


    /// @brief function which is needed to display all the animals and their sounds
    void makeAllSounds()const;

    /// @brief releasing animal
    /// @param number the number of an animal we would like to release
    /// @return std::unique_ptr<Animal> released_animal
    std::unique_ptr<Animal> releaseAnimal(int number);

    //destructor
    ~Zoo();

};

#endif