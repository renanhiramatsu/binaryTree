#pragma once
#include "person.h"
//#include "treeNode.h"

template <typename T>
class BinaryTree {
private:

	struct TreeNode : public BinaryTree {
		Person data;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

	};
	
	std::string treeType;
	TreeNode* root;
	TreeNode* getNewNode(Person& data)
	{
		TreeNode* newNode = new TreeNode;
		newNode->data = data;
		newNode->left = newNode->right = nullptr;
		return newNode;
	};

	//friend struct TreeNode;
	//friend class Person;

	void insert(TreeNode*&, TreeNode*&, std::string);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void displayBreadthFirst(TreeNode*) const;

	//	BinaryTree<T> operator<(const BinaryTree& *);

public:
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	void displayBreadthFirst() const { displayBreadthFirst(root); }

	template <typename U>
	friend std::ostream& operator <<(std::ostream& out, BinaryTree<U>& obj);
	void insertNode(Person&, std::string);


	BinaryTree<T>();
	BinaryTree<T>(std::string type);
	~BinaryTree<T>();




	//T findSmallest();
	//T findLargest();
	//void deleteTreeNode(TreeNode<T> node);
	//void displayBreadthFirst();
};

//typename BinaryTree<T>::TreeNode

//overloading the output operator
//ISNT WORKING PROPERLY
template <typename T>
std::ostream& operator << (std::ostream& out, BinaryTree<T>& obj) {
	out << "wtf" << std::endl;
	out << obj.getFullName() << "\t";
	//out << obj.getBirthdate() << std::endl;
	//out << obj->TreeNode::data.getBirthdate() << std::endl;
	return out;
}

// default constructor
template <typename T>
BinaryTree<T>::BinaryTree<T>() : root(nullptr), treeType(" ") {};


template <typename T>
BinaryTree<T> ::BinaryTree<T>(std::string type) {
	root = nullptr;
	treeType = type;
}

// destructor
template <typename T>
BinaryTree<T>::~BinaryTree<T>() { std::cout << "destructor called" << std::endl; } //TODO: destroySubTree func




// It searches for the appropriate location in the subtree to insert the node, then makes the insertion.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode, std::string type)
{
	if (type == "birthday") {
		if (!nodePtr)
			nodePtr = newNode;

		else if (newNode->TreeNode::data.getBirthdate() < nodePtr->TreeNode::data.getBirthdate()) {
			//std::cout << "comparing only birthdays: " << std::endl;
			insert(nodePtr->left, newNode, type);
		}

		else {
			insert(nodePtr->right, newNode, type);

		}
	}
	if (type == "name") {

		if (!nodePtr)
			nodePtr = newNode;

		else if (newNode->TreeNode::data.getFirstName() < nodePtr->TreeNode::data.getFirstName() && 
				 newNode->TreeNode::data.getLastName() < nodePtr->TreeNode::data.getLastName()) {
			//std::cout << "comparing only names: " << std::endl;

			insert(nodePtr->left, newNode, type);
		}
		else
		{
			insert(nodePtr->right, newNode, type);
		}
	}


	/*else if (newNode->TreeNode::data.getFirstName() < nodePtr->TreeNode::data.getFirstName())
		insert(nodePtr->left, newNode);*/
}


											
// Insert a node into the tree.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::insertNode(Person& data, std::string type)
{
	// Create a new node and store num in it.
	TreeNode* newNode = new TreeNode;
	newNode->data = data;
	newNode->left = newNode->right = nullptr;   // leaf nodes

												// Insert the node.
	root->insert(root, newNode, type);
}



// DDisplays the values in the subtree pointed to by nodePtr, via inorder traversal.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;
		displayInOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via preorder traversal.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		//std::cout << nodePtr->data << std::endl;
		std::cout << nodePtr->TreeNode::data.getFirstName() << " "
			<< nodePtr->TreeNode::data.getLastName() << std::endl;

		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via postorder traversal.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->TreeNode::data.getFullName() << " "
			<< nodePtr->TreeNode::data.getLastName() << std::endl;
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via breadth-first traversal.

//*************************************************************************************************************
// 
// PRE:
// POS:
//
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayBreadthFirst(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);									//SOMETHING HERE IS WRONG
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;
	}

}



