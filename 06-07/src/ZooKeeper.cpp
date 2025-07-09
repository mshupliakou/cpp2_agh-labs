#include <iostream>
#include <memory>
#include "ZooKeeper.h"
#include "Animal.h"


void ZooKeeper::takeAnimal(std::unique_ptr<Animal> a){
    std::cout<<"ZooKeeper is now taking care of: "<<a->getType()<<" "<<a->getName()<<std::endl;
    own_amimal=std::move(a);
}
void ZooKeeper::makeAnimalSound()const{
    std::cout<<own_amimal->getSound()<<std::endl;
}