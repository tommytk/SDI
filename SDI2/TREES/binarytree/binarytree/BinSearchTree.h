#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H
#include "Aircraft.h"
#include <vector>
//#include <iostream>
//#include <cstdlib>


class BinarySearchTree
{
private:
	class treeNode
	{
	public:
		treeNode();
		treeNode(Aircraft* data, treeNode* left, treeNode* right);
		treeNode* _left;
		treeNode* _right;  
		Aircraft* _data;

	};

	typedef class treeNode* NodePtr;
	NodePtr _root;
	int _nodeCount;
	NodePtr &_search(std::string ID, NodePtr &curr);
	bool _insert(NodePtr &curr,NodePtr insertPTR);
	void _addNodesToVector(std::vector<NodePtr> &nodes,NodePtr curr,bool toBalance = false);
	
public:
	BinarySearchTree();

	/*bool isEmpty() const { return root==NULL; }*/
	
	bool addItem(Aircraft* itemToAdd);
	bool remove(std::string idToRemove);
	int getSize()const;
	Aircraft* retreiveByCallSig(std::string ID);
	std::vector<Aircraft*> getDataAsVector();
};
#endif
