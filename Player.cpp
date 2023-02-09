#include "Player.h"

#include <stdlib.h>

#include <string>

using namespace std;
// Default de / constructor
Player::Player() {}
Player::~Player() {}

// AI Player class member functions
void AI::setPlayersPokemon(Pokemon* object) {
  this->playersPokemon = object;
};  // Allocates the AI the Pokemon
Pokemon* AI::getPlayersPokemon() {
  return playersPokemon;
}  // returns what Pokemon the AI has

// AI Player class member functions
Person::Person() {}
Person::~Person() {}
void Person::setPlayersPokemon(
    Pokemon* object) {  // Allocates the Player the Pokemon
  this->playersPokemon = object;
};
Pokemon* Person::getPlayersPokemon() {
  return playersPokemon;
}  // returns what Pokemon the Persob has
