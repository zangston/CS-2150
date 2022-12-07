#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(string s)
{
  value = s;
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
