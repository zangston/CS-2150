// Winston Zhang, wyz5rge
// heap.h
// Code adapted from binary_heap.h, written by Aaron Bloomfield, 2014
// 22 November 2021

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffmanNode.h"

using namespace std;

class heap
{
 public:
  heap();
  heap(vector<huffmanNode*> v);
  ~heap();

  void insert(huffmanNode* x);
  huffmanNode* findMin();
  huffmanNode* deleteMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  vector<huffmanNode*> h;
  unsigned int heap_size;

  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
