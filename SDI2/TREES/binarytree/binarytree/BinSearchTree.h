#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H
#include "Aircraft.h"
#include <vector>
//#include <iostream>
//#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	class treeNode
	{
	public:
		treeNode(Aircraft* data, treeNode* left, treeNode* right);
		treeNode();
		treeNode* _left;
		treeNode* _right;  
		Aircraft* _data;

	};
	typedef class treeNode* NodePtr;
	NodePtr _root;
	int _nodeCount;
	NodePtr &_search(std::string ID, NodePtr &curr);

public:
	BinarySearchTree()

	bool isEmpty() const { return root==NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(tree_node *root, Aircraft);
	void remove(Aircraft* d);
};
#endif
//class Node
//{
//   public:
//		   Node(Aircraft* data,Node* left, Node* right);
//		   Node();
//		   Aircraft* _data;
//		   Node* left;
//		   Node* right;
//};
//
//class BinSearchTree
//{
//private:
//	   
//	   Node* _root;
//	   int _nodeSize;
//	   bool _insert(Node* &curr,Node* insertPTR);
//	   Node* &_search(std::string ID, Aircraft* &curr);
//public:
//	BinSearchTree();
//	bool addItem(Aircraft* itemToAdd);
//
//};