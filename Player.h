#ifndef Player_h
#define Player_h
#include <stdlib.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "Pokemon.h"

using namespace std;

class Player {  // Pure Abstract Player class
 public:
  Pokemon *playersPokemon;
  // Setters
  virtual void setPlayersPokemon(Pokemon *object) = 0;
  // Getters
  virtual Pokemon *getPlayersPokemon() = 0;
  // Default De/constructor
  Player();
  ~Player();
};

class AI : public Player {
 public:
  // Setters
  void setPlayersPokemon(
      Pokemon *object);  // Overriding the abstract class setter
  // Getters
  Pokemon *getPlayersPokemon();  // Overriding the abstract class getter
  int selectPokemonNumber = 1 + (rand() % 3);  // Random value for Pokemon
                                               // choice
  int selectMove;
  int selectAttack() {  // Member function for generating attack choices
    selectMove = 1 + (rand() % 3);
    return selectMove;
  }
};

class Person : public Player {
 public:
  // Setters
  void setPlayersPokemon(
      Pokemon *object);  // Overriding the abstract class setter
  // Getters
  Pokemon *getPlayersPokemon();  // Overriding the abstract class getter
  // Default De/constructor

  Person();
  ~Person();
};

#endif