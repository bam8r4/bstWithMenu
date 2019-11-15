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
      int value;    //Value in the node
      TreeNode *left;   //Pointer to left child
      TreeNode *right;   //Pointer to right child
  };

  TreeNode *root;   //Pointer to root node

  //Private member functions
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(int value, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;
  int treeHeight(TreeNode *);



public:
  //Constructor
  binaryTree()
  {root = nullptr;}

  //Destructor
  ~binaryTree()
  {destroySubTree(root);}

  //Binary tree operations
  void insertNode(int value);
  void searchNode(int value);
  void remove(int value);
  //int treeHeight(TreeNode *);


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
    treeHeight(root);
  }

};
void binaryTree::insert(TreeNode *&nodePtr,  TreeNode *&newNode)
{
    if(nodePtr == nullptr)
    {
      nodePtr = newNode;    //Insert the node.
    }
    else if(newNode->value < nodePtr->value)
    {
      insert(nodePtr->left, newNode);   //Search the left branch.
    }
    else
    {
      insert(nodePtr->right, newNode);    //Search the right branch.
    }
}

//Creates new node and stores a num in it. It then passes that value to insert function.
void binaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr;    //Pointer to a new node.


    //Creation of a new node with num stored in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);   //Insert new node.
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
      displayInOrder(nodePtr->left);
      cout<< nodePtr->value <<endl;
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

//Calling treeHeight recursively to find the height of the tree.
int binaryTree::treeHeight(TreeNode *nodePtr)
{
  //cout<<"Being called";
  if (nodePtr == nullptr)
  {
    //cout<<"Being called";
    return 0;
  }
  else
  {
    int lb = treeHeight(nodePtr->left);
    int rb = treeHeight(nodePtr->right);
    return 1 + max(lb,rb);
    //return max(treeHeight(nodePtr->left),treeHeight(nodePtr->right))+1;
  }

}
#endif
