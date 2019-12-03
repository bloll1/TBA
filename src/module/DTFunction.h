#ifndef DTFUNCTION
#define  DTFUNCTION
  #include "io.h"
  #include <string>
  #include <sstream>

struct DialogTree {
  public:

  IO * io_npc = new IO("Default", true);

  int number_of_entries;

  DialogTree();
  //===============================================================================
  //                            DIALOGTREE FUNCTIONS

  //when a new stream is loaded the meta data is stored in number_of_entries
  void DialogTree::load_meta();

  //when a new stream is loaded the meta data is stored in number_of_entries
  void DialogTree::create_meta();

  //displays the character commands for loaded npc
  void ch_usage();

  //processes character commands for a file tree
  void char_process(std::string cmd, DialogTree * dt);



};




#endif /* DialogTree */
