#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
void swapp(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template<typename T>
struct Node
{
  T value;
  int weight;
  int depth;
  Node<T> *left, *right;
  Node<T> *parent;
  Node(T _value) : value(_value), weight(0), depth(1), left(nullptr), right(nullptr), parent(nullptr){}
  ~Node()
  {
    if(left){delete left;}
    if(right){delete right;}
  }
  void update()
  {
    int a = (left)? left->depth : 0;
    int b = (right)? right->depth : 0;
    weight = a - b;
    depth = (a>b)? a+1 : b+1;
    //cout << "Valor: " << value << "\tProfundidad: " << depth << "\tPeso: " << weight << endl;
  }
  void check()
  {
    if(!(parent)){return;}
    if(!(parent->parent)){return;}
    if(!(parent->parent->weight < 2 && parent->parent->weight > -2))
    {
      balance();
    }
    if(parent){parent->check();}
  }
  void balance()
  {
    if(!parent){return;}
    Node<T>* p = parent->parent;
    if(!p){return;}
    if(p->right == parent)
    {
      if(p->right->right == this)
      {
        rrcase();
      }
      else
      {
        rlcase();
      }
    }
    else
    {
      if(p->left->left == this)
      {
        llcase();
      }
      else
      {
        lrcase();
      }
    }
  }
  void llcase()
  {
    Node<T>* p = parent->parent;
    Node<T> *pointers[4] = {p->right, parent->right, right, left};
    swapp(p->value, parent->value);

    p->left = nullptr;
    p->right = parent;
    p->left = this;
    p->left->parent = p;
    p->right->parent = p;

    p->right->right = pointers[0];
    if(p->right->right){p->right->right->parent = p->right;}
    p->right->left = pointers[1];
    if(p->right->left){p->right->left->parent = p->right;}

    p->left->right = pointers[2];
    if(p->left->right){p->left->right->parent = p->left;}
    p->left->left = pointers[3];
    if(p->left->left){p->left->left->parent = p->left;}
  }
  void rrcase()
  {
    Node<T>* p = parent->parent;
    Node<T> *pointers[4] = {p->left, parent->left, left, right};
    swapp(p->value, parent->value);
    
    p->right = nullptr;
    p->left = parent;
    p->right = this;
    p->left->parent = p;
    p->right->parent = p;

    p->left->left = pointers[0];
    if(p->left->left){p->left->left->parent = p->left;}
    p->left->right = pointers[1];
    if(p->left->right){p->left->right->parent = p->left;}

    p->right->left = pointers[2];
    if(p->right->left){p->right->left->parent = p->right;}
    p->right->right = pointers[3];
    if(p->right->right){p->right->right->parent = p->right;}
  }
  void lrcase()
  {
    Node<T>* p = parent->parent;
    Node<T> *pointers[3] = {parent->left, left, right};
    swapp(parent->value, value);
    
    parent->right = nullptr;
    parent->left = this;
    
    left = pointers[0];
    if(left){left->parent = this;}
    right = pointers[1];
    if(right){right->parent = this;}
    parent->right = pointers[2];
    if(parent->right){parent->right->parent = parent;}
    llcase();
  }
  void rlcase()
  {
    Node<T>* p = parent->parent;
    Node<T> *pointers[3] = {parent->right, right, left};
    swapp(parent->value, value);

    parent->left = nullptr;
    parent->right = this;

    right = pointers[0];
    if(right){right->parent = this;}
    left = pointers[1];
    if(left){left->parent = this;}
    parent->left = pointers[2];
    if(parent->left){parent->left->parent = parent;}
    rrcase();
  }
  void print()
  {
    cout << value << " ";
    if(left){ left->print();}
    if(right){ right->print();}
  }
  Node<T>* insert(T value);
};

template<typename T>
Node<T>* Node<T>::insert(T _value)
{
  if(_value == value)
  {
    return nullptr;
  }
  Node<T>* result = nullptr;
  if(_value > value)
  {
    if(right)
    {
      result = right->insert(_value);
      update();
      return result;
    }
    right = new Node<T>(_value);
    right->parent = this;
    update();
    return right;
  }
  if(left)
  {
    result = left->insert(_value);
    update();
    return result;
  }
  left = new Node<T>(_value);
  left->parent = this;
  update();
  return left;
}

#endif

