// Winston Zhang, wyz5rge
// node.cpp
// 22 November 2021

#include "huffmanNode.h"
#include <string>

using namespace std;

huffmanNode::huffmanNode()
{
  frequency = 0;
  ch = 0;
  prefix = "";
  left = NULL;
  right = NULL;
}

huffmanNode::huffmanNode(int f, char c)
{
  frequency = f;
  ch = c;
  prefix = "";
  left = NULL;
  right = NULL;
}

// hmm...
huffmanNode::~huffmanNode()
{

}
