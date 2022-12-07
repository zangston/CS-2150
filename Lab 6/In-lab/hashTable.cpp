//Winston Zhang, wyz5rge
//hashTable.cpp
//18 October 2021

#include "hashTable.h"
#include <math.h>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

hashTable::hashTable(int x)
{
  size = x;
  buckets = vector<list<string>>(size);
}

void hashTable::insert(string s)
{
  buckets[hash(s)].push_front(s);
}

bool hashTable::contains(string s)
{
  list<string> l = buckets.at(hash(s));
  return find(l.begin(), l.end(), s) != l.end();
}

int hashTable::hash(string s)
{
  int sum = 0;
  for(int i = 0; i < s.length(); i++)
    {
      sum += int(s[i]) * pow(37, i);
    }
  int hash = sum % buckets.size();
  return hash;
}

int hashTable::getSize()
{
  return size;
}

