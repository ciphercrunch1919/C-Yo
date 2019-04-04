#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "SLinkedList.h"

template <typename Object>
class LinkedStack {

public:
   LinkedStack();                  // empty list constructor
   int size() const;               // number of items in stack
   bool empty() const;             // is the stack empty?
   const Object& top() const;      // get the top element
   void push(const Object& e);     // push element onto stack
   void pop();                     // pop the stack

private:
   SLinkedList<Object> S;          // linked list of elements
   int n;                          // number of elements   
};

#include "LinkedStack.cpp"
#endif
