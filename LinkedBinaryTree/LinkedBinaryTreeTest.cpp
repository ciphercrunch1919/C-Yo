#include <iostream>
#include "LinkedBinaryTree.h"

int main()
{
/* create the following binary tree:
*                      9
*                    /   \
*                   7     11
*                  / \   /  \
*                 3   8 10  14
*                / \
*               2   5
*      */
 
   LinkedBinaryTree<int> tree;
   tree.addRoot(9);
   tree.addLeftLeaf(tree.root(),7);
   tree.addRightLeaf(tree.root(),11);
   tree.addLeftLeaf(tree.root().left(),3);
   tree.addRightLeaf(tree.root().left(),8);
   tree.addLeftLeaf(tree.root().right(),10);
   tree.addRightLeaf(tree.root().right(),14);
   tree.addLeftLeaf(tree.root().left().left(), 2);
   tree.addRightLeaf(tree.root().left().left(), 5);

   cout << "Tree: " << endl;

   cout << "Preorder: " << endl;
   tree.preorderPrint();

   cout << endl << "Inorder: " << endl;
   tree.inorderPrint();

   cout << endl << "Postorder: " << endl;
   tree.postorderPrint();

   cout << endl << "BST: ";
   if(tree.isBST())
      cout << endl << "Tree is BST" << endl;
   else
      cout << endl << "Tree is not BST" << endl;

 /* second binary tree:
 *                       9
 *                     /   \
 *                    7     11
 *                   / \   /  \
 *                  3   8 10  14
 *                 / \
 *                2  100
 *      */

   LinkedBinaryTree<int> tree2;
   tree2.addRoot(9);
   tree2.addLeftLeaf(tree2.root(),7);
   tree2.addRightLeaf(tree2.root(),11);
   tree2.addLeftLeaf(tree2.root().left(),3);
   tree2.addRightLeaf(tree2.root().left(),8);
   tree2.addLeftLeaf(tree2.root().right(),10);
   tree2.addRightLeaf(tree2.root().right(),14);
   tree2.addLeftLeaf(tree2.root().left().left(), 2);
   tree2.addRightLeaf(tree2.root().left().left(), 100);

   cout << endl << "Tree2: " << endl;
   cout << endl << "Preorder: " << endl;
   tree2.preorderPrint();

   cout << endl << "Inorder: " << endl;
   tree2.inorderPrint();

   cout << endl << "Postorder: " << endl;
   tree2.postorderPrint();

   cout << endl << "BST: ";
   if(tree2.isBST())
      cout << endl << "Tree2 is BST" << endl;
   else
      cout << endl << "Tree2 is not BST" << endl;

   return 0;
}
