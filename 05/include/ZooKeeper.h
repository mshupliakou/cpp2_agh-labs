#include <iostream>
#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include <memory>
class Animal;

///@brief class which describes a zoo keeper
class ZooKeeper{
    std::unique_ptr<Animal> own_amimal;
    public:
    ///@brief function describes a process of taking care of an animal
    void takeAnimal(std::unique_ptr<Animal> a);

    ///@brief to make an animal to make a noise
    void makeAnimalSound()const;

    //default constructor
    ZooKeeper(){}

    //default destructor 
    ~ZooKeeper(){
        std::cout<<"ZooKeeper was destroyed"<<std::endl;
    }

};



#endif