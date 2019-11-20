#pragma once
#include "person.h"
//#include "treeNode.h"

template <typename T>
class BinaryTree {
private:

	struct TreeNode : public BinaryTree {
		Person data;
		TreeNode* left;
		TreeNode* right;

	};

	TreeNode* root;
	TreeNode* getNewNode(Person& data)
	{
		TreeNode* newNode = new TreeNode;
		newNode->data = data;
		newNode->left = newNode->right = nullptr;
		return newNode;
	};

	friend struct TreeNode;
	friend class Person;

	void insert(TreeNode* &, TreeNode* &);

	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	void displayBreadthFirst(TreeNode *) const;


	
	//	BinaryTree<T> operator<(const BinaryTree& *);

public:
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	void displayBreadthFirst() const { displayBreadthFirst(root); }


	void insertNode(Person&);


	BinaryTree<T>();
	~BinaryTree<T>();



	//T findSmallest();
	//T findLargest();
	//void deleteTreeNode(TreeNode<T> node);
	//void displayBreadthFirst();
};





// It searches for the appropriate location in the subtree to insert the node, then makes the insertion.
template <typename T>
void BinaryTree<T>::insert(TreeNode* &nodePtr, TreeNode* &newNode)
{
	if (!nodePtr)
		nodePtr = newNode;

	else if (newNode->TreeNode::data.getBirthdate() < nodePtr->TreeNode::data.getBirthdate())
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
void BinaryTree<T>::insertNode(Person& data)
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
		//std::cout << nodePtr->data << std::endl;
		displayInOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via preorder traversal.
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;
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
//		std::cout << nodePtr->data << std::endl;
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via breadth-first traversal.
template <typename T>
void BinaryTree<T>::displayBreadthFirst(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->data << std::endl;
	}

}



