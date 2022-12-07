//Winston Zhang
//mathfun.cpp
//1 November 2021

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int, int);

int main()
{
  int x, y;

  cout << "Enter integer 1: ";
  cin >> x;

  cout << "Enter integer 2: ";
  cin >> y;
  
  cout << "Product: " << product(x, y) << endl;
  cout << "Power: " << power(x, y) << endl;

  return 0;
}
