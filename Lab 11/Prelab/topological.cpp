// Winston Zhang, wyz5rge
// topological.cpp
// code adapted from fileio.cpp, written by Aaron Bloomfield
// 30 November 2021

/**
 * @author Winston Zhang
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Node
{
public:
  string name;
  int indegree = 0;
  vector<Node*> adjacent;
};

int main(int argc, char** argv)
{
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  vector<Node*> nodes;   // order of nodes
  deque<string> strings;
  
  while(!file.eof())
    {
      // read in two strings
      string s1, s2;
      file >> s1;
      file >> s2;

      if(s1 == "0" && s2 == "0")
	break;

      int in1 = 0;
      int in2 = 0;
      int x = -1;

      for(Node* n: nodes)
	{
	  x++;   // count nodes

	  if(n->name == s1)
	    in1 = x;
	  if(n->name == s1)
	    in2 = x;
	}

      Node* n1 = new Node();
      n1->name = s1;

      if(!(find(nodes.begin(), nodes.end(), n1) != nodes.end()))
	{
	  nodes.push_back(n1);
	  in1 = nodes.size() - 1;
	}

      Node* n2 = new Node();
      n2->name = s2;

      if(!(find(nodes.begin(), nodes.end(), n2) != nodes.end()))
	{
	  nodes.push_back(n2);
	  in2 = nodes.size() - 1;
	}

      Node* n3 = nodes.at(in2);
      n3->indegree = 1;
      nodes[in1]->adjacent.push_back(n3);
    }

  for(int i = 0; i < nodes.size(); i++)
    {
      if(nodes.at(i)->indegree == 0)
	strings.push_front(nodes.at(i)->name);
    }

  Node* n1 = new Node();
  
  while(!strings.empty())
    {
      sort(strings.begin(), strings.end());
      for(int i = 0; i < nodes.size(); i++)
	{
	  if(nodes.at(i)->name == strings.front())
	    n1->name = strings.front();
	}

      strings.pop_front();
      
      string s;
      if(s.find(n1->name) == string::npos)
	{
	  cout << n1->name << " ";
	  s = s + n1->name;
	}

      for(int j = 0; j < n1->adjacent.size(); j++)
	{
	  if(n1->adjacent.at(j)->indegree-- == 0)
	    strings.push_front(n1->adjacent.at(j)->name);
	}
    }

  cout << endl;
  file.close();
  
  return 0;
}
