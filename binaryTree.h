//Author of this code: Brent Moran

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <algorithm>    //This is to allow use of max command in treeHeight method.
using namespace std;

//Inserts a new node into the tree with the value in the TreeNode pointer.
//That value is then inserted into the tree.

class binaryTree
{
private:
  struct TreeNode
  {
      int height;        //Level in which the node is located.
      int value;         //Value in the node
      TreeNode *left;    //Pointer to left child
      TreeNode *right;   //Pointer to right child
  };

  TreeNode *root;   //Pointer to root node
  int maxHeight = 0;  //We are assuming the tree has nodes. This value will be reset when the height function and delete functions are called.
  int *maxHeightPtr = &maxHeight;

  //Private member functions
  void insert(TreeNode *&, TreeNode *&, int);
  void destroySubTree(TreeNode *);
  void deleteNode(int value, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;
  void treeHeight(TreeNode *, int *);
  void heightSetter(TreeNode *, int);
  void heightSetterDriver(int);



public:
  //Constructor
  binaryTree()
  {root = nullptr;}

  //Destructor
  ~binaryTree()
  {destroySubTree(root);}

  //Binary tree operations
  void insertNode(int value, int level);
  void searchNode(int value);
  void remove(int value);
  void getMaxHeight();  //This just returns the value of max height so it can be printed.


  void displayInOrder() const
  {
    displayInOrder(root);
  }

  void displayPreOrder() const
  {
    displayPreOrder(root);
  }

  void displayPostOrder() const
  {
    displayPostOrder(root);
  }

  int treeHeight()
  {
    treeHeight(root, maxHeightPtr);
  }

};
void binaryTree::insert(TreeNode *&nodePtr,  TreeNode *&newNode, int level)
{
    if(nodePtr == nullptr)
    {
      nodePtr = newNode;    //Insert the node.
      nodePtr->height = level;
    }
    else if(newNode->value < nodePtr->value)
    {
      level = level + 1;
      insert(nodePtr->left, newNode, level);   //Search the left branch.
    }
    else
    {
      level = level + 1;
      insert(nodePtr->right, newNode, level);    //Search the right branch.
    }
}

//Creates new node and stores a num in it. It then passes that value to insert function.
void binaryTree::insertNode(int num, int level = 1)
{
    TreeNode *newNode = nullptr;    //Pointer to a new node.


    //Creation of a new node with num stored in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode, level);   //Insert new node.
}

//Called by the destructor to delete all nodes in the tree.
void binaryTree::destroySubTree(TreeNode *nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->left)
        {
          destroySubTree(nodePtr->left);
        }

        if(nodePtr->right)
        {
          destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }
}

//Checks to see if the a value is in the the tree. If it is it will return true.
void binaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;
    bool valueInTree = false;

    while(nodePtr)
    {
        if(nodePtr->value == num)
        {
          valueInTree = true;
          break;
        }
        else if(num < nodePtr->value)
        {
          cout<<"We are looking for the value "<<num<<" which is less than current node's value ";
          cout<<nodePtr->value<<" so we check the left child."<<endl;
          nodePtr = nodePtr->left;
        }
        else
        {
          cout<<"We are looking for the value "<<num<<" which is greater than the current node's value ";
          cout<<nodePtr->value<<" so we check the right child."<<endl;
          nodePtr = nodePtr->right;
        }

    }

    if(valueInTree == true)
    {
      cout<<"We have found the value "<<nodePtr->value<<" in the tree."<<endl;
    }
    else
    {
      cout<<"We have checked the entire tree and "<<num<<" is not in it."<<endl;
    }
}

//Calls deleteNode to delete the node with the value passes into deleteNode.
void binaryTree::remove(int num)
{
    this->maxHeight = 0; //If we delete a node we need to reset max height to zero for the next call of the treeHeight function.
    deleteNode(num, root);
}

//Deletes the node with value member same as num.
void binaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if(num < nodePtr->value)
    {
      deleteNode(num, nodePtr->left);
    }
    else if(num > nodePtr->value)
    {
      deleteNode(num, nodePtr->right);
    }
    else
    {
      makeDeletion(nodePtr);
    }
}

void binaryTree::makeDeletion(TreeNode *&nodePtr)
{
    //Temp pointer to use in reattaching left subtree.
    TreeNode *tempNodePtr = nullptr;

    if(nodePtr == nullptr)
    {
      cout<<"Error: Can't delete an empty node."<<endl;
    }
    else if(nodePtr->right == nullptr)
    {
      tempNodePtr = nodePtr;
      nodePtr  = nodePtr->left;  //Reattaching the left child.
      delete tempNodePtr;
    }
    else if(nodePtr->left == nullptr)
    {
      tempNodePtr = nodePtr;
      nodePtr  = nodePtr->right;  //Reattaching right child.
      delete tempNodePtr;
    }
    else   //If the node has more than one child.
    {
      tempNodePtr = nodePtr->right;  //Move one node to the right.

      while(tempNodePtr->left)  //Go to the end left node.
      {
        tempNodePtr = tempNodePtr->left;
      }
      tempNodePtr->left = nodePtr->left;  //Reattach left subtree.
      tempNodePtr = nodePtr;

      nodePtr = nodePtr->right;  //Reattach right subtree.
      delete tempNodePtr;

    }
}

//Display in order travel.
void binaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
      cout<< nodePtr->value <<endl;
      displayInOrder(nodePtr->left);
      displayInOrder(nodePtr->right);
    }
}

//Display preorder travel.
void binaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
    }
}

//Display postorder travel.
void binaryTree::displayPostOrder(TreeNode *nodePtr) const
{

    if(nodePtr)
    {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
    }

}

void binaryTree::heightSetterDriver(int setterValue = 1)
{
  heightSetter(root, setterValue);
}
void binaryTree::heightSetter(TreeNode *nodePtr, int setterValue)
{
  if(nodePtr)
  {
    nodePtr->height = setterValue;
    setterValue += 1;
    heightSetter(nodePtr->left,setterValue);
    heightSetter(nodePtr->right,setterValue);
  }

}

//Calling treeHeight recursively to find the height of the tree.
void binaryTree::treeHeight(TreeNode *nodePtr, int *maxHeightPtr)
{
  if(nodePtr)
  {

    if(nodePtr->height > this->maxHeight)
    {
      this->maxHeight = nodePtr->height;
    }
      treeHeight(nodePtr->left,maxHeightPtr);
      treeHeight(nodePtr->right,maxHeightPtr);
  }

}

//Output the height of the tree.
void binaryTree::getMaxHeight()
{
  heightSetterDriver();
  treeHeight(root, maxHeightPtr);
  cout<< this->maxHeight;
}

//Menu prompt for our users.
void printMenu()
{
  cout<<"\n\n";
  cout<<"********************************************************************************************************"<<endl;
  cout<<"*                                                                                                      *"<<endl;
  cout<<"*                                          Select an Option                                            *"<<endl;
  cout<<"*                                                                                                      *"<<endl;
  cout<<"*    1. Display Inorder                  2. Display Preorder                     3. Display Postorder  *"<<endl;
  cout<<"*                                                                                                      *"<<endl;
  cout<<"*    4. Print Tree Height                5. Search for Node                      6. Delete a Node      *"<<endl;
  cout<<"*                                                                                                      *"<<endl;
  cout<<"*                                        7. Select to Exit                                             *"<<endl;
  cout<<"*                                                                                                      *"<<endl;
  cout<<"********************************************************************************************************\n"<<endl;
}

#endif
