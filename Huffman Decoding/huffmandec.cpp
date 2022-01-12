// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "heapnode.h"
using namespace std;

string calcCode(string character, heapnode* node) {
	if (!node -> left&& !node -> right) 
		return node -> val;

	if (character[0] == '1') 
		return calcCode(character.substr(1), node -> right);	
	
	if (character.length() == 1 && character == "0") {
		return node->left->val;
	} else if (character.length() == 1 && character == "1") {
		return node->right->val;
	}
	return calcCode(character.substr(1), node -> left);
}


void huffmanTree(heapnode* n, string prefix, char c) {
 if(prefix.length()==0) {
    n->val = c;
  }
  if(prefix[0] == '0') {
    if(!n->left) {
      n->left = new heapnode();
    }
    string s = prefix.substr(1);
    huffmanTree(n->left, s, c);
  }
  else if(prefix[0] == '1') {
    if(!n->right) {
      n->right = new heapnode();
    }
    string s = prefix.substr(1);
    huffmanTree(n->right, s, c);
  }
  
}

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    heapnode* x = new heapnode();
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        huffmanTree(x,prefix,character[0]);
        // do something with the prefix code
        //out << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
        cout << calcCode(bits, x);
    }
    cout << endl;
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    return 0;
}