//Winston Zhang, wyz5rge
//bitCounter.cpp
//21 Sept 2021

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Recursive function to count number of 1 bits for a base 10 number's binary representation
int bitCount(int x)
{
  if(x == 0)
    return 0;
  else if(x == 1)
    return 1;
  else return bitCount(x / 2) + bitCount(x % 2);
}

//Pre: char* number to be converted, char* starting base of number, char* base to convert number to
//Post: string converted number
string baseConverter(char* number, char* startBase, char* endBase)
{
  //Convert C-style strings into appropriate types
  string num = string(number);
  int startingBase = stoi(string(startBase));
  int endingBase = stoi(string(endBase));
  
  //Convert string into array of chars
  char bits[num.length()];
  for(int i = 0; i < num.length(); i++)
    {
      bits[i] = num[i];
    }
  
  //Convert char values to proper base 36 digit values
  for(int i = 0; i < num.length(); i++)
    {
      if(bits[i] >= 48 && bits[i] <= 57)
	bits[i] = bits[i] - 48;
      if(bits[i] >= 65 && bits[i] <= 90)
	bits[i] = bits[i] - 55;
    }

  //Convert to base 10 int
  long int base10 = 0;
  int power = 0;
  for(int i = num.length() - 1; i >= 0; i--)
    {
      base10 += bits[i] * pow(startingBase, power);
      power++;
    }

  //Create a 16 bit int array of zeros
  int cBits[16];
  for(int i = 0; i < 16; i++)
    {
      cBits[i] = 0;
    }
  
  //Convert to end base
  int place = 0;
  while(base10 > 0)
    {
      if(base10 % endingBase == 0)
	cBits[place] = 0;
      else cBits[place] = base10 % endingBase;
      base10 = base10 / endingBase;
      place++;
    }
  
  /*
    I'm not really sure why I had to do this, but simply setting chars to 0 would cause
    my loops to not iterate over that index, so I instead made an array of ints and then
    gave them an offset of 1 so converting back to chars wouldn't cause any weird behavior
  */
  for(int i = 0; i < 16; i++)
    {
      cBits[i]++;
    }

  //Convert back to char values, with offset in mind
  char charBits[16];
  for(int i = 0; i < 16; i++)
    {
      if(cBits[i] >= 1 && cBits[i] <= 10)
       charBits[i] = cBits[i] + 47;
      if(cBits[i] >= 11 && cBits[i] <= 36)
	charBits[i] = cBits[i] + 54;
    }
  
  //Loop thru array of chars and concatenate them into a string
  string converted;
  for(int i = place - 1; i >= 0; i--)
    {
      string s(1, charBits[i]);
      converted += s;
    }

  return converted;
}

int main(int argc, char *argv[])
{
  cout << argv[1] << " has " << bitCount(stoi(string(argv[1]))) << " bit(s)" << endl;
  cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(argv[2], argv[3], argv[4]) << " (base " << argv[4] << ")" << endl;
  
  //Random stuff I used in the main method to test out certain things
  
  /*
  bitCount test

  cout << 2 << " " << bitCount(2) << endl;
  cout << 10 << " " << bitCount(10) << endl;
  cout << 7 << " " << bitCount(7) << endl;
  */

  /*
  baseConverter basic output test

  cout << baseConverter("123", 10, 10) << endl;
  cout << baseConverter("123", 10, 2) << endl;
  cout << baseConverter("123", 10, 16) << endl;
  cout << baseConverter("123", 10, 36) << endl;
  cout << baseConverter("4", 10, 2) << endl;
  cout << baseConverter("1011000111" , 2, 10) << endl;
  cout << baseConverter("DEADBEEF", 16, 2) << endl;
  cout << baseConverter("DEADBEEF", 16, 10) << endl;
  cout << baseConverter("ABCD", 16, 10) << endl;
  */

  /*
  ASCII stuff

  char a = 'a';
  cout << a << endl;
  int ia = int(a);
  cout << ia << endl;
  cout << "make sense?" << endl;
  */
}
