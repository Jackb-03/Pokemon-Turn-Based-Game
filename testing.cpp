#include <iostream>

#include "Commentator.h"
#include "Player.h"
#include "Pokemon.h"
using namespace std;

int main(int argc, char const *argv[]) {
  // Set up Pokemon
  Pokemon *bulbasaur = new Pokemon("Bulbasaur", "Grass", "Vine Wipe",
                                   "Leech Seed", "Seed Bomb", 100, 1);
  Pokemon *charmander = new Pokemon("Charmander", "Fire", "Amber", "Fire Fang",
                                    "Flamethrower", 100, 2);
  Pokemon *squirtle = new Pokemon("Squirtle", "Water", "Water Gun",
                                  "Water Pulse", "Hydro Pump", 100, 3);

  Person *p1 = new Person();
  AI *ai1 = new AI();

  cout << "Pokemon Setter and getter test" << endl;

  if (bulbasaur->attack1 == "Vine Wipe") {
    cout << "Pokemon Getter test successful" << endl;
  };

  bulbasaur->setPokemonAttack1("Grass Blade");
  if (bulbasaur->attack1 == "Grass Blade") {
    cout << "Pokemon Setter test successful";
  }

  return 0;
}
