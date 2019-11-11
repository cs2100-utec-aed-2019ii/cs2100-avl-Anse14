#include "./Avl.hpp"

int main()
{
  AVLTree<int> a;
  a.insert(5);
  a.insert(9);
  a.insert(6);
  a.insert(12);
  a.insert(10);
  a.insert(2);
  a.insert(3);
  a.root->print();
  return 0;
}
