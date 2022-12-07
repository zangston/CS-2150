//Winston Zhang, wyz5rge
//ListItr.cpp
//3 Sept 2021

#include "ListItr.h"

#include <iostream>
using namespace std;

ListItr::ListItr()
{
  current = NULL;
}

ListItr::ListItr(ListNode* theNode)
{
  current = theNode;
}

bool ListItr::isPastEnd() const
{
  if((*current).next == NULL)
    return true;
  else
    return false;
}

bool ListItr::isPastBeginning() const
{
  if((*current).previous == NULL)
    return true;
  else
    return false;
}

void ListItr:: moveForward()
{
  if(isPastEnd())
    return;
  current = (*current).next;
}

void ListItr::moveBackward()
{
  if(isPastBeginning())
    return;
  current = (*current).previous;
}

int ListItr::retrieve() const
{
  return (*current).value;
}

