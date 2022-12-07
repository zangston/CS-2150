// Winston Zhang, wy5rge
// heap.cpp
// Code adapted from binary_heap.cpp, written by Aaron Bloomfield, 2014
// 22 November 2021

#include <iostream>
#include <vector>
#include "huffmanNode.h"
#include "heap.h"

using namespace std;

// default constructor
heap::heap()
{
  heap_size = 0;
  h.push_back(0);
}

// builds heap from vector
heap::heap(vector<huffmanNode*> v)
{
  heap_size = v.size();
  h = v;
  h.push_back(h[0]);
  h[0] = NULL;

  for(int i = (heap_size / 2); i > 0; i--)
    {
      percolateDown(i);
    }
}

// supposedly the destructor doesn't need to do much
heap::~heap()
{
  // lol nice
}

// gee, i wonder what the insert method does??
void heap::insert(huffmanNode* x)
{
  h.push_back(x);
  percolateUp(++heap_size);
}

void heap::percolateUp(int hole)
{
  huffmanNode* x = h[hole];
  for( ; (hole > 1) && (x < h[hole / 2]); hole /= 2)
    {
      h[hole] = h[hole / 2];
    }
  h[hole] = x;
}

huffmanNode* heap::deleteMin()
{
  if(heap_size == 0)
    throw "deleteMin() called on empty heap";

  huffmanNode* ret = h[1];
  h[1] = h[heap_size--];
  h.pop_back();

  if(!isEmpty())
    percolateDown(1);

  return ret;
}

void heap::percolateDown(int hole)
{
  huffmanNode* x = h[hole];
  while(hole * 2 <= heap_size)
    {
      int child = hole * 2;
      if((child + 1 <= heap_size) && (h[child + 1]-> frequency < h[child]-> frequency))
	{
	  child++;
	}
      if(x > h[child])
	{
	  h[hole] = h[child];
	  hole = child;
	}
      else
	break;
    }
  h[hole] = x;
}

huffmanNode* heap::findMin()
{
  if(heap_size == 0)
    throw "findMin() called on empty heap";
  else
    return h[1];
}

unsigned int heap::size()
{
  return heap_size;
}

void heap::makeEmpty()
{
  heap_size = 0;
  h.resize(1);
}

bool heap::isEmpty()
{
  if(heap_size == 0)
    return true;
  else
    return false;
}

void heap::print() {
    cout << "(" << h[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << h[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
