#ifndef AVL_H
#define AVL_H
#include "./Node.hpp"

template<typename T>
class AVLTree
{
public:
  Node<T> *root;
  AVLTree() : root(nullptr) {}
  ~AVLTree(){delete root; }
  void insert(T value)
  {
    if(!root)
    {
      root = new Node<T>(value);
      return;
    }
    Node<T>* result = root->insert(value);
    if(result)
    {
      result->check();
    }
  }
};

#endif
