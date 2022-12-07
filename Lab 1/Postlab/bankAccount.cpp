//Winston Zhang, wyz5rge
//bankAccount.cpp
//2 Sept 2021

#include "bankAccount.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount() : balance(0.00) {}
bankAccount::bankAccount(double amount) : balance(amount) {}

bankAccount::~bankAccount() {}

double bankAccount::withdraw(double amount)
{
  if(amount > balance)
    return balance;
  else
    {
      balance = balance - amount;
      return balance;
    }
}

double bankAccount::deposit(double amount)
{
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance()
{
  return balance;
}
