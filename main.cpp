#include <iostream>
#include <string>

#include "Commentator.h"
#include "Player.h"
#include "Pokemon.h"

using namespace std;

int main() {
  // Set up Pokemon
  Pokemon *bulbasaur = new Pokemon("Bulbasaur", "Grass", "Vine Wipe",
                                   "Leech Seed", "Seed Bomb", 100, 1);
  Pokemon *charmander = new Pokemon("Charmander", "Fire", "Amber", "Fire Fang",
                                    "Flamethrower", 100, 2);
  Pokemon *squirtle = new Pokemon("Squirtle", "Water", "Water Gun",
                                  "Water Pulse", "Hydro Pump", 100, 3);

  // Set up Players
  Person *p1 = new Person();
  AI *ai1 = new AI();
  PokemonSelection *game = new PokemonSelection;
  game->playersPickPokemon(p1, ai1, bulbasaur, charmander, squirtle);
  game->gameLoop(ai1, p1);
  game->endGame(ai1, p1);

  delete bulbasaur;
  delete charmander;
  delete squirtle;
  delete p1;
  delete ai1;
  delete game;

  return 0;
}
