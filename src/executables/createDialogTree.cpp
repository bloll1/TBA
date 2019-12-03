#include <cstring>
#include "createDialogTree.h"
#include <iostream>
#include <sstream>




int main(int argc, char const *argv[]) {
  NPC * dt = new NPC();
  std::string command;
  std::string ccommand;
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
    dt->process(command, dt);
    while (dt->npc_name != "Default" && dt->dt_npc->io_npc->stream.is_open()
                        && ccommand != "quit" && ccommand != "q") {
      std::cout << "\033[1;37m NPC - \033[0m" << "\033[1;36m" << dt->npc_name << ": \033[0m";
      ccommand = read();
      dt->dt_npc->char_process(ccommand, dt->dt_npc);
    }

  } while (command != "q" && command != "quit");
  return 0;
}




NPC::NPC() {

}




//================================================================================
//                              NPC RELATED FUNCTIONS




void NPC::usage() {
  std::cout << std::endl;
  std::cout <<
              "Commands:" << '\n'
  << "        help   | h            - displays this help page" <<              '\n'
  << "        create | c <NPC NAME> - creates a new npc with a given name" <<  '\n'
  << "        load   | l <NPC NAME> - loads a npc's dialog tree by name" <<    '\n'
  << "        delete | d <NPC NAME> - delete's npc from the file" <<           '\n'
  << "        quit   | q            - exits the program" <<                    '\n';
}




void NPC::process(std::string cmd, NPC * dt) {
  std::stringstream strnstream(cmd);
  std::string command;
  strnstream >> command;
  std::string parameters;
  strnstream >> parameters;
  if (command == "help" || command == "h" || command == "") {
    dt->usage();
  } else if (command == "create" || command == "c") {
    dt->create(dt, parameters);
  } else if (command == "load" || command == "l") {
    dt->load(dt, parameters);
  } else if (command == "delete" || command == "d") {
    dt->delete_dt(parameters);
  } else if (command == "quit" || command == "q") {
  } else {
    std::cout << "Error: " << command << " is unkown try <help>" << '\n';
  }

}




void NPC::delete_dt(std::string parameters) {
  if (parameters != "") {
    std::remove(parameters.c_str());
  } else {
    std::cout << "Delete NPC Name: ";
    std::remove(read().c_str());
  }
}




void NPC::load(NPC * dt, std::string parameters) {
  dt->dt_npc->io_npc->stream.close();
  if (parameters != "") {
    dt->npc_name = parameters;
    dt->dt_npc->io_npc = new IO(dt->npc_name, false);
  } else {
    std::cout << "Load NPC Name: ";
    dt->npc_name = read();
    dt->dt_npc->io_npc = new IO(dt->npc_name, false);

  }
  if (!dt->dt_npc->io_npc->stream.is_open()) {
    std::cout << "Error: " << dt->npc_name << " is not a Valid NPC Name" << '\n';
    std::cout << std::endl;
    dt->dt_npc->io_npc = new IO("Default", true);
    dt->npc_name = "Default";
  } else {
    dt->dt_npc->load_meta();
  }
}




void NPC::create(NPC * dt, std::string parameters) {
  if (parameters != "") {
    dt->npc_name = parameters;
    dt->dt_npc->io_npc = new IO(dt->npc_name, true);
  } else {
    std::cout << "NPC Name: ";
    dt->npc_name = read();
    dt->dt_npc->io_npc = new IO(dt->npc_name, true);
  }
  dt->dt_npc->load_meta();
}




//                            END OF NPC FUNCTIONS
//===============================================================================
