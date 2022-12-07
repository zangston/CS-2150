//Winston Zhang, wyz5rge
//LifeCycle.h
//31 Aug 2021

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <iostream>
using namespace std;

class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif
