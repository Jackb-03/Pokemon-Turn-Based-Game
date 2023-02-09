#ifndef Commentator_h
#define Commentator_h
#include <stdlib.h>

#include <iostream>
#include <string>

#include "Player.h"
#include "Pokemon.h"

using namespace std;

class Commentator {
 public:
  Commentator();  // Default Constructor

  ~Commentator();  // Default Destructor
};

class PokemonSelection : public Commentator {
 public:
  // Instantiate member functions
  void playersPickPokemon(Person *Person, AI *Ai, Pokemon *Pokemon1,
                          Pokemon *Pokemon2, Pokemon *Pokemon3);
  void gameLoop(AI *Ai, Person *Person);
  void endGame(AI *Ai, Person *Person);
};

#endif