#ifndef dialogTree
#define dialogTree
  #include "TBA.h"
  #include "io.h"
  struct DialogTree {
    public:

    IO * npc = new IO("Default", true) ;

    DialogTree();

    void process(std::string command, DialogTree  dt);

    void usage();

    void create();

    void load(DialogTree dt);

    void delete_dt();

  };


#endif
