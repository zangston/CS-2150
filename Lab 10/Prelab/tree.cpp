// Winston Zhang, wyz5rge
// tree.cpp
// 22 November 2021

// i will be very upset if i coded this for nothing

#include <iostream>
#include "huffmanNode.h"
#include "tree.h"

using namespace std;

tree::tree(){
  root=NULL;
}

tree::~tree(){
  delete root;
}

heap tree::hTree(heap h)
{
  while(h.size() >= 2)
    {
      huffmanNode* x = h.findMin();
      h.deleteMin();
      huffmanNode* y = h.findMin();
      h.deleteMin();
  
      huffmanNode* merged = mergeNodes(x, y);
      h.insert(merged);
    }
  return h;
}

huffmanNode* tree::mergeNodes(huffmanNode* x, huffmanNode* y)
{
  int xFrequency = x->frequency;
  int yFrequency = y->frequency;
  
  huffmanNode* m = new huffmanNode(xFrequency + yFrequency, '0');
  m->left = x;
  m->right = y;
  return m;
}

void tree::setNodePrefix(huffmanNode *x, string s)
{
  if (x->left == NULL && x->right == NULL)
    {
    x->prefix = s;
    }
  if (x->left)
    {
    setNodePrefix(x->left, s + "0");
    }
  if (x->right)
    {
    setNodePrefix(x->right, s + "1");
    }
}
    
void tree::printPrefix(huffmanNode *x, string s)
{
  if (x->ch == ' ')
    cout << "space" << " " << s << endl;
  if (x->left == NULL && x->right == NULL)
    {
    cout << x->ch << "  " << s << endl;
    }
  if (x->left)
    {
    printPrefix(x->left, s + "0");
    }
  if (x->right)
    {
    printPrefix(x->right, s + "1");
    }
}

