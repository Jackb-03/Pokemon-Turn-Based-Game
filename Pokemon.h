#ifndef Pokemon_h
#define Pokemon_h

#include <string>

using namespace std;

class BasicPokemon {  // Basic Pokemon class
 public:
  string name;
  int health;
};

class TypePokemon : public BasicPokemon {  // Type Pokemon class with type
 public:
  string type;
};

class Pokemon : public TypePokemon {  // Pokemon class with attacks
 public:
  string attack1;
  string attack2;
  string attack3;

 public:
  Pokemon();  // Default Constructor
  Pokemon(string name, string type, string attack1, string attack2,
          string attack3, int health,
          int number);  // Default Constructor

  // Setters
  void setPokemonName(string name);
  void setPokemonType(string type);
  void setPokemonAttack1(string attack1);
  void setPokemonAttack2(string attack2);
  void setPokemonAttack3(string attack3);
  void setPokemonHealth(int health);

  // Getters
  string getPokemonName();
  string getPokemonType();
  string getPokemonAttack(int val);
  int getPokemonHealth();

  // Attack
  int useAttack(Pokemon* target, string attack);
  // Default Destructor
  ~Pokemon();
};

#endif