#include "SLinkedList.h"
#include <iostream>
using namespace std;

int main() {
  SLinkedList<int> numlist;
  
  if (numlist.empty())
    cout << "You successfully made an empty list!" << endl;
  
  numlist.addFront(2);
  cout << numlist.front() << endl;  // print: 2

  numlist.addFront(7);
  cout << numlist.front() << endl;  // print 7
  
  numlist.removeFront();
  cout << numlist.front() << endl;  // print 2
  
  SLinkedList<char> charlist;
  
  charlist.addFront('b');
  charlist.addFront('d');
  cout << charlist.front() << endl; //print 'd'
  
  charlist.removeFront();
  cout << charlist.front() << endl; //print 'b'

  charlist.removeFront();
  cout << charlist.front() << endl; //print ??

  return 0;
}
