#include "ArrayStack.h"
#include <stdexcept>
using namespace std;

template <typename Object>
ArrayStack<Object>::ArrayStack(int cap)
   : S(new Object[cap]), capacity(cap), t(-1) {}

template <typename Object>
int ArrayStack<Object>::size() const {
   return t +1;
}

template <typename Object>
bool ArrayStack<Object>::empty() const {
   return t < 0;
}

template <typename Object>
const Object& ArrayStack<Object>::top() const {
   if (empty()){
      throw runtime_error("Stack is Empty");
   }
   return S[t];
}

template <typename Object>
void ArrayStack<Object>::push(const Object& e) {
   if (size() == capacity){
      throw runtime_error("Stack is Full");
   }
   S[++t] = e;
}

template <typename Object>
void ArrayStack<Object>::pop() {
   if (empty()){
      throw runtime_error("Stack is Empty");
   }
   t--;
}

template <typename Object>
ArrayStack<Object>::ArrayStack(const ArrayStack& other)
   : S(new Object[other.capacity]), capacity(other.capacity), t(other.t)
{
   for (int j=0; j <= t; j++)
      S[j] = other.S[j];
}

template <typename Object>
ArrayStack<Object>::~ArrayStack() {
   delete[] S;
}

template <typename Object>
ArrayStack<Object>& ArrayStack<Object>::operator=(const ArrayStack& other) {
   if (this != &other) {
      capacity = other.capacity;
      t = other.t;
      delete[] S;
      S = new Object[capacity];
      for (int j=0; j <= t; j++)
         S[j] = other.S[j];
   }
   return *this;
}
