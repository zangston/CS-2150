//Winston Zhang, wyz5rge
//TestPostfixCalc.cpp
//11 Sept 2021

#include "postfixCalculator.h"

#include <iostream>
using namespace std;

int main()
{
  postfixCalculator calc;

  string token;
  while(cin >> token)
    {
      if(token == "+")
	calc.add();
      else if(token == "-")
	calc.subtract();
      else
	calc.pushInput(stoi(token));
    }
  
  cout << calc.getTop() << endl;
  
  return 0;
}
