//Winston Zhang, wyz5rge
//postfixCalculator.cpp
//13 Sept 2021

#include "postfixCalculator.h"
#include "List.h"

#include <iostream>
using namespace std;

postfixCalculator::postfixCalculator()
{
  
}

void postfixCalculator::pushInput(int x)
{
  l.insertAtTail(x);
}

int postfixCalculator::getTop()
{
  if(l.isEmpty())
    {
      cout << "Stack empty, no top element to return" << endl;
      return 0;
    }
  return l.last().retrieve();
}


void postfixCalculator::add()
{
  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = l.last().retrieve();
  l.removeLast();

  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = l.last().retrieve();
  l.removeLast();

  int sum = x1 + x2;
  l.insertAtTail(sum);
}

void postfixCalculator::subtract()
{
  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = l.last().retrieve();
  l.removeLast();

  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = l.last().retrieve();
  l.removeLast();

  int diff = x2 - x1;
  l.insertAtTail(diff);
}

void postfixCalculator::multiply()
{
  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = l.last().retrieve();
  l.removeLast();

  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = l.last().retrieve();
  l.removeLast();

  int product = x1 * x2;
  l.insertAtTail(product);
}

void postfixCalculator::divide()
{
  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = l.last().retrieve();
  l.removeLast();

  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = l.last().retrieve();
  l.removeLast();

  int quotient = x2 / x1;
  l.insertAtTail(quotient);
}

void postfixCalculator::negate()
{
  if(l.isEmpty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = l.last().retrieve();
  l.removeLast();

  int neg = x1 * -1;
  l.insertAtTail(neg);
}
