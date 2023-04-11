#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store information about a Pokemon
struct PokemonNode {
char name[20];
char ability[20];
struct PokemonNode *next;
struct PokemonNode *prev;
};

// Define a struct to store information about a player
struct PlayerNode {
char name[20];
int pokemonCount;
struct PokemonNode *ownedPokemon[100];
struct PlayerNode *next;
struct PlayerNode *prev;
};

// Define a struct to store the Pokedex
struct Pokedex {
struct PokemonNode *headPokemon;
struct PlayerNode *headPlayer;
};

// Create a Pokedex
struct Pokedex pokedex;

// Function to create a new Pokemon node
struct PokemonNode *createPokemonNode(char name[], char ability[]) {
struct PokemonNode *newNode = (struct PokemonNode *)malloc(sizeof(struct PokemonNode));
strcpy(newNode->name, name);
strcpy(newNode->ability, ability);
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}

// Function to add a new Pokemon to the list
void addPokemonToList(struct PokemonNode *newNode) {
if (pokedex.headPokemon == NULL) {
pokedex.headPokemon = newNode;
} else {
struct PokemonNode *current = pokedex.headPokemon;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
newNode->prev = current;
}
}

// Function to search for a Pokemon by name
struct PokemonNode *searchPokemonByName(char name[]) {
struct PokemonNode *current = pokedex.headPokemon;
while (current != NULL) {
if (strcmp(current->name, name) == 0) {
return current;
}
current = current->next;
}
return NULL;
}

// Function to create a new Player node
struct PlayerNode *createPlayerNode(char name[]) {
struct PlayerNode *newNode = (struct PlayerNode *)malloc(sizeof(struct PlayerNode));
strcpy(newNode->name, name);
newNode->pokemonCount = 0;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}

// Function to add a new Player to the list
void addPlayerToList(struct PlayerNode *newNode) {
if (pokedex.headPlayer == NULL) {
pokedex.headPlayer = newNode;
} else {
struct PlayerNode *current = pokedex.headPlayer;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
newNode->prev = current;
}
}

// Function to add a Pokemon to a player's owned Pokemon list
void addPokemonToPlayer(struct PlayerNode *player, struct PokemonNode *pokemon) {
if (player->pokemonCount == 100) {
printf("Maximum number of owned Pokemon reached.\n");
} else {
player->ownedPokemon[player->pokemonCount] = pokemon;
player->pokemonCount++;
}
}

// Function to remove a Pokemon from a player's owned Pokemon list
void removePokemonFromPlayer(struct PlayerNode *player, struct PokemonNode *pokemon) {
int index = -1;
for (int i = 0; i < player->pokemonCount; i++) {
if (player->ownedPokemon[i] == pokemon) {
index = i;
break;
}
}
if (index == -1) {
printf("Pokemon not found in player's owned Pokemon list.\n");