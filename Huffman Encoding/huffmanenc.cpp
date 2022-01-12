/*
*@author: Hoai-Nam (Tony) Le
*Created on 11/19/2021
*
*Huffman encoder that takes in a .txt file input and creates a subsequent tree based on the characters in the file.
*Prints statistics after the encoding occurs.
*Tested using normal1.txt - normal4.txt
*/ 

#include "heap.h"
#include "heapnode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>


void getCodes(heapnode* h, string code, map<string, string> &codeMap) {
	if (h == NULL)
		return;
	else if (h -> left == NULL && h -> right == NULL) {
		codeMap[h -> val] = code;
	}

	getCodes(h -> right, code + "1", codeMap);
	getCodes(h -> left, code + "0", codeMap);
}

int main(int argc, char** argv) {

	if (argc != 2) {
 		cout << "Must supply the input file name as the one and only parameter" << endl;
 		return 1;
    }

    ifstream file(argv[1]);

    char c;
    int count = 0;
    map<string, int> fmap;
    while (file.get(c)) {
    	if (c >= 20 && c <= 126) {
    		count++;
    		string temp = "";
    		temp += c;
    		fmap[temp]++;
    	}
    }

    heap h;
    for (auto item : fmap) {
    	if (item.first == " ") {
    		heapnode* hn = new heapnode("space", item.second);
    		h.insert(hn);
    	}

    	else {
    		heapnode* hn = new heapnode(item.first, item.second);
    		h.insert(hn);
    	}
    }

    while (h.size() != 1) {
    	heapnode* hn = new heapnode();
    	heapnode* min = h.deleteMin();
    	heapnode* min2 = h.deleteMin();
    	hn -> frequency = min -> frequency + min2 -> frequency;
    	hn -> left = min;
    	hn -> right = min2;
    	h.insert(hn);
    }

    map<string, string> codeMap;
    getCodes(h.findMin(), "", codeMap);

    for (auto item : codeMap) {
    	cout << item.first << "\t" << item.second << endl;
    }

    cout << "----------------------------------------" << endl;

    ifstream ifile(argv[1]);

    char g;
    int counter = 0;
    int counter2 = 0;
    while (ifile.get(g)) {
    	if (g >= 20 && g <= 126) {
    		string temp = "";

    		if (g == ' ') {
    			temp = "space";
    		}

    		else {
    			temp += g;
    		}

    		counter++;
    		counter2 += codeMap[temp].length();
    		cout << codeMap[temp] << " ";
    	}
    }

    cout << endl;

    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << counter << " symbols that are encoded." << endl;
    cout << "There are " << codeMap.size() << " distinct symbols used." << endl;
    cout << "There were " << counter * 8 << " bits in the original file." << endl;
    cout << "There were " << counter2 << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << fixed << setprecision(5) << counter*8/counter2 << "." << endl;
    cout << "The cost of the Huffman tree is " << fixed << setprecision(5) << counter2/counter;
    cout << " bits per character." << endl;

    return 0;
}