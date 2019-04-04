#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

template <typename Object>

class ArrayStack
{
   private:
      enum { DEF_CAPACITY = 10 }; // default stack capacity
      Object* S; // array of stack elements
      int capacity; // stack capacity
      int t; // index of top of the stack

   public:
      ArrayStack(int cap=DEF_CAPACITY); // constructor from capacity
      int size() const; // number of items in stack
      bool empty() const; // is the stack empty?
      const Object& top() const; // get the top element
      void push(const Object& e); // push element onto stack
      void pop(); // pop the stack

       // Housekeeping functions
       ArrayStack(const ArrayStack& other); // copy constructor
       ArrayStack& operator=(const ArrayStack& other); // assignment operator
       ~ArrayStack(); // destructor
};
#include "ArrayStack.tcc"
#endif
