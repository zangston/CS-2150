// Winston Zhang, wyz5rge
// threexinput.cpp
// 15 November 2021

#include <iostream>
#include "timer.h"

using namespace std;

// there should be a line here for the x86 subroutine
extern "C" int threexplusone(int);

int main()
{
  int x, n, steps;

  // Removed input prompts because gradescope
  
  //cout << "Enter a number: ";
  cin >> x;

  //cout << "Enter iterations of subroutine: ";
  cin >> n;

  timer t;
  t.start();
  for(int i = 0; i < n; i++)
    {
      steps = threexplusone(x);
    }
  t.stop();

  int averageTime = t.getTime() / n;

  cout << steps << endl;
  //cout << "Steps: " << steps << endl;

  // Removed because gradescope said so
  //cout << "Average time: " << averageTime * 1000 << " per iteration" << endl;
  
  return 0;
}
