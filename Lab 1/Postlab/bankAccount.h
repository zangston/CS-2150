//Winston Zhang, wyz5rge
//bankAccount.h
//2 Sept 2021

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount
{
 public:
  bankAccount(); //default constructor
  bankAccount(double amount);
  ~bankAccount();
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();
  
 private:
  double balance;
};

#endif
