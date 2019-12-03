#ifndef DTFUNCTION
#define  DTFUNCTION
  #include "io.h"
  #include <string>
  #include <sstream>

struct DialogTree {
  public:

  IO * io_npc = new IO("Default", true);

  DialogTree();
  //===============================================================================
  //                            DIALOGTREE FUNCTIONS

  //displays the character commands for loaded npc
  void ch_usage();

  //processes character commands for a file tree
  void char_process(std::string cmd, DialogTree * dt);

};




#endif /* DialogTree */
