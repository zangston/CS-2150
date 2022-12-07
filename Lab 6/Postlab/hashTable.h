//Winston Zhang, wyz5rge
//hashTable.h
//18 October 2021

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class hashTable
{
 public:
  hashTable(int x);
  void insert(string s);
  bool contains(string s);
  //int getSize();
  vector<string> prefix;

 private:
  //int size;
  int hash(string s);
  vector<string> words;
};

#endif
