#pragma once
#include "pple.h"
//#include "treeNode.h"

template <typename T>
class BinaryTree {
private:

	struct TreeNode {
		T data;
		TreeNode* left;
		TreeNode* right;
		void insert(TreeNode* &, TreeNode* &);

	};

	TreeNode* root;
	TreeNode* getNewNode(T& data)
	
		{
			TreeNode* newNode = new TreeNode;
			newNode->data = data;
			newNode->left = newNode->right = nullptr;
			return newNode;
		};
	

	void insert(TreeNode* &, TreeNode* &);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	void displayInOrder() const { displayInOrder(root); }
	void insertNode(T&);


	BinaryTree<T>();
	~BinaryTree<T>();



	//T findSmallest();
	//T findLargest();
	//void deleteTreeNode(TreeNode<T> node);
	//void displayBreadthFirst();
};



//// creating new node and allocating dynamically
//template <typename T>
//BinaryTree<T>::TreeNode *getNewNode(T& data)
//{
//	TreeNode* newNode = new TreeNode;
//	newNode->data = data;
//	newNode->left = newNode->right = nullptr;
//	return newNode;
//};


// It searches for the appropriate location in the subtree to insert the node, then makes the insertion.
template <typename T>
void BinaryTree<T>::insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	if (!nodePtr)
		nodePtr = newNode;

	else if (newNode->data < nodePtr->data)
		insert(nodePtr->left, newNode);

	else
		insert(nodePtr->right, newNode);
}


// default constructor
template <typename T>
BinaryTree<T>::BinaryTree<T>() : root(nullptr) {};

// destructor
template <typename T>
BinaryTree<T>::~BinaryTree<T>() { std::cout << "destructor called" << std::endl; } //TODO: destroySubTree func


// Insert a node into the tree.
template <typename T>
void BinaryTree<T>::insertNode(T& data)
{
	// Create a new node and store num in it.
	TreeNode* newNode = new TreeNode;
	newNode->data = data;
	newNode->left = newNode->right = nullptr;   // leaf nodes

	// Insert the node.
	root->insert(root, newNode);
}



// DDisplays the values in the subtree pointed to by nodePtr, via inorder traversal.
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		std::cout << nodePtr->value << std::endl;
		displayInOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via preorder traversal.
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->value << std::endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via postorder traversal.
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->value << std::endl;
	}

}



