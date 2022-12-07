//Winston Zhang, wyz5rge
//TestPostfixCalc.cpp
//13 Sept 2021

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
      else if(token == "*")
	calc.multiply();
      else if(token == "/")
	calc.divide();
      else if(token == "~")
	calc.negate();
      else
	calc.pushInput(stoi(token));
    }
  
  cout << calc.getTop() << endl;
  
  return 0;
}
