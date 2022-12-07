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
  //Original input prompts, commented out due to lack of user protection
  /*
  int x, y, z;
  cin >> x;
  cin >> y;
  */
  
  double x, y, z;

  //while loop runs so that program can continually ask user for input if input isn't positive or an integer
  while(true)
    {
      if(cin >> x && (x >= 0 && x - (int)x == 0))
	break;
      else
	{
	  cout << "Please enter a positive integer value" << endl;
	  cin.clear();
	  cin.ignore(100, '\n');
	}
    }

  while(true)
    {
      if(cin >> y && (y >= 0 && y - (int)y == 0))
	break;
      else
	{
	  cout << "Please enter a positive integer value" << endl;
	  cin.clear();
	  cin.ignore(100, '\n');
	}
    }
  
  z = power(x, y);
  cout << z << endl;
  return 0;
}
