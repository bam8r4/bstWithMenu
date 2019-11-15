//Author of this code: Brent Moran

#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
  int arr[10] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12}; //Array given to us to by instructor to populate our tree.
  binaryTree tree;


  for(int i = 0; i < 10; i++)
  {
    tree.insertNode(arr[i]);
  }

  //Assignment instructions
  /*
  Must be menu driven.
  Create binary search tree with the given array.
  Display using all methods. (in,post,pre)order.
  Call searchNode for keys 38 and 9. Display update as search goes on.
  Call deleteNode on key 10.
  */


}
