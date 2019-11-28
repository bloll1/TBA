#include <cstring>
#include "createDialogTree.h"
#include <iostream>

//cout << "\033[1;31mbold red text\033[0m\n";

int main(int argc, char const *argv[]) {
  DialogTree  dt;
  std::string command;
  for (size_t y = 0; y < 3; y++) {
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

    while (dt.npc->stream.is_open() && command != "quit") {
      break;
    }
  } while (command != "q" && command != "quit");


  return 0;
}

DialogTree::DialogTree() {

}

void DialogTree::process(std::string command, DialogTree dt) {
  if (command == "help" || command == "h" || command == "") {
    dt.usage();
  } else if (command == "create" || command == "c") {
    dt.create();
  } else if (command == "load" || command == "l") {
    dt.load(dt);
    std::cout << "CALLED LOAD" << '\n';
  } else if (command == "delete" || command == "d") {
    dt.delete_dt();
    std::cout << "CALLED DELETE" << '\n';
  } else if (command == "quit" || command == "q") {
    std::cout << "CLOSING..." << '\n';
  } else {
    std::cout << "Error: " << command << " is unkown try <help>" << '\n';
  }

}

void DialogTree::delete_dt() {
  std::cout << "Delete NPC Name: ";
  std::remove(read().c_str());
}


void DialogTree::load(DialogTree dt) {
  dt.npc->stream.close();
  do {
    std::cout << "Load NPC Name: ";
    std::string name = read();
    npc = new IO(name, false);
    if (name == "quit" || name == "q") {
      npc = new IO("Default", true);
      break;
    }
    if (!dt.npc->stream.is_open()) {
      std::cout << "Error: " << name << " is not a Valid NPC Name" << '\n';
      std::cout << "Press quit or q to exit" << '\n';
      std::cout << std::endl;
    }
  } while(!dt.npc->stream.is_open());
}

void DialogTree::create() {
  std::cout << "NPC Name: ";
  npc = new IO(read(), true);
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
