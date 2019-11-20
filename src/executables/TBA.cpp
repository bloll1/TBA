#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include "TBA.h"

int main(int argc, char const *argv[]) {
  printline("ENGLAND HAS THE BIGGEST EMPIRE IN AFRICA CIRCA 1890", 40000);
  printline("zzzzzzzzzzzz", 800000);
  printline("OHHH", 30000);
  printline("Hello, kind stanger", 45000);
  printline("Can I offer you the sex this evening?", 45000);
  printline("No?", 500000);
  printline("Well okay, thanks for waking me up!", 30000);
  return 0;
}

void usage() {


}

void printline(std::string input, int speed) {
  unsigned int microseconds = speed;//40000
  for (long unsigned int i = 0; i < input.length(); i++) {
    std::cout << input[i] << std::flush;
    usleep(microseconds);
  }
  std::cout << '\n';
}













std::string read() {
  std::string output;
  std::cin >> output;
  return output;
}

void process(std::string command) {


}
