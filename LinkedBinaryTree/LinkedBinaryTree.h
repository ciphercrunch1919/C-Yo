#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include <iostream>
#include <climits>

using namespace std;

template <typename Object>
class LinkedBinaryTree {

protected:
   // Node declaration
   struct Node { // a node of the tree
      Object elem; // element value
      Node* parent; // parent
      Node* left; // left child:
      Node* right; // right child
      Node() : elem(), parent(NULL), left(NULL), right(NULL) {} // constructor
      Node(Object& e) : elem(e), parent(NULL), left(NULL), right(NULL) {}
      int data;
   };
public:                                                                        
   // Position declaration   
   class Position { // position in the tree
   private:
      Node* v; // pointer to the Node
   public:
      Position(Node* _v = NULL) : v(_v){} // constructor
      Object& operator*() { return v-> elem; } // get element
      Position left() const { return Position(v->left); } // get left child
      Position right() const { return Position(v->right); } // get right child
      Position parent() const { return Position(v->parent); } // get parent
      bool isRoot() const { return v->parent == NULL; } // root of the tree?
      bool isExternal() const { return v->left == NULL && v->right == NULL; } // on exteral Node?
      bool isNULL() { return (v == NULL);} // check if position is NULL
      friend class LinkedBinaryTree; // give tree access
   };

public:
   LinkedBinaryTree();// constructor
   int size() const; // number of Nodes
   bool empty() const; // is tree empty?
   Position root() const; // get the root
   void addRoot(const Object& value=Object()); // add root to empty tree
   void addLeftLeaf(const Position& p, const Object& value); // add left leaf to the tree
   void addRightLeaf(const Position& p, const Object& value); // add right leaf to the tree
   void preorderPrint() const; // print nodes in preorder
   void inorderPrint() const; // print nodes in inorder
   void postorderPrint() const; // print nodes in postorder
   void expandExternal(const Position& p); // expand external Node
   Position removeAboveExternal(const Position& p); // remove p and parent
   bool isBST() const; // return if is a BST or not

   // housekeeping functions omitted...
protected: // local utilities


private:
   void preorder(const Node* v) const;     // preorder utility
   void inorder(const Node* v) const;      // inorder utility
   void postorder(const Node* v) const;    // postorder utility
   Node* _root;                            // pointer to the root
   int n;                                  // number of Node
   bool isBSTU(Node* root) const;
   bool isBST1(Node* node, int minKey, int maxKey) const;
   Node* newNode(int key){
      Node* node = new Node;
      node ->data = key;
      node ->left = node -> right = nullptr;
      return node;
   }
};

#include "LinkedBinaryTree.cpp"
#endif
