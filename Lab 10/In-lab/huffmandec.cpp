// Winston Zhang, wyz5rge
// huffmandec.cpp
// Code adapted from inlab-skeleton.cpp, written by Aaron Bloomfield
// 23 November 2021

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "huffmanNode.h"

using namespace std;

void buildTree(huffmanNode* n, string s, char c);
//void traverseTree(huffmanNode* n, string s, char c);

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

    // read in the first section of the file: the prefix codes
    char aValues[256];
    huffmanNode* n = new huffmanNode(0, '0');
    
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;	

	/*
	if(character[0] == '\n' || character[0] == '\r')
	  {
	    continue;
	  }
	*/	

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
	  break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // ~~read in the prefix code~~
	// build tree using prefix code
	prefix = (string)aValues;
        file >> prefix;
	buildTree(n, prefix, character[0]);
	
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    /*
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
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
    */

    // read in encoded message
    char g;
    huffmanNode* traverseNode = n;

    while((g = file.get()) && g != '-')  // end while loop when reached separator
      {
	if(g == '0' && traverseNode->left != NULL)
	  traverseNode = traverseNode->left;
	else if(g == '1' && traverseNode->right != NULL)
	  traverseNode = traverseNode->right;
	if(traverseNode->left == NULL && traverseNode->right == NULL)
	  {
	    cout << traverseNode->ch;
	    traverseNode = n;
	  }
      }
    cout << endl;
    // close the file before exiting
    file.close();

    return 0;
}

// recursive method to build Huffman tree from input file
void buildTree(huffmanNode* n, string prefix, char c)
{
  if(prefix.length() == 0)
    n->ch = c;
  
  if(prefix[0] == '0')
    {
      if(n->left == NULL)
	n->left = new huffmanNode(0, '0');
      buildTree(n->left, prefix.substr(1, prefix.length() - 1), c);
    }
  else if(prefix[0] == '1')
    {
      if(n->right == NULL)
	n->right = new huffmanNode(0, '0');
      buildTree(n->right, prefix.substr(1, prefix.length() - 1), c);
    }
}

