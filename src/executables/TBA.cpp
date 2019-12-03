#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "TBA.h"
#ifdef __linux__
#include <unistd.h>
#endif

/*If the local system is windows or using a CYGWIN as a shell the native windows
*  header is included for the Sleep function
*/
#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#endif


int main(int argc, char const *argv[]) {
  printline("ENGLAND HAS THE BIGGEST EMPIRE IN AFRICA CIRCA 1890", 40000);
  printline("zzzzzzzzzzzz", 80000);
  printline("OHHH", 30000);
  printline("Hello, kind stanger", 45000);
  printline("Can I offer you the sex this evening?", 45000);
  printline("No?", 450000);
  printline("Well okay, thanks for waking me up!", 30000);
  return 0;
}

void usage() {


}

void mySleep(int mySleep) {
  #ifdef __linux__
    usleep(mySleep);
  #endif
  #if defined(_WIN32) || defined(__CYGWIN__)
    Sleep(mySleep / 1000);
  #endif
}

void printline(std::string input, int speed) {
  for (long unsigned int i = 0; i < input.length(); i++) {
    std::cout << input[i] << std::flush;
    mySleep(speed);
  }
  std::cout << '\n';
}




/*process: processes the command and calls the appropraite function
* @param - user command input
*/
void process(std::string command) {


}
