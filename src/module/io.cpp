#include "io.h"

IO::IO(std::string fileName, bool initialize) :
    stream{fileName, std::ios::in | std::ios::out | std::ios::binary} {
  if (!stream.is_open() && initialize) {
    stream.open(fileName, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
  } else {
    stream.close();
  }
}


IO::~IO() {
    stream.close();
}

void IO::flush_stream() {
  stream.flush();
}


void IO::write(size_t k, char * str, size_t blockSize) {
  char buffer[blockSize];
  buffer[blockSize - 1] = '\0';
  strncpy(buffer, str, blockSize - 1);
  stream.seekp(k*blockSize, std::ios::beg);
  stream.write(buffer, blockSize);
  stream.flush();
}

char * IO::read(size_t k, char * oldbuffer, size_t blockSize) {
  char str[blockSize];
  strncpy(str, oldbuffer, blockSize);
  stream.seekg(k*blockSize, std::ios::beg);
  stream.read(str, blockSize);
  char * buffer = new char[blockSize + 1];
  strncpy(buffer, str, blockSize);
  return buffer;
}

/*read: reads the user input are returns it in a string type
*/
std::string read() {
  std::string output;
  std::cin >> output;
  return output;
}
