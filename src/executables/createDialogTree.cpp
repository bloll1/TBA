#include <cstring>
#include "createDialogTree.h"
#include <iostream>


int main(int argc, char const *argv[]) {
  do {
  std::cout << "New NPC or old NPC? <n | o>" << '\n';
  std::string choice = read();
} while (choice != "n" && choice != "o")

if (choice == "n") {
  //create new character
} else {
  //load old character
}
  return 0;
}


DialogFile::DialogFile(string fileName, bool initialize):
    stream{fileName, ios::in | ios::out | ios::binary} {
  if (!stream.is_open() || initialize) {
    stream.open(fileName, ios::in | ios::out | ios::binary | ios::trunc);
  }
}

DialogFile::~DialogFile() {
    stream.close();
}

void DialogFile::flush_stream() {
  stream.flush();
}


void DialogFile::write(size_t k, char * str, size_t blockSize) {
  char buffer[blockSize];
  buffer[blockSize - 1] = '\0';
  strncpy(buffer, str, blockSize - 1);
  stream.seekp(k*blockSize, ios::beg);
  stream.write(buffer, blockSize);
  stream.flush();
}


char * DialogFile::read(size_t k, char * oldbuffer, size_t blockSize) {
  char str[blockSize];
  strncpy(str, oldbuffer, blockSize);
  stream.seekg(k*blockSize, ios::beg);
  stream.read(str, blockSize);
  char * buffer = new char[blockSize + 1];
  strncpy(buffer, str, blockSize);
  return buffer;
}
