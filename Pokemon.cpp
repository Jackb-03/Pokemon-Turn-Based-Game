#include "Pokemon.h"

#include <iostream>
#include <string>
using namespace std;
// Default contructor
Pokemon::Pokemon() {}
// Pokemon Contructor
Pokemon::Pokemon(string name, string type, string attack1, string attack2,
                 string attack3, int health, int number) {
  this->name = name;
  this->type = type;
  this->attack1 = attack1;
  this->attack2 = attack2;
  this->attack3 = attack3;
  this->health = health;
}
// Setters
void Pokemon::setPokemonName(string name) { this->name = name; }
void Pokemon::setPokemonType(string type) { this->type = type; }
void Pokemon::setPokemonAttack1(string attack1) { this->attack1 = attack1; }
void Pokemon::setPokemonAttack2(string attack2) { this->attack2 = attack2; }
void Pokemon::setPokemonAttack3(string attack3) { this->attack3 = attack3; }
void Pokemon::setPokemonHealth(int health) { this->health = health; }

// Getters
int Pokemon::getPokemonHealth() { return health; }
string Pokemon::getPokemonName() { return name; }
string Pokemon::getPokemonType() { return type; }
string Pokemon::getPokemonAttack(int val) {
  switch (val) {  // Switch statement for return correlated attack
    case 1:
      return this->attack1;
      break;
    case 2:
      return this->attack2;
      break;
    case 3:
      return this->attack3;
      break;
    default:
      return 0;
  }
}

// Attack member function
int Pokemon::useAttack(Pokemon* target, string attack) {
  // Pointers
  int chance;
  int* chancePtr = &chance;

  float damage;
  float* damageptr = &damage;

  float multiplier;
  float* multiplierPtr = &multiplier;

  // Comparing the attacking pokemon type to the target pokemon to set damage
  // multiplier
  if (((this->getPokemonType() == "Fire") &&
       (target->getPokemonType() == "Water")) ||
      ((this->getPokemonType() == "Water") &&
       (target->getPokemonType() == "Grass")) ||
      ((this->getPokemonType() == "Grass") &&
       (target->getPokemonType() == "Fire"))) {
    multiplier = 0.5;
  } else if (((target->getPokemonType() == "Fire") &&
              (this->getPokemonType() == "Water")) ||
             ((target->getPokemonType() == "Water") &&
              (this->getPokemonType() == "Grass")) ||
             ((target->getPokemonType() == "Grass") &&
              (this->getPokemonType() == "Fire"))) {
    *multiplierPtr = 1.3;
  }
  // Attack 1
  if (attack == this->attack1) {
    *damageptr = 25 * *multiplierPtr;  // Calculate damage

    // Attack 2
  } else if (attack == this->attack2) {
    int chance = (rand() % 100);  // Get random hit chance
    if (chance > 75) {            // 75% hit chance
      *chancePtr = 0;
    } else {
      *chancePtr = 1;
    }
    *damageptr =
        50 * *multiplierPtr * *chancePtr;  // Calculate damage with hit chance
  }
  // Attack 3
  else if (attack == this->attack3) {
    int chance = (rand() % 100);
    if (chance > 50) {
      *chancePtr = 0;
    } else {
      *chancePtr = 1;
    }
    *damageptr = 75 * *multiplierPtr * *chancePtr;
  }

  int newHealth = target->health - damage;  // Calculate the target's new health
  target->setPokemonHealth(newHealth);      // Set the target's new health
  return (target->getPokemonHealth());
}

// Default destructor
Pokemon::~Pokemon() {}