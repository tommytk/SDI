#include "BinSearchTree.h"
#include "Aircraft.h"
#define NULL 0
#include <exception>
#include <string>
#include <iostream>
#include <cstdlib>
using std::cout; using std::endl;

// Smaller elements go left
// larger elements go right
BinarySearchTree::treeNode::treeNode(Aircraft* data, treeNode* left, treeNode* right): _data(data), _right(right), _left(left)
{

}
BinarySearchTree::treeNode::treeNode()
{
	_right = NULL;
	_left = NULL;
}
BinarySearchTree::BinarySearchTree()
{
	_root = NULL;
	_nodeCount = 0;
}
BinarySearchTree::NodePtr& BinarySearchTree::_search(std::string ID, NodePtr &CurrentPositonInTree)
{
	if(CurrentPositonInTree == NULL)//If the tree is empty or there is a missing node
	{
		return CurrentPositonInTree;

	}
	else if (ID == CurrentPositonInTree->_data->getCallSig())
	{

	}


}
void BinarySearchTree::insert(tree_node *root, Aircraft newCraft)
{
	
	tree_node* t = new tree_node;
    tree_node* parent;
	
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(isEmpty()) 
  {
	  root = new tree_node(newCraft);
  }
  else
  {
	  
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr) //loop until curr = NULL
    {
		//getters get serial
        parent = curr;
		if(t->data->getSerial() > curr->data->getSerial()) //is the new node greater than the parent note
		{
			curr = curr->right; //make current the right child node
		}
        else
		{
			curr = curr->left; //make current the left child node
		}
    }

	if(t->data->getSerial() < parent->data->getSerial()) //if new node is LESS than the parent
	{
       parent->left = t; //put new node in left child of parent 
	}
    else
	{
       parent->right = t; //put new node in right child of parent
	}

  }
}

void BinarySearchTree::remove(Aircraft* d)
{
    //Locate the element
	
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
		if(curr->data == d->getSerial())
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d > curr->data)
			 {
				 curr = curr->right;
			 }
             else
			 {
				 curr = curr->left;
			 }
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }

	// 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL)) //check if the node has a single child
    {
       if(curr->left == NULL && curr->right != NULL) //left side is EMPTY
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // right side is EMPTY
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

	//We're looking at a leaf node
	if(curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) //check which side of the parent to delete
		{
			parent->left = NULL; //remove from node
		}
        else
		{
			parent->right = NULL;
		}
		 		 
		//IF?!!
		delete curr; //clear the curr variable
		return; //return to main
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
				
				curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
		 		curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

void BinarySearchTree::print_inorder()
{
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
  preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
	//p = root
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
  postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else return;
}

int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
       cout<<" 3. Pre-Order Traversal "<<endl;
       cout<<" 4. Post-Order Traversal "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    cin>>tmp;
                    b.insert(tmp);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 6 : system("pause");
                    return 0;
                    break;
       }
    }
}























//BinSearchTree::BinSearchTree()
//{
//	_root = NULL;
//	_nodeSize = 0;
//}
//Node::Node(Aircraft* data,Node* left, Node* right)
//{
//	this->left = left;
//	this->right = right;
//	this->_data = data;
//}
//Node::Node()
//{
//}
//Node* _search(std::string ID, Node* &currentPositionInTree)
//{
//	if (currentPositionInTree == NULL)// in case of a search for a missing node or if the tree is empty
//	{
//		return currentPositionInTree;
//	}
//	else if (ID == currentPositionInTree->_data->getRegNum())//if the ID = the ID of the Aircraft in the node
//	{
//		return currentPositionInTree;//returns this position
//	}
//	//if it is not in that node then check which child node it is in
//	else if (currentPositionInTree->_data->getRegNum() < ID)
//	{
//		return _search(ID, currentPositionInTree->right);// restarts the search with the current position as child
//	}
//	else if (currentPositionInTree->_data->getRegNum() > ID)
//	{
//		return _search(ID, currentPositionInTree->left);
//	}
//	else
//	{
//		throw "Postion searched for is not found...";
//	}
//}
//bool _insert(Node* &currentPositionInTree, Node* insertPTR)
//{
//	Node* &ptrField = _search(insertPTR->_data->getRegNum(),currentPositionInTree);// Search for the position given to the function "insertPTR"
//
//	if(ptrField != NULL)// if the node is not equal to null
//	{
//		if(ptrField->_data->getRegNum() == insertPTR->_data->getRegNum())// if the reg number of the node postion is equal to that of the node pointed to
//		{
//			delete ptrField->_data;
//			ptrField->_data = insertPTR->_data;
//			delete insertPTR;
//		}
//		else
//		{
//			throw "un-able to add data, node is taken";
//		}
//	}
//	else // slot is free set ptrField as the insertPTR
//	{
//		ptrField = insertPTR; 
//	}
//	return true;
//}
//
//bool BinSearchTree::addItem(Aircraft* itemToAdd)
//{
//	try
//	{
//		Node* toAdd = new Node(itemToAdd,NULL,NULL);
//
//		if (_insert(_root,toAdd) == 1)
//		{
//			_nodeSize++;
//			
//			
//		}
//		else
//		{
//			
//		}
//	}
//	catch (char const* error)
//	{
//		throw error;
//	}
//}