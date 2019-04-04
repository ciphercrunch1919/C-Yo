#include "SLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename E>
SLinkedList<E>::SLinkedList()
   :head(NULL) {}
template<typename E>
bool SLinkedList<E>::empty() const
   {return head == NULL;}

template<typename E>
const E& SLinkedList<E>::front() const
   {if(empty()){
      throw std::runtime_error("SLinkedList<>::front(): empty list");
   }
   return head -> elem;}

template<typename E>
SLinkedList<E>::~SLinkedList()
   {while(!empty()) removeFront();}

template<typename E>
void SLinkedList<E>::addFront(const E& e) {
   SNode* v = new SNode;
   v -> elem = e;
   v -> next = head;
   head = v;
}

template <typename E>
void SLinkedList<E>::removeFront(){
   SNode* old = head;
   head = old -> next;
   delete old;
}

