#include <iostream>
#include "Pokemon.h"
#include "Team.h"

void Team::addPokemon(Pokemon &pokemon){
    PokemonNode* new_node = new PokemonNode(pokemon);
    if (!m_head) {
        m_head = new_node;
        m_tail = new_node;
    } else {
        m_tail->next = new_node;
        new_node->prev = m_tail;
        m_tail = new_node;
    }
     std::cout << "Added Pokemon: " << pokemon.getName() << std::endl;

}

void Team::printPokemonsForward()const{
    if (!m_head){
        std::cout << "No pokemons in the team!" << std::endl;
        return;
    }
    PokemonNode* current = m_head;
    while(current){
        current->data.printInfo();
        current = current->next;
    }
}

std::string Team::getName() const{
    return m_name;
}

Team::~Team(){
        PokemonNode* current = m_head;
        while (current) {
            PokemonNode* next = current->next;
            delete current;  
            current = next;
        }
}

void Team::printPokemonsBackward() const {
    PokemonNode* current = m_tail;
    while (current) {
        current->data.printInfo();
        current = current->prev;
    }
}

Pokemon Team::operator[](int index){
    int i=0;
    PokemonNode* current = m_head;
    while (current) {
        if(i==index){
            return current->data;
        }
    current = current->next;
    i++;
}

Pokemon non("None", "None");
    return non;
}

void Team::removePokemon(std::string name){
    PokemonNode* current = m_head;
    while(current){
        if(current->data.getName()==name){
            if (current->prev) {
                current->prev->next=current->next;
            }
            else{
                m_head=current->next;
            }
            if(current->next) {
                current->next->prev=current->prev;
            } 
            else{
                m_tail=current->prev;
            }
            delete current;
            return; 
        }
    current = current->next;
    }
}