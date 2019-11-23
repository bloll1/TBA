#ifndef dialogTree
#define dialogTree
  #include "TBA.h"
  #include <fstream>

  struct DialogTree{
    public:

    DialogTree();

    void DialogFile(string fileName, bool initialize);

    void ~DialogFile();

    void process(std::string command);

    void flush_stream();

    void usage();

    void DialogFile::write(size_t k, char * str, size_t blockSize);

    char * DialogFile::read(size_t k, char * oldbuffer, size_t blockSize);

    fstream stream = nullptr;
  };


#endif
