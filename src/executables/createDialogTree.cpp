#include <cstring>
#include "createDialogTree.h"
#include <iostream>


int main(int argc, char const *argv[]) {
  DialogTree dt = new DialogTree();
  std::string command;

  do {

  } while (command != "q" || command != "quit")


  return 0;
}

void DialogTree::process(std::string command) {
  
}

void DialogTree::usage() {
  std::cout <<
              "Commands:" << '\n'
  << "        create | c - creates a new npc with a given name" <<  '\n'
  << "        load   | l - loads a npc's dialog tree by name" <<    '\n'
  << "        delete | d - delete's npc from the file" <<           '\n';
}



DialogTree::DialogFile(string fileName, bool initialize):
    stream{fileName, ios::in | ios::out | ios::binary} {
  if (!stream.is_open() && initialize) {
    stream.open(fileName, ios::in | ios::out | ios::binary | ios::trunc);
  } else {
    stream = nullptr;
  }
}

DialogTree::~DialogFile() {
    stream.close();
}

void DialogTree::flush_stream() {
  stream.flush();
}


void DialogTree::write(size_t k, char * str, size_t blockSize) {
  char buffer[blockSize];
  buffer[blockSize - 1] = '\0';
  strncpy(buffer, str, blockSize - 1);
  stream.seekp(k*blockSize, ios::beg);
  stream.write(buffer, blockSize);
  stream.flush();
}


char * DialogTree::read(size_t k, char * oldbuffer, size_t blockSize) {
  char str[blockSize];
  strncpy(str, oldbuffer, blockSize);
  stream.seekg(k*blockSize, ios::beg);
  stream.read(str, blockSize);
  char * buffer = new char[blockSize + 1];
  strncpy(buffer, str, blockSize);
  return buffer;
}
