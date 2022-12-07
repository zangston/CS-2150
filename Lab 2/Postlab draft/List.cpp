//Winston Zhang, wyz5rge
//List.cpp
//3 Sept 2021

#include "List.h"

#include <iostream>
using namespace std;

List::List()
{
  head = new ListNode;
  tail = new ListNode;
  count = 0;
  (*head).next = tail;
  (*head).previous = NULL;
  (*tail).previous = head;
  (*tail).next = NULL;
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
  makeEmpty();
  delete head;
  delete tail;
}

bool List::isEmpty() const
{
  if(count == 0)
    return true;
  else
    return false;
}

void List::makeEmpty()
{
  while(!isEmpty())
    {
      remove((*(*head).next).value);
    }
}

ListItr List::first()
{
  return ListItr((*head).next);
}

ListItr List::last()
{
  return ListItr((*tail).previous);
}

void List::insertAfter(int x, ListItr position)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).previous = position.current;
  (*l).next = (*position.current).next;
  (*(*position.current).next).previous = l;
  (*position.current).next = l;
  count++;
}

void List::insertBefore(int x, ListItr position)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).previous = (*position.current).previous;
  (*l).next = position.current;
  (*(*position.current).previous).next = l;
  (*position.current).previous = l;
  count++;
}

void List::insertAtTail(int x)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).next = tail;
  (*l).previous =(*tail).previous;
  (*(*tail).previous).next = l;
  (*tail).previous = l;
  count++;
}

ListItr List::find(int x)
{
  ListItr l((*head).next);
  while(!l.isPastEnd())
    {
      if((*l.current).value == x)
	return l;
      l.moveForward();
    }
  return l;
}

void List::remove(int x)
{
  ListItr l = find(x);
  if(l.current == tail)
    return;
  else
    {
      (*(*l.current).previous).next = (*l.current).next;
      (*(*l.current).next).previous = (*l.current).previous;
      delete l.current;
      count--;
    }
}

int List::size() const
{
  return count;
}

void printList(List& source, bool forward)
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
	  cout << l.retrieve() << endl;
	  l.moveBackward();
	}
    }
}
