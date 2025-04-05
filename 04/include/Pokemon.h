#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

/**
 * @class Pokemon
 * @brief Represents a Pokémon.
 * 
 * The class is used to store information about a single Pokémon, such as its name and type.
 */
class Pokemon {
    std::string m_name; /**< The name of the Pokémon. */
    std::string m_type; /**< The type of the Pokémon (e.g., Fire, Water, Grass). */

public:
    /**
     * @brief Constructor for the Pokémon.
     * 
     * Initializes the Pokémon with a given name and type.
     * 
     * @param m_name The name of the Pokémon.
     * @param m_type The type of the Pokémon.
     */
    Pokemon(std::string m_name, std::string m_type) : m_name(m_name), m_type(m_type) {}

    /**
     * @brief Prints the information of the Pokémon.
     * 
     * This function outputs the name and type of the Pokémon.
     */
    void printInfo() const;

    /**
     * @brief Gets the name of the Pokémon.
     * 
     * @return The name of the Pokémon.
     */
    std::string getName() const { return m_name; }
};

/**
 * @struct PokemonNode
 * @brief Represents a node in a doubly linked list that stores a Pokémon.
 * 
 * This structure is used in the doubly linked list to hold the Pokémon data along with 
 * pointers to the previous and next nodes in the list.
 */
struct PokemonNode {
    PokemonNode* prev; /**< Pointer to the previous node. */
    Pokemon data; /**< The Pokémon data stored in the node. */
    PokemonNode* next; /**< Pointer to the next node. */

    /**
     * @brief Constructor for the PokémonNode.
     * 
     * Initializes the node with a given Pokémon and sets the previous and next pointers to nullptr.
     * 
     * @param p The Pokémon to be stored in the node.
     */
    PokemonNode(Pokemon p) : data(p), prev(nullptr), next(nullptr) {}
};

#endif
