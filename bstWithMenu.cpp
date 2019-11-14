//Author of this code: Brent Moran

#include <iostream>
#include "BINARYSEARCHTREE_H"

int main()
{
  bstWithMenu tree;

  cout<<"Inserting nodes."<<endl;
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(2);

  tree.displayInOrder();
  tree.displayPostOrder();



}
