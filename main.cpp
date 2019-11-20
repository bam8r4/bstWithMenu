//Author of this code: Brent Moran

#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
  int selectionNum = 0; //This is a selection number to run the switch case for the menu.
  int input = 0; //This will be used in both case 5 and 6 of switch case.
  int arr[10] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12}; //Array given to us to by instructor to populate our tree.
  binaryTree tree;

  //This will build our binary search tree.
  for(int i = 0; i < 10; i++)
  {
    tree.insertNode(arr[i]);
  }

  do{

      printMenu();
      cout<<"\nINPUT:";
      cin>>selectionNum;

      switch(selectionNum)
      {
        case 1:
          cout<<"\nPrinting tree InOrder."<<endl;
          tree.displayInOrder();
          break;

        case 2:
          cout<<"\nPrinting tree PreOrder."<<endl;
          tree.displayPreOrder();
          break;

        case 3:
          cout<<"\nPrinting tree PostOrder."<<endl;
          tree.displayPostOrder();
          break;

        case 4:
          cout<<"\nThe tree height is: ";
          //tree.treeHeight();
          tree.getMaxHeight();
          break;

        case 5:
          cout<<"\nInput the key value you would like to search for: ";
          cin >> input;
          cout<<"Ok we will search for key and show the progress!"<<endl;
          tree.searchNode(input);
          break;

        case 6:
          cout<<"\nInput the key value you would like to delete from the tree: ";
          cin >> input;
          cout <<"Ok we will delete the node with that key value!"<<endl;
          tree.remove(input);
          break;

        case 7:
          cout<<"Thank you for using our binary search tree menu! Goodbye!"<<endl;
          break;

        default:
          cout<<"Either no selection was made or an invalid selection was made."<<endl;
          break;

      }
    }while(selectionNum != 7);


  //Assignment instructions
  /*
  Must be menu driven.
  Create binary search tree with the given array.
  Display using all methods. (in,post,pre)order.
  Call searchNode for keys 38 and 9. Display update as search goes on.
  Call deleteNode on key 10.
  */


}
