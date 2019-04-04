#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename Object>
class SLinkedList {
public:
   SLinkedList();                  // empty list constructor
   bool empty() const;             // is list empty?
   const Object& front() const;    // return front element
   void addFront(const Object& e); // add to front of list
   void removeFront();             // remove front item list

   // housekeeping functions
   ~SLinkedList();                 // destructor
   SLinkedList(const SLinkedList& other);  //Copy constructor
   SLinkedList& operator=(const SLinkedList& other);   //operator=
    
private:
   struct SNode {      // node struct
       Object elem;
       SNode* next;
   };

   SNode* head;        // head of list
};

#include "SLinkedList.cpp"
#endif
