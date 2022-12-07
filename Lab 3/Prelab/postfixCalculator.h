//Winston Zhang, wyz5rge
//postfixCalculator.h
//11 Sept 2021

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
using namespace std;

#include <stack>

class postfixCalculator
{
 public:
  postfixCalculator();

  stack<int> s;
  
  void pushInput(int x);
  int getTop();
  void add();
  void subtract();
};

#endif
