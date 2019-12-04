#ifndef DTFUNCTION
#define  DTFUNCTION
  #include "io.h"
  #include <string>
  #include <sstream>
  #include <stdlib.h>
  #include <iostream>
  #include <vector>

struct DialogTree {
  public:

  IO * io_npc = new IO("Default", true);

  int number_of_entries;

  int current_line_cursor = 0;

  int children;

  int parent;

  char * data;

  DialogTree();
  //===============================================================================
  //                            DIALOGTREE FUNCTIONS

  //when a new stream is loaded the meta data is stored in number_of_entries
  void load_meta();

  //when a stream is added or created it updates the metainf to the new info
  void update_meta(int newMeta);

  //displays the character commands for loaded npc
  void ch_usage();

  //processes character commands for a file tree
  void char_process(std::string cmd, DialogTree * dt);

  //add a line to the current
  void addline();


private:
  //reads the parent, child, and data blocks
  void readblock(int blockNumber);

};



#endif /* DialogTree */
