template <typename Object>
LinkedBinaryTree<Object>::LinkedBinaryTree()    // constructor
   :_root(NULL), n(0) {}

template <typename Object>
int LinkedBinaryTree<Object>::size() const      // number of nodes
{
   return n;
}

template <typename Object>
bool LinkedBinaryTree<Object>::empty() const    // is tree empty?
{
   return size() == 0;
}

template <typename Object>
typename LinkedBinaryTree<Object>::Position LinkedBinaryTree<Object>::root() const      // get the root
{
   return Position(_root);
}

template <typename Object>
void LinkedBinaryTree<Object>::addRoot(const Object& value)             // add root to empty tree
{
   _root = new Node;
   _root->elem = value;
   n = 1;
}

template <typename Object>
void LinkedBinaryTree<Object>::addLeftLeaf(const Position& p, const Object& value) {
   Node* v = p.v;          // p*s node
   v->left = new Node;     // add a new left child
   v->left->elem = value;  // v is its parent
   v->left->parent = v;    // v is its parent
   n++;                    // one more node
}

template<typename Object>
void LinkedBinaryTree<Object>::addRightLeaf(const Position& p, const Object& value){
   Node* v = p.v;          // p*s node
   v->right = new Node;     // add a new right child
   v->right->elem = value;  // v is its parent
   v->right->parent = v;    // v is its parent
   n++;                    // one more node
}

template <typename Object>
void LinkedBinaryTree<Object>::preorderPrint() const{
   preorder(_root);
}

template <typename Object>
void LinkedBinaryTree<Object>::preorder(const Node* v) const{
   if (v == NULL) return;
   cout << v -> elem << endl;
   preorder(v->left);
   preorder(v->right);
}

template <typename Object>
void LinkedBinaryTree<Object>::inorderPrint() const {
   inorder(_root);
}

template <typename Object>
void LinkedBinaryTree<Object>::inorder(const Node* v) const{
   if (v == NULL) return;
   inorder(v->left);
   cout << v-> elem << endl;
   inorder(v->right);
}

template <typename Object>
void LinkedBinaryTree<Object>::postorderPrint() const {
   postorder(_root);
}

template <typename Object>
void LinkedBinaryTree<Object>::postorder(const Node* v) const {
   if (v == NULL) return;
   postorder(v -> left);
   postorder(v -> right);
   cout << v -> elem << endl;
}

template <typename Object>
void LinkedBinaryTree<Object>::expandExternal(const Position& p)        // expand expternal node
{
   Node* v = p.v;  // p's node
   v->left = new Node;     // add a new left child
   v->left->parent = v;    // v is its parent
   v->right = new Node;    // add a new right child
   v->right->parent = v;   // v is its parent
   n += 2; //two more nodes
}

template <typename Object>
typename LinkedBinaryTree<Object>::Position LinkedBinaryTree<Object>::removeAboveExternal(const Position& p)    //remove p and parent
{
   Node* w = p.v; Node* v = w->parent;     // get p's node and parent
   Node* sib = (w == v->left ? v->right :v->left);
   if(v == _root){ //child or root
      _root = sib;    // ... make sibling root
   }
   else{
         Node* gpar = v->parent;
      if(v == gpar->left)
         gpar->left = sib;       //replace parent by sib
      else
         gpar->right = sib;
      sib->par = gpar;
   }
   delete w; delete v;
   n -=2;
   return Position(sib);
}

template <typename Object>
bool LinkedBinaryTree<Object>::isBST() const{
   isBSTU(_root);
}

template <typename Object>
bool LinkedBinaryTree<Object>::isBSTU(Node* _root) const{
   isBST1(_root, INT_MIN, INT_MAX);
}

template <typename Object>
bool LinkedBinaryTree<Object>::isBST1(Node* node, int minKey, int maxKey) const{
   if(node == NULL)
      return true;
   if(node -> data < minKey || node -> data > maxKey)
      return false;
   return  isBST1(node->left, minKey, node->data) &&
      isBST1(node->right, node->data, maxKey);
}
