#include "Commentator.h"

#include <stdlib.h>

#include <string>

#include "Player.h"
#include "Pokemon.h"

using namespace std;

// Default de/constructor
Commentator::Commentator() {}

Commentator::~Commentator() {}

// Define the Pokemon selection phase of the game
void PokemonSelection::playersPickPokemon(Person *Person, AI *Ai,
                                          Pokemon *Pokemon1, Pokemon *Pokemon2,
                                          Pokemon *Pokemon3) {
  int choice;

  do {
    cout << "Choose a starter pokemon: " << endl;

    cout << "[1]" << Pokemon1->getPokemonName() << " "
         << "[2]" << Pokemon2->getPokemonName() << " "
         << "[3]" << Pokemon3->getPokemonName() << " "
         << endl;   // Provide Person with 3 options
    cin >> choice;  // Take choice input from Person
    cout << endl;
    if (cin.fail()) {  // If Person enters non-int then clear cin buffer and ask
                       // again
      cout << "Error: Input is not an Integer!" << endl;
      cin.clear();
      cin.ignore(100, '\n');
    }
  } while (choice < 1 || choice > 3);
  switch (choice) {  // Switch statement for Person's choice
    case 1:
      cout << "Your starter pokemon is " << Pokemon1->getPokemonName()
           << endl;  // Notify the Person of what they chose
      Person->playersPokemon =
          Pokemon1;  // Allocate the chosen Pokemon to the Person

      break;
    case 2:
      cout << "Your starter pokemon is " << Pokemon2->getPokemonName() << endl;
      Person->playersPokemon = Pokemon2;

      break;
    case 3:
      cout << "Your starter pokemon is " << Pokemon3->getPokemonName() << endl;
      Person->playersPokemon = Pokemon3;
      break;
  }
  choice = Ai->selectPokemonNumber;  // Using the AI member function generate
                                     // random number between 1-3

  switch (choice) {
    case 1:

      Ai->playersPokemon = Pokemon1;  // Switch statement for AI's choice
      if (Ai->playersPokemon ==
          Person->playersPokemon) {  // Check if the AI has chosen the same
                                     // Pokemon as the Person
        Ai->playersPokemon =
            Pokemon2;  // If so assign a different Pokemon to the AI
      }
      cout << "--Enemy's  pokemon is " << Pokemon1->getPokemonName() << endl
           << endl;  // Output the AI's pokemon in the terminal

      break;
    case 2:
      Ai->playersPokemon = Pokemon2;
      if (Ai->playersPokemon == Person->playersPokemon) {
        Ai->playersPokemon = Pokemon3;
      }
      cout << "--Enemy's  pokemon is " << Pokemon1->getPokemonName() << endl
           << endl;

      break;
    case 3:
      Ai->playersPokemon = Pokemon3;
      if (Ai->playersPokemon == Person->playersPokemon) {
        Ai->playersPokemon = Pokemon1;
      }
      cout << "--Enemy's pokemon is " << Pokemon1->getPokemonName() << endl
           << endl;

      break;
  }
}

void PokemonSelection::gameLoop(AI *Ai, Person *Person) {
  cout << "--- LET THE BATTLE BEGIN ---" << endl;
  cout << "Remember Attacks have Different damages and success rates choose "
          "wisely to win!"  // Give basic instructions to the player
       << endl
       << endl;
  while (Ai->getPlayersPokemon()->getPokemonHealth() > 0 &&
         Person->getPlayersPokemon()->getPokemonHealth() >
             0) {  // If both players Pokemon have more then 0 health then loop
    int choice;
    //---------Person's Turn---------
    do {
      cout << "Choose an Attack Move " << endl;

      cout << "[1]" << Person->getPlayersPokemon()->getPokemonAttack(1) << " "
           << "[2]" << Person->getPlayersPokemon()->getPokemonAttack(2) << " "
           << "[3]" << Person->getPlayersPokemon()->getPokemonAttack(3) << " "
           << endl;
      cin >> choice;
      cout << endl;
      if (cin.fail()) {
        cout << "Error: Input is not an Integer!" << endl;
        cin.clear();  // If Person enters non-int then clear cin buffer and ask
                      // again
        cin.ignore(100, '\n');
      }
    } while (choice < 1 || choice > 3);
    switch (choice) {
      case 1:
        cout << "You selected: "
             << Person->getPlayersPokemon()->getPokemonAttack(1)
             << endl;  // Tell person what they have selected
        Person->getPlayersPokemon()->useAttack(
            Ai->playersPokemon,
            Person->getPlayersPokemon()->getPokemonAttack(
                1));  // Use the attack member function to damage opponent
        if (Ai->playersPokemon->getPokemonHealth() <=
            0) {  // If the AI Pokemon has 0 or less health tell that player the
                  // pokemon has fainted
          cout << endl;
          cout << "***The enemy's, " << Ai->playersPokemon->getPokemonName()
               << " has fainted" << endl;
        } else {  // else show the person the amount of health the enemy pokemon
                  // has left
          cout << "---The enemy, " << Ai->playersPokemon->getPokemonName()
               << " is now on " << Ai->playersPokemon->getPokemonHealth()
               << " Health" << endl
               << endl;
        }
        break;
      case 2:
        cout << "You selected: "
             << Person->getPlayersPokemon()->getPokemonAttack(2) << endl;
        Person->getPlayersPokemon()->useAttack(
            Ai->playersPokemon,
            Person->getPlayersPokemon()->getPokemonAttack(2));
        if (Ai->playersPokemon->getPokemonHealth() <= 0) {
          cout << endl;
          cout << "***The enemy's, " << Ai->playersPokemon->getPokemonName()
               << " has fainted" << endl;
        } else {
          cout << "---The enemy, " << Ai->playersPokemon->getPokemonName()
               << " is now on " << Ai->playersPokemon->getPokemonHealth()
               << " Health" << endl
               << endl;
        }
        break;
      case 3:
        cout << "You selected: "
             << Person->getPlayersPokemon()->getPokemonAttack(3) << endl;
        Person->getPlayersPokemon()->useAttack(
            Ai->playersPokemon,
            Person->getPlayersPokemon()->getPokemonAttack(3));
        if (Ai->playersPokemon->getPokemonHealth() <= 0) {
          cout << endl;
          cout << "***The enemy's, " << Ai->playersPokemon->getPokemonName()
               << " has fainted" << endl;
        } else {
          cout << "---The enemy, " << Ai->playersPokemon->getPokemonName()
               << " is now on " << Ai->playersPokemon->getPokemonHealth()
               << " Health" << endl
               << endl;
        }
        break;
    }
    //---------Ai's Turn---------
    if (Ai->getPlayersPokemon()->getPokemonHealth() > 0) {
      choice = Ai->selectAttack();  // Check if AI Pokemon is still alive, if so
                                    // then it can attack
      switch (choice) {
        case 1:
          cout << "---The enemy selected: "
               << Ai->getPlayersPokemon()->getPokemonAttack(1)
               << endl;  // Tell the Person what move the AI chose
          Ai->getPlayersPokemon()->useAttack(
              Person->playersPokemon,
              Ai->getPlayersPokemon()->getPokemonAttack(
                  1));  // Using the Pokemon attack member function damage the
                        // Person's Pokemon
          if (Person->playersPokemon->getPokemonHealth() <= 0) {
            cout << endl;
            cout << "***Your " << Person->playersPokemon->getPokemonName()
                 << " has fainted" << endl;
          } else {
            cout << "Your " << Person->playersPokemon->getPokemonName()
                 << " is now on " << Person->playersPokemon->getPokemonHealth()
                 << " Health" << endl
                 << endl;
          }

          break;
        case 2:;
          cout << "---The enemy selected: "
               << Ai->getPlayersPokemon()->getPokemonAttack(2) << endl;
          Ai->getPlayersPokemon()->useAttack(
              Person->playersPokemon,
              Ai->getPlayersPokemon()->getPokemonAttack(2));
          if (Person->playersPokemon->getPokemonHealth() <= 0) {
            cout << endl;
            cout << "***Your " << Person->playersPokemon->getPokemonName()
                 << " has fainted" << endl;
          } else {
            cout << "Your " << Person->playersPokemon->getPokemonName()
                 << " is now on " << Person->playersPokemon->getPokemonHealth()
                 << " Health" << endl
                 << endl;
          }

          break;

        case 3:
          cout << "---The enemy selected: "
               << Ai->getPlayersPokemon()->getPokemonAttack(3) << endl;
          Ai->getPlayersPokemon()->useAttack(
              Person->playersPokemon,
              Ai->getPlayersPokemon()->getPokemonAttack(3));
          if (Person->playersPokemon->getPokemonHealth() <= 0) {
            cout << endl;
            cout << "***Your " << Person->playersPokemon->getPokemonName()
                 << " has fainted" << endl;
          } else {
            cout << "Your " << Person->playersPokemon->getPokemonName()
                 << " is now on " << Person->playersPokemon->getPokemonHealth()
                 << " Health" << endl
                 << endl;
          }

          break;
      }
    }
  }
}

void PokemonSelection::endGame(AI *Ai, Person *Person) {
  if (Ai->getPlayersPokemon()->getPokemonHealth() <
      0) {  // If the AI's Pokemon has 0 or less health
    cout << "Congratulations you have Won!";  // Congrat the player for winning
  } else if (Person->getPlayersPokemon()->getPokemonHealth() <
             0) {  // Else if the Person's Pokemon has 0 or less health
    cout << "You have lost!";  // Let them know they've lost
  }
}