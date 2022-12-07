// Winston Zhang, wyz5rge
// tree.h
// 22 November 2021

// the prelab mentioned a secondary data structure and i'm very lost so i hope to god this is the way

#ifndef TREE_H
#define TREE_H

#include "huffmanNode.h"
#include "heap.h"

using namespace std;

class tree
{
 public:
  tree();
  ~tree();

  huffmanNode* root;
  
  heap hTree(heap h);
  huffmanNode* mergeNodes(huffmanNode* x, huffmanNode *y);
  void setNodePrefix(huffmanNode* x, string s);
  void printPrefix(huffmanNode* x, string s);
};
#endif
