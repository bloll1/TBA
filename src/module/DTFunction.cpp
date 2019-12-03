#include "DTFunction.h"

DialogTree::DialogTree() {

}


//                            DIALOGTREE FUNCTIONS


void DialogTree::load_meta() {
  char hello = 'a';
  char * metainf = io_npc->read(0, &hello, sizeof(number_of_entries));
  number_of_entries = atoi(metainf);
}

void DialogTree::update_meta(int newMeta) {
  number_of_entries = newMeta;
  char metainf = number_of_entries;
  io_npc->write(0, &metainf, sizeof(number_of_entries));
}

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
    dt->addline();
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




void DialogTree::addline() {

}
