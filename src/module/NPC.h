#ifndef theNPC
#define theNPC

struct NPC {
  std::string name;
  int ID;
  std::vector<std::string> inventory;
  int health;
  int strength;
  std::string armour;
  std::string weapon;



  NPC(std::string newName){
    name = newName;
  };
};
#endif
