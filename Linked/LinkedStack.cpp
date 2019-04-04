#include "LinkedStack.h"
#include <stdexcept>
using namespace std;

template <typename E>
LinkedStack<E>::LinkedStack()
   :S(), n(0){}

template <typename E>
int LinkedStack<E>::size() const
   {return n;}

template <typename E>
bool LinkedStack<E>::empty() const
   {return n == 0;}

template <typename E>
const E& LinkedStack<E>::top() const
   {if(empty())
      throw std::out_of_range("Stack<>::pop(): empty stack");
   return S.front();}

template <typename E>
void LinkedStack<E>::push(const E& e)
   {++n;
   S.addFront(e);}

template <typename E>
void LinkedStack<E>::pop()
   {if(empty())
      throw std::out_of_range("Stack<>::pop(): empty stack");
   --n;
   S.removeFront();}
