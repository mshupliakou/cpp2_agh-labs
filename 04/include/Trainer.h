#ifndef TRAINER_H
#define TRAINER_H

#include "Team.h"
#include <string>
#include <iostream>

/**
 * @class Trainer
 * @brief Represents a Pokémon Trainer.
 * 
 * The class manages multiple Pokémon teams. Each trainer can have multiple teams, 
 * with each team containing several Pokémon.
 */
class Trainer {
    std::string m_name; /**< The name of the trainer. */
    
    /**
     * @struct TeamNode
     * @brief Represents a node in a doubly linked list that stores a Pokémon team.
     * 
     * Each node holds a Pokémon team and has pointers to the previous and next nodes in the list.
     */
    struct TeamNode {
        TeamNode* prev; /**< Pointer to the previous node. */
        Team data; /**< The team data stored in the node. */
        TeamNode* next; /**< Pointer to the next node. */

        /**
         * @brief Constructor for the TeamNode.
         * 
         * Initializes the node with a given Pokémon team and sets the previous and next pointers to nullptr.
         * 
         * @param team The Pokémon team to be stored in the node.
         */
        TeamNode(Team team) : data(team), prev(nullptr), next(nullptr) {}
    };

    TeamNode* m_head; /**< Pointer to the first node in the team list. */
    TeamNode* m_tail; /**< Pointer to the last node in the team list. */

public:
    /**
     * @brief Constructor for the Trainer.
     * 
     * Initializes the trainer with a given name and sets the head and tail of the team list to nullptr.
     * 
     * @param m_name The name of the trainer.
     */
    Trainer(std::string m_name) : m_name(m_name), m_head(nullptr), m_tail(nullptr) {}

    /**
     * @brief Adds a Pokémon team to the trainer's list of teams.
     * 
     * This function creates a new node to hold the team and appends it to the end of the list.
     * 
     * @param team The Pokémon team to be added.
     */
    void addTeam(Team& team);

    /**
     * @brief Prints all the teams of the trainer.
     * 
     * This function iterates through the list of teams and prints each team's Pokémon.
     */
    void printTeams() const;

    /**
     * @brief Destructor for the Trainer.
     * 
     * Frees the memory by deleting all the team nodes.
     */
    ~Trainer();  
};

#endif
