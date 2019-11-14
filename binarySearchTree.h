//Author of this code:Brent Moran

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#inlclude <iostream>
using namespace std;

//Inserts a new node into the tree with the value in the TreeNode pointer.
//That value is then inserted into the tree.
void bstWithMenu::insert(TreeNode *&nodePtr,  TreeNode *&newNode)
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
void bstWithMenu::insertNode(int num)
{
    TreeNode *newNode = nullptr;    //Pointer to a new node.


    //Creation of a new node with num stored in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode)   //Insert new node.
}

//Called by the destructor to delete all nodes in the tree.
void bstWithMenu::destroySubTree(TreeNode *nodePtr)
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
bool bstWithMenu::searchNode(int num)
{
    TreeNode *nodePtr = root;

    while(nodePtr)
    {
        if(nodePtr->value == num)
        {
          return true;
        }
        else if(num < nodePtr->value)
        {
          nodePtr = nodePtr->right;
        }
        else
        {
          nodePtr = nodePtr->right;
        }

        return false;
    }
}

//Calls deleteNode to delete the node with the value passes into deleteNode.
void bstWithMenu::remove(int num)
{
    deleteNode(num, root);
}

//Deletes the node with value member same as num.
void bstWithMenu::deleteNode(int num, TreeNode *&nodePtr)
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

void bstWithMenu::makeDeletion(TreeNode *&nodePtr)
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
void bstWithMenu::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
      displayInOrder(nodePtr->left);
      cout<< nodePtr->value <<endl;
      displayInOrder(nodePtr->right);
    }
}

//Display pre order travel.
void bstWithMenu::displeyPreOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
      cout << nodePtr->value << endl;
      displeyPreOrder(nodePtr->left);
      displeyPreOrder(nodePtr->right);
    }
}

void bstWithMenu::displayPostOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
    }
}
