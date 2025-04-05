#include <iostream>
#include "Trainer.h"
#include "Team.h"

void Trainer::addTeam(Team& team){
    TeamNode* new_node = new TeamNode(team);
    if(!m_head){
        m_head=new_node;
        m_tail=new_node;
    }
    else{
        m_tail->next = new_node;
        new_node->prev=m_tail;
        m_tail=new_node;
    }
     std::cout << "Added Team: " << team.getName() << std::endl;
}

void Trainer::printTeams() const{
    std::cout<<"Trainer "<<m_name<<" teams:"<<std::endl; 
    TeamNode* current = m_head;
    while (current) {
    std::cout<<"- "<<current->data.getName()<<std::endl;
    current = current->next;
}
}

Trainer::~Trainer(){
        TeamNode* current = m_head;
        while (current) {
            TeamNode* next = current->next;
            delete current;  
            current = next;
        }
}