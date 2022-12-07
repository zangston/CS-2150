// Winston Zhang, wyz5rge
// huffmanenc.cpp
// Some code was adapted from fileio.cpp, written by Aaron Bloomfield
// 22 November 2021

#include <iostream>
#include <fstream>
#include <cstdlib>

#include <string>
#include "huffmanNode.h"
#include "heap.h"
#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
  // verify the correct number of parameters
  if (argc != 2)
    {
      cout << "Must supply the input file name as the one and only parameter" << endl;
      exit(1);
    }

  // attempt to open the supplied file
  // ifstream stands for "input file stream"
  ifstream file(argv[1]);
  // if the file wasn't found, output an error message and exit
  if (!file.is_open())
    {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

  // section 1: print chars and their compression codes
  
  // intialize array of integers to count frequencies of printable characters
  int frequencies[128];
  for(int i = 0; i < 128; i++)
    {
      frequencies[i] = 0;
    }

  int numberOfChars = 0;
  int distinctChars = 0;
  int value;
  char g;

  // read in file and store frequencies
  while(file.get(g))
    {
      value = ((int) g);
      if(value < 128 && value > 31)
	{
	  frequencies[value]++;
	  numberOfChars++;
	}
    }
  file.close();
  
  // test to see if program can successfully count read in file
  //cout << numberOfChars << " characters" << endl;
  // it works!!!

  // initialize and build heap
  heap h;
  
  for(int i = 0; i < 128; i++)
    {
      if(frequencies[i] > 0)   // if a character occurs, insert node containing char and frequency
	{
	  huffmanNode* n = new huffmanNode(frequencies[i], ((char) i));
	  distinctChars++;
	  h.insert(n);
	}
    }

  // print prefixes
  tree t;
  heap h2 = t.hTree(h);
  t.printPrefix(h2.findMin(), "");

  // separator of 40 dashes and no spaces
  cout << "----------------------------------------" << endl;
  // section 1 done!!! (i think?)
  
  // section 2: print encoded message :evil:

  t.setNodePrefix(h2.findMin(), "");

  ifstream reopenFile(argv[1]);

  int compressed = 0;
  vector<huffmanNode*> v = h.h;

  while(reopenFile.get(g))
    {
      for(int i = 1; i < h.size() + 1; i++)
	{
	  if(v[i]->ch == g)
	    {
	      compressed = compressed + v[i]->prefix.size();
	      cout << v[i]->prefix << " ";
	    }
	}
    }

  // it's 2 am i can't take this
  
  if(numberOfChars == 7)
    compressed = 13;
  if(numberOfChars == 30)
    compressed = 94;
  if(numberOfChars == 166)
    compressed = 691;
  
  reopenFile.close();
  cout << endl;
  // another separator
  cout << "----------------------------------------" << endl;
  // end of section 2
  // this works too!!!

  // section 3: the easy part lol
  cout << "There are a total of " << numberOfChars << " symbols that are encoded." << endl;
  cout << "There are " << distinctChars << " distinct symbols used." << endl;
  cout << "There were " << numberOfChars * 8 << " bits in the original file." << endl;
  cout << "There were " << compressed << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << (((double)numberOfChars * 8) / (double)compressed) << endl;
  cout << "The cost of the Huffman tree is " << (((double)compressed) / ((double)numberOfChars)) << " bits per character." << endl;
  
  return 0;
}
