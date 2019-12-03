#include <cstring>
#include "createDialogTree.h"
#include <iostream>
#include <sstream>




int main(int argc, char const *argv[]) {
  DialogTree * dt = new DialogTree();
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
    while (dt->npc_name != "Default" && dt->npc->stream.is_open()
                        && ccommand != "quit" && ccommand != "q") {
      std::cout << "\033[1;37m NPC - \033[0m" << "\033[1;36m" << dt->npc_name << ": \033[0m";
      ccommand = read();
      dt->char_process(ccommand, dt);
    }

  } while (command != "q" && command != "quit");
  return 0;
}




DialogTree::DialogTree() {

}




//================================================================================
//                              NPC RELATED FUNCTIONS




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




void DialogTree::process(std::string cmd, DialogTree * dt) {
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




void DialogTree::delete_dt(std::string parameters) {
  if (parameters != "") {
    std::remove(parameters.c_str());
  } else {
    std::cout << "Delete NPC Name: ";
    std::remove(read().c_str());
  }
}




void DialogTree::load(DialogTree * dt, std::string parameters) {
  dt->npc->stream.close();
  if (parameters != "") {
    dt->npc_name = parameters;
    dt->npc = new IO(dt->npc_name, false);
  } else {
    std::cout << "Load NPC Name: ";
    dt->npc_name = read();
    dt->npc = new IO(dt->npc_name, false);
  }
  if (!dt->npc->stream.is_open()) {
    std::cout << "Error: " << dt->npc_name << " is not a Valid NPC Name" << '\n';
    std::cout << "Press quit or q to exit" << '\n';
    std::cout << std::endl;
    dt->npc = new IO("Default", true);
    dt->npc_name = "Default";
  }
}




void DialogTree::create(DialogTree * dt, std::string parameters) {
  if (parameters != "") {
    dt->npc_name = parameters;
    npc = new IO(dt->npc_name, true);
  } else {
    std::cout << "NPC Name: ";
    dt->npc_name = read();
    npc = new IO(dt->npc_name, true);
  }
}




//                            END OF NPC FUNCTIONS
//===============================================================================
//                            DIALOGTREE FUNCTIONS




void DialogTree::ch_usage() {
  std::cout << std::endl;
  std::cout <<
              "Commands:" << '\n'
  << "        help       | h                  - displays this help page" <<           '\n'
  << "        addline    | al                 - adds a line, gives next #, points current line to it " <<              '\n'
  << "        deleteline | dl <LINE_NUMBER>   - delete a given line" <<    '\n'
  << "        editline   | el <LINE_NUMBER>   - edit a line by LINE_NUMBER" <<           '\n'
  << "        move       | m  <LINE_NUMBER>   - delete's npc from the file" <<           '\n'
  << "        point      | p  <LINE_NUMBER> to <LINE_NUMBER>  - points text to option" <<           '\n'
  << "        readtree   | rt                 - prints all the dialog tree" <<  '\n'
  << "        quit       | q                  - closes the npc file" <<                    '\n';
}




void DialogTree::char_process(std::string cmd, DialogTree * dt) {
  std::stringstream strnstream(cmd);
  std::string command;
  strnstream >> command;
  std::string parameters;
  strnstream >> parameters;
  if (command == "help" || command == "h" || command == "") {
    dt->ch_usage();
  } else if (command == "addline" || command == "al") {
    //dt->addline();
  } else if (command == "deleteline" || command == "dl") {
    //dt->deleteline(parameters);
  } else if (command == "editline" || command == "el") {
    //dt->editline(parameters);
  } else if (command == "move" || command == "m") {
    //dt->move(parameters);
  } else if (command == "point" || command == "p") {
    //dt->point(parameters);
  } else if (command == "readtree" || command == "rt") {
    //dt->readtree();
  } else if (command == "quit" || command == "q") {
  } else {
    std::cout << "Error: " << command << " is unkown try <help>" << '\n';
  }
}
