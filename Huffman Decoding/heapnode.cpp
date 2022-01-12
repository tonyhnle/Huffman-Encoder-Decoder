// Tony Le, hnl7vwd, 11/19/2021, heapnode.cpp

#include <iostream>
#include "heapnode.h"

using namespace std;

heapnode::heapnode() {
  right = NULL;
  left = NULL;
  frequency = 0;
  val = '0';
  prefix="";
}

heapnode::heapnode(string c, int f) {
  right = NULL;
  left = NULL;
  frequency = f;
  val = c;
  prefix="";
}

 heapnode::~heapnode() {
 	//destructor
 }