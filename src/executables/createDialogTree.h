#ifndef dialogTree
#define dialogTree
  #include "TBA.h"
  #include <fstream>

  DialogFile(string fileName, bool initialize);

  ~DialogFile();

  void flush_stream();

  void DialogFile::write(size_t k, char * str, size_t blockSize);

  char * DialogFile::read(size_t k, char * oldbuffer, size_t blockSize);

#endif
