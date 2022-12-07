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
  //size = x;
  words = vector<string>(x);
}

void hashTable::insert(string s)
{
  int h = hash(s);
  int i = 0;
  while(words[h] != "")
    {
      i++;
      h = (h + i * i) % words.size();
      if(h >= words.size())
	h = 0;
    }
  words[h] = s;
}

bool hashTable::contains(string s)
{
  int h = hash(s);
  int i = 0;
  while(words[h] != "")
    {
      if(words[h] == s)
	return true;
      else
	{
	  i++;
	  h = (h + i * i) % words.size();
	  if(h >= words.size())
	    h = 0;
	}
    }
  return false;
}

int hashTable::hash(string s)
{
  int sum = 0;
  int pow = 37;
  for(int i = 0; i < s.length(); i++)
    {
      for(int j = 0; j < i; j++)
	{
	  pow = pow * 37;
	}
      sum += int(s[i]) * pow;
    }
  return sum % words.size();
}

/*
int hashTable::getSize()
{
  return size;
}
*/

