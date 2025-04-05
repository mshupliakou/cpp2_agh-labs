#ifndef TEAM_H
#define TEAM_H

#include "Pokemon.h"
#include <string>
#include <iostream>

/**
 * @class Team
 * @brief Represents a Pokémon team.
 * 
 * The class is used to store a team of Pokémon in a doubly linked list.
 * Each object of this class contains the team's name and pointers to the first and last elements of the Pokémon list.
 */
class Team {
    std::string m_name; /**< The name of the team. */
    PokemonNode* m_head; /**< Pointer to the first element of the Pokémon list. */
    PokemonNode* m_tail; /**< Pointer to the last element of the Pokémon list. */

public:
    /**
     * @brief Constructor for the team.
     * 
     * Initializes the team's name and sets the first and last pointers of the list to nullptr.
     * 
     * @param m_name The name of the team.
     */
    Team(std::string m_name):m_name(m_name), m_head(nullptr), m_tail(nullptr){}

    /**
     * @brief Adds a Pokémon to the team.
     * 
     * This function creates a new list node containing the Pokémon and adds it to the end of the team's list.
     * 
     * @param pokemon The Pokémon to be added.
     */
    void addPokemon(Pokemon& pokemon);

    /**
     * @brief Removes a Pokémon by name from the team.
     * 
     * This function searches the list for a Pokémon with the given name and removes it. 
     * If the Pokémon is not found, nothing happens.
     * 
     * @param name The name of the Pokémon to be removed.
     */
    void removePokemon(std::string name);

    /**
     * @brief Indexing operator.
     * 
     * Provides access to the Pokémon in the team by index.
     * 
     * @param index The index of the Pokémon in the team.
     * @return Returns the Pokémon located at the given index.
     */
    Pokemon operator[](int index);

    /**
     * @brief Prints information about all the Pokémon in the team, from the first to the last.
     * 
     * This function iterates through the list of Pokémon and prints their information in order.
     */
    void printPokemonsForward() const;

    /**
     * @brief Prints information about all the Pokémon in the team, from the last to the first.
     * 
     * This function iterates through the list of Pokémon in reverse order and prints their information.
     */
    void printPokemonsBackward() const;

    /**
     * @brief Destructor.
     * 
     * Cleans up the memory by deleting all nodes in the Pokémon list.
     */
    ~Team();  

    /**
     * @brief Gets the name of the team.
     * 
     * @return The name of the team.
     */
    std::string getName() const;
};

#endif
