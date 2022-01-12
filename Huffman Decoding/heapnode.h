// Tony Le, hnl7vwd, 11/19/2021, heapnode.h

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
#include <string>

using namespace std;

class heapnode {
 public:
  heapnode();
  heapnode(string c, int f);
  ~heapnode();

  heapnode* left;
  heapnode* right;


  string val;
  int frequency;
  string prefix;

  friend class heap;

};


#endif