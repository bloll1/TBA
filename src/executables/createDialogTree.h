#ifndef NPC
#define NPC
  #include "TBA.h"
  #include "io.h"
  #include "DTFunction.h"
  #include <string>
  struct NPC {
    public:

    //TODO: Consider making a seperate class for in character tree creating


    //NPC object for i/o calls

    DialogTree * dt_npc = new DialogTree();

    //the name of the current npc open
    std::string npc_name = "Default";

    //Default Constructor
    NPC();

    //================================================================================
    //                              NPC RELATED FUNCTIONS


    //display the default commands for npc loading/creation/deletion
    void usage();

    //processes the given command and calls the according funcion
    void process(std::string cmd, DialogTree * dt);

    //deletes a npc by given name
    void delete_dt(std::string parameters);

    //load a npc's file checks if file exists while loading
    void load(DialogTree * dt, std::string parameters);

    //create a new npc by given name and set the IO object in
    //the DialogTree class to it
    void create(DialogTree * dt, std::string parameters);


    //                            END OF NPC FUNCTIONS
    //===============================================================================
  };


#endif
