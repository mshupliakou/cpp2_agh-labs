#include <iostream>
#include <memory>
#include <vector>
#include "Zoo.h"
    void Zoo::addAnimal(std::unique_ptr<Animal> a){
        animals.push_back(std::move(a));
    }

    void Zoo::makeAnimalSound(int number)const{
        if(!animals.empty())
        std::cout<<animals[number]->getSound()<<std::endl;
        else{
           std::cout<<"Zoo is empty!"<<std::endl; 
        }
    }

    Zoo::Zoo(const Zoo& other){
    if(&other != this)
        for(const  std::unique_ptr<Animal>& a: other.animals){
            if(a)
            animals.push_back(a->clone());
        }
    }

    Zoo Zoo::operator=(const Zoo& other){
    if(&other != this)
    for(const std::unique_ptr<Animal>& a: other.animals){
        if(a)
            animals.push_back(a->clone());
        }
        return *this;
    }

    Zoo::Zoo( Zoo&& other) noexcept{
        animals=std::move(other.animals);
    }

    Zoo& Zoo:: operator =( Zoo&& other) noexcept{
        animals=std::move(other.animals);
        return *this;
    }

    Zoo::    ~Zoo(){
        std::cout<<"Zoo was destroyed"<<std::endl;
    }


    void Zoo::makeAllSounds()const{
        if(animals.empty()){
            std::cout<<"Zoo is empty!"<<std::endl;
        }
        for(const std::unique_ptr<Animal>& a: animals){
            if(a)
            std::cout<<a->getSound()<<std::endl;
        }
    }

    std::unique_ptr<Animal> Zoo::releaseAnimal(int number){
        std::unique_ptr<Animal> a = std::move(animals[number]);
        return a;
    }