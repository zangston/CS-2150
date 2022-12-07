// Winston Zhang, wyz5rge
// node.h
// 22 November 2021

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

using namespace std;

class huffmanNode
{
 public:
  huffmanNode();
  huffmanNode(int f, char c);

  // not too sure if i need this, but it can't hurt??
  ~huffmanNode();

  huffmanNode* left;
  huffmanNode* right;
  
  int frequency;
  char ch;
  string prefix;
  
};

#endif
