#ifndef INOUT
#define INOUT
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

class IO {
  public:
    
  IO(std::string fileName, bool initialize);

  ~IO();

  void write(size_t k, char * str, size_t blockSize);

  char * read(size_t k, char * oldbuffer, size_t blockSize);

  std::fstream stream;

  void flush_stream();
};

std::string read();
#endif
