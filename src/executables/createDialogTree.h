#ifndef dialogTree
#define dialogTree
  #include "TBA.h"
  #include "io.h"
  struct DialogTree {
    public:

    IO * npc;

    DialogTree();

    void process(std::string command, DialogTree  dt);

    void usage();



  };


#endif
