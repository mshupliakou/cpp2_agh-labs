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
        for(const  std::unique_ptr<Animal>& a: other.animals){
            animals.push_back(a->clone());
        }
    }

    Zoo Zoo::operator=(const Zoo& other){
    for(const  std::unique_ptr<Animal>& a: other.animals){
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
