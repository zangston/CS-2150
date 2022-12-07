//Winston Zhang, wyz5rge
//postfixCalculator.cpp
//13 Sept 2021

#include "postfixCalculator.h"
#include <stack>

#include <iostream>
using namespace std;

postfixCalculator::postfixCalculator()
{
  
}

void postfixCalculator::pushInput(int x)
{
  s.push(x);
}

int postfixCalculator::getTop()
{
  if(s.empty())
    {
      cout << "Stack empty, no top element to return" << endl;
      return 0;
    }
  return s.top();
}

void postfixCalculator::add()
{
  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = s.top();
  s.pop();

  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = s.top();
  s.pop();

  int sum = x1 + x2;
  s.push(sum);
}

void postfixCalculator::subtract()
{
  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = s.top();
  s.pop();

  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = s.top();
  s.pop();

  int diff = x2 - x1;
  s.push(diff);
}

void postfixCalculator::multiply()
{
  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = s.top();
  s.pop();

  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = s.top();
  s.pop();

  int product = x1 * x2;
  s.push(product);
}

void postfixCalculator::divide()
{
  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = s.top();
  s.pop();

  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x2 = s.top();
  s.pop();

  int quotient = x2 / x1;
  s.push(quotient);
}

void postfixCalculator::negate()
{
  if(s.empty())
    {
      cout << "Not enough stack elements to perform operation" << endl;
      return;
    }
  int x1 = s.top();
  s.pop();

  int neg = x1 * -1;
  s.push(neg);
}
