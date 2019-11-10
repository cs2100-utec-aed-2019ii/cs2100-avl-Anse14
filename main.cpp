#include "./Avl.hpp"

int main()
{
  AVLTree<int> a;
  a.insert(5);
  a.insert(4);
  a.insert(3);
  a.insert(2);
  a.insert(1);
  a.root->print();
  return 0;
}
