//Winston Zhang, wyz5rge
//List.cpp
//6 Sept 2021

#include "List.h"

#include <iostream>
using namespace std;

List::List()
{
  head = new ListNode;
  head->previous = NULL;

  tail = new ListNode;
  tail->next = NULL;

  head->next = tail;
  tail->previous = head;
  
  count = 0;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List()
{

}

bool List::isEmpty() const
{
  return false;
}

void List::makeEmpty()
{

}

ListItr List::first()
{
  ListItr first(head->next);
  return first;
}

ListItr List::last()
{
  ListItr last(tail->previous);
  return last;
}

void List::insertAfter(int x, ListItr position)
{

}

void List::insertBefore(int x, ListItr position)
{

}

void List::insertAtTail(int x)
{
  ListNode *l = new ListNode;
  l->value = x;
  l->next = tail;
  l->previous = tail->previous;
  tail->previous->next = l;
  tail->previous = l;
  count++;
}

ListItr List::find(int x)
{
  ListItr find;
  return find;
}

void List::remove(int x)
{

}

int List::size() const
{
  return count;
}

void printList(List &source, bool forward)
{
  if(forward == true)
    {
      ListItr l(source.first());
      while(!l.isPastEnd())
	{
	  cout << l.retrieve() << endl;
	  l.moveForward();
	}
    }
  else
    {
      ListItr l(source.last());
      while(!l.isPastBeginning())
	{
	  cout<< l.retrieve() << endl;
	  l.moveBackward();
	}
    }
}
