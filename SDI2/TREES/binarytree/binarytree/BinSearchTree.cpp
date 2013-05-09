#include "BinSearchTree.h"
#include "Aircraft.h"
#define NULL 0
#include <exception>
#include <string>
#include <iostream>
#include <cstdlib>
using std::cout;

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
BinarySearchTree::~BinarySearchTree()
{
}
BinarySearchTree::NodePtr& BinarySearchTree::_search(std::string ID, NodePtr &CurrentPositonInTree)
{
	try
	{
		if(CurrentPositonInTree == NULL)//If the tree is empty or there is a missing node
		{
			return CurrentPositonInTree;

		}
		else if (ID == CurrentPositonInTree->_data->getCallSig())// The ID entered matches the Aircraft ID held by the current node.
		{
			return CurrentPositonInTree;
		}
		// If its not in the current node then we work out what child node to move to.
		else if (CurrentPositonInTree->_data->callSig() < ID)
		{
			return _search(ID, CurrentPositonInTree->_right); //restarts the search with the currentpositionintree as the relevant child node.
		}
		else if (CurrentPositonInTree->_data->callSig() > ID)
		{
			return _search(ID, CurrentPositonInTree->_left);
		}
		else
		{
			throw "Un-able to find position in tree";
		}
	}
	catch(const char* error)
	{
		throw error;
	}

}
bool BinarySearchTree::_insert(NodePtr &CurrentPositionInTree,NodePtr insertPtr)
{
	try
	{
		NodePtr &ptrField = _search(insertPtr->_data->callSig(),CurrentPositionInTree); //This will return the position of the data in the Tree, that is specified in the inserPtr

		if(ptrField != NULL) //The ptrField will == null if the search function retunrs currentPositionInTree as Null because missing Node or empty Tree.
		{
			if(ptrField->_data->callSig() == insertPtr->_data->callSig()) //We want to compare the callSig of the InserPtr and PtrField which is the search function retunr
			{
				delete ptrField->_data;
				ptrField->_data = insertPtr->_data;
				delete insertPtr;
			}

		}
		else
		{
			ptrField = insertPtr; 
		}
		return true;
	}
	catch (char const* error)
	{
		throw error;
	}
}

void BinarySearchTree::_addNodesToVector(std::vector<NodePtr> &nodes, NodePtr currentPostitionInTree, bool toBalance)
{
	try
	{
		if (currentPostitionInTree == NULL)
		{
			return; 
		}
		_addNodesToVector(nodes,currentPostitionInTree->_left); 
		nodes.push_back(currentPostitionInTree);
		if(toBalance)
		{
			currentPostitionInTree->_left = NULL;
		}
		_addNodesToVector(nodes,currentPostitionInTree->_right); 
		if(toBalance)
		{
			currentPostitionInTree->_right = NULL;
		}

		return;
	}
	catch (const char* error)
	{
		throw error;
	}
}
void BinarySearchTree::_balanceTree()
{
	try
	{
		std::vector<NodePtr> nodes;
		_addNodesToVector(nodes,_root,true);
		for (int idx = 0; idx <nodes.size();idx++)
		{
			nodes[idx]->_right = NULL;
			nodes[idx]->_left = NULL;
		}
		_root = NULL;
		_balanceHelper(nodes);
	}
	catch (char const* error)
	{
		throw error;
	}
}
void BinarySearchTree::_balanceHelper(std::vector<NodePtr> nodeList)
{
	try
	{
		if (nodeList.size() <= 2)
		{
			for(int idx = 0; idx < nodeList.size(); idx++)
			{
				_insert(_root,nodeList[idx]);
			}
			return;
		}
		else
		{
			std::vector<NodePtr> list1,list2;
			int medoid = _getMidPoint(nodeList);
			_insert(_root,nodeList[medoid]);

			for(int idx = 0; idx < nodeList.size(); idx++)
			{
				if (idx < medoid)
				{
					list1.push_back(nodeList[idx]);
				}
				if (idx > medoid)
				{
					list2.push_back(nodeList[idx]);
				}
			}
			_balanceHelper(list1);
			_balanceHelper(list2);
			return;
		}
	}
	catch (char const* error)
	{
		throw error;
	}
}
int BinarySearchTree::_getMidPoint(std::vector<NodePtr> nodeList)
{	
	double mid = nodeList.size() / 2;
	for (int idx = 0; idx <nodeList.size();idx++)
	{
		if ((idx == (mid+0.5))||(idx == mid))
		{
			return idx;
		}
	}
}
void BinarySearchTree::_clearTreeHelper(NodePtr currentPositionInTree)
{
	if (currentPositionInTree == NULL)
	{
		return; 
	}
	_clearTreeHelper(currentPositionInTree->_left); 
	_clearTreeHelper(currentPositionInTree->_right);
	delete currentPositionInTree->_data;
	delete currentPositionInTree;
	return;
}
//////-----------------------\\\\\\
///// Binary Tree Public Functions.
////   AND WHAT.
//----------------------------\\\\\\

bool BinarySearchTree::addItem(Aircraft* itemToAdd)
{
	try
	{
		NodePtr toAdd = new treeNode(itemToAdd,NULL,NULL); //create a new object of treeNode (Data, childnodes)

		if(_insert(_root,toAdd) == 1) //  Check whether the insert function returns true IE = 1. We use root to start at the top of the 
		{
			_nodeCount++; // Increase the node count as we have added a new node
			_balanceTree();
			return true;
		}
		else
		{
			return false;
		}
	}
	catch(const char* error)
	{
		throw error;
	}

}

bool BinarySearchTree::remove(std::string idToDelete)
{
 try
 {
	NodePtr &ptrPos = _search(idToDelete,_root); // Search for the ID in the binary tree -> Load that as a reference called ptrPos
	if (ptrPos == NULL) // If search returns null then we haven't found the ID in the tree -_-
	{
		throw "The item position cannot be found in the tree!";

	}
	NodePtr toDelete = ptrPos; // Create a new Pointer
	ptrPos = toDelete->_left; // Set ptrPos as the node lower than the current ID node.
	if (ptrPos == NULL) // If the child left node is Null, Then we do not have to remove it, just change ptrPos the the Right Node
	{
		ptrPos = toDelete->_right;
	}
	
	else if (toDelete->_right != NULL) // If there is a right node then insert the data into that one, otherwise we just delete the data in the current one
	{
		_insert(ptrPos,toDelete->_right);
	}
	delete toDelete->_data; 
	delete toDelete; // Delete the object and the data within the node. Nobody shall ever hear of this.
	_nodeCount--;
	return true;
 }
 catch(const char* error)
 {
	 throw error;
 }
}
void BinarySearchTree::clearTree()
{
	_clearTreeHelper(_root);
}
int BinarySearchTree::getSize() const
{
	return _nodeCount;
}

Aircraft* BinarySearchTree::retreiveByCallSig(std::string ID)
{
	try
	{
		NodePtr retrieveNode = _search(ID,_root); //Search for the Id(call sig) 
		if (retrieveNode != NULL) //IF its not null then it means it has found the relevant node
		{
			return retrieveNode->_data; // Return the data held in the node.
		}
		else
		{
			throw "Unknown Signature!!";
		}


	}
	catch (const char* error)
	{
		throw error;
	}

}
std::vector<Aircraft*> BinarySearchTree::getDataAsVector()
{
	std::vector<NodePtr> temp; // set up a temporary vector
	_addNodesToVector(temp, _root); // use the add nodes function 
	std::vector<Aircraft*> aircraftList; // create a vector called aircraftList
	for (int idx = 0; idx < temp.size(); idx++)
	{
		aircraftList.push_back(temp[idx]->_data); // Load the Aircraft vector with the temp vector[element] data. So the data in the nodes.
	}
	return aircraftList;


}

