#include <cstring>
#include "createDialogTree.h"
#include <iostream>

//cout << "\033[1;31mbold red text\033[0m\n";

int main(int argc, char const *argv[]) {
  DialogTree  dt;
  std::string command;
  for (size_t y = 0; y < 2; y++) {
    for (size_t i = 31; i < 37; i++) {
      std::cout << "COLOR #: " << i << " THINGY: " << y << " ";
      std::cout << "\033["<< y <<";" << i << "mLOOK AT ME \033[0m" << '\n';
    }
    for (size_t i = 41; i < 47; i++) {
      std::cout << "COLOR #: " << i << " THINGY: " << y << " ";
      std::cout << "\033["<< y <<";" << i << "mLOOK AT ME \033[0m" << '\n';
    }
  }

  do {
    std::cout << "\033[1;37mCRT: \033[0m";
    command = read();
    dt.process(command, dt);
  } while (command != "q" && command != "quit");


  return 0;
}

DialogTree::DialogTree() {

}

void DialogTree::process(std::string command, DialogTree dt) {
  if (command == "help" || command == "h" || command == "") {
    dt.usage();
  } else if (command == "create" || command == "c") {
    //dt.create(name);
    std::cout << "CALLED CREATE" << '\n';
  } else if (command == "load" || command == "l") {
    //dt.load(name);
    std::cout << "CALLED LOAD" << '\n';
  } else if (command == "delete" || command == "d") {
    //dt.delete(name);
    std::cout << "CALLED DELETE" << '\n';
  } else if (command == "quit" || command == "q") {
    std::cout << "CLOSING..." << '\n';
  } else {
    std::cout << "Error: " << command << " is unkown try <help>" << '\n';
  }

}

void DialogTree::usage() {
  std::cout << std::endl;
  std::cout <<
              "Commands:" << '\n'
  << "        help   | h            - displays this help page" <<              '\n'
  << "        create | c <NPC NAME> - creates a new npc with a given name" <<  '\n'
  << "        load   | l <NPC NAME> - loads a npc's dialog tree by name" <<    '\n'
  << "        delete | d <NPC NAME> - delete's npc from the file" <<           '\n'
  << "        quit   | q            - exits the program" <<                    '\n';
}
