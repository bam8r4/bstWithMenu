//Author of this code: Brent Moran

#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
  binaryTree tree;

  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(29);
  tree.insertNode(3);
  tree.insertNode(1);

  tree.displayInOrder();

  tree.remove(8);

  tree.displayInOrder();
  cout<<"****************************"<<endl;

  tree.displayPreOrder();
  cout<<"\n\n";
  tree.displayPostOrder();


}
