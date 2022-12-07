//Winston Zhang, wyz5rge
//xToN.cpp
//28 August 2021

#include <iostream>
using namespace std;

//Pre: Takes in two integer values, x and n
//Post: Recursively raises x to n power; Returns 1 if n is zero, returns x times power(x, n-1) otherwise
int power(int x, int n)
{
  if(n == 0)
    return 1;
  else
    return x * power(x, n-1);
}

int main()
{

  int x, y, z;

  cin >> x;
  cin >> y;
  
  z = power(x, y);
  cout << z << endl;
  return 0;
}
