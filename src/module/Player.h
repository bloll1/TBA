#ifndef thePlayer
#define thePlayer
#include <vector>

struct Player {
  std::string name;
  std::vector<std::string> inventory;
  int health;
  int strength;
  int mana;
  std::string armour;
  std::string weapon;

  
  Player(std::string newName) {
    name = newName;
    health = 100;
    strength = 1;
    mana = 0;
  }
};
#endif
