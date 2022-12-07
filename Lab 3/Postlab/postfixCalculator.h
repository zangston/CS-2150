//Winston Zhang, wyz5rge
//postfixCalculator.h
//13 Sept 2021

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "List.h"

#include <iostream>
using namespace std;

class postfixCalculator
{
 public:
  postfixCalculator();

  List l;
  
  void pushInput(int x);
  int getTop();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
};

#endif
