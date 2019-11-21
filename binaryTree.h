#pragma once
#include "person.h"
#include "queueADT.h"
//#include "treeNode.h"

template <typename T>
class BinaryTree {
private:
	int count=0;
	struct TreeNode: public BinaryTree {
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

	friend struct TreeNode;
	friend class Person;
	BinaryTree<T>::TreeNode* getleft() { return BinaryTree<T>::TreeNode::left; }
	BinaryTree<T>::TreeNode* getRight() { return BinaryTree<T>::TreeNode::right; }
	void insert(TreeNode*&, TreeNode*&, std::string);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void displayBreadthFirst(TreeNode*) const;

	//	BinaryTree<T> operator<(const BinaryTree& *);

public:
	Person getData() { return TreeNode::data; }
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	void displayBreadthFirst() const { displayBreadthFirst(root); }

	//template <typename U>
	friend std::ostream& operator <<(std::ostream& out, const TreeNode& obj);
	void insertNode(Person&, std::string);
	void removeNode(Person&);
	bool searchNode(Person&);

	BinaryTree<T>();
	BinaryTree<T>(std::string type);
	~BinaryTree<T>();




	//T findSmallest();
	//T findLargest();
	//void deleteTreeNode(TreeNode<T> node);
	//void displayBreadthFirst();
};




//overloading the output operator
//ISNT WORKING PROPERLY
template <typename T>
std::ostream& operator << (std::ostream& out, const typename BinaryTree<T>::TreeNode &obj) {
	out << obj.BinaryTree<Person>::TreeNode::data.getFirstName() << " " ;
	out << obj.BinaryTree<Person>::TreeNode::data.getLastName() << "\t" ;
	out << "no";
	//out << obj.getData().getFullName();
	//out << obj.getFullName() << "\t";
	//out << obj.getBirthdate() << std::endl;
	//out << obj->TreeNode::data.getBirthdate() << std::endl;
	return out;
}

// default constructor
template <typename T>
BinaryTree<T>::BinaryTree<T>() : root(nullptr), treeType(" ") {};

// overloded constructor 
template <typename T>
BinaryTree<T> ::BinaryTree<T>(std::string type) {
	root = nullptr;
	treeType = type;
}

// destructor
template <typename T>
BinaryTree<T>::~BinaryTree<T>() { std::cout << "destructor called" << std::endl; } //TODO: destroySubTree func





//*************************************************************************************************************
//							void insert(TreeNode*& , TreeNode*& , std::String)
// PRE: a TreeNode nodePtr, a TreeNode newNode to compare with, and a string representing the type of data 
//		that is being implemented 
// POS:  node has been inserted into the tree  
// depending on the string parameter passed by the insertNode(), the function seraches for the appropiate 
// location within subtree for node insertion.
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode, std::string type)
{
	//adding into correct spot for birthday binary tree
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

	//adding into correct spot for name binary tree 
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


											

//*************************************************************************************************************
//								void insertNode( Person& data , std::string)
// PRE: Person data passed through reference, string representing the binary tree type 
// POS: the node has been inserted from root 
// the function takes in the data from main and calls the function to insert the new node
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
	count++;
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
		std::cout << nodePtr->TreeNode::data.getFirstName() << " "
				  << nodePtr->TreeNode::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;
		displayInOrder(nodePtr->right);
	}

}



// Displays the values in the subtree pointed to by nodePtr, via preorder traversal.

//*************************************************************************************************************
//								void displayPreOrder(TreeNode*) const				
// PRE: a TreeNode* nodePtr which is going to be used to for the traversal
// POS: all the values within each subtree will have been displayed 
// the function displays all the values through recursion and preOrder traversing (Node - left - right)
// uses const in header to because the values are constant and ensures none of the values are being changed
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		//std::cout << nodePtr << std::endl;
		std::cout << nodePtr->TreeNode::data.getFirstName() << " "
				  << nodePtr->TreeNode::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;

		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}

}



// DDisplays the values in the subtree pointed to by nodePtr, via postorder traversal.

//*************************************************************************************************************
//								void displayPostOrder(TreeNode*) const
// PRE: a TreeNode* nodePtr used for the traversal
// POS: all the values in the subtree is displayed in postOrder
// the function displays each value in the subtree through recursion and postOrder ( Left - Right - Node )
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->TreeNode::data.getFirstName() << " "
				  << nodePtr->TreeNode::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;

	}

}



// Displays the values in the subtree pointed to by nodePtr, via breadth-first traversal.

//*************************************************************************************************************
//							void displayBreadthFirst(TreeNode*) const
// PRE: a TreeNode* nodePtr which is used for traversing
// POS: all treeNode members displayed by using breadth traversal.
// The function traverses the tree and displays the nodes by each level. 
// ex:
//					20
//				   /   \					would display 20 - 10 - 23 - 8 - 13 - 21 - 30
//				10		 23
//			   /  \	    /  \
//			 8     13  21    30
//
//
//**************************************************************************************************************
//template <typename T>
//void BinaryTree<T>::displayBreadthFirst(TreeNode* nodePtr) const
//{
//	ListQueue<BinaryTree<T>::TreeNode> treeQueue;
//	treeQueue.enqueue(*root);
//	if (root == nullptr)
//		return;
//	else {
//		while (!treeQueue.isEmpty()) {
//			const TreeNode temp = treeQueue.peekFirst();
//			treeQueue.dequeue();
//
//			if (temp.left != nullptr) {
//				treeQueue.enqueue(*temp.left);
//				std::cout << temp.left->getData().getFirstName() << " ";
//			}
//
//			if (temp.right != nullptr) {
//				treeQueue.enqueue(*temp.right);
//			}
//		}
//	}
//	
//		//displayPostOrder(nodePtr->left);									//SOMETHING HERE IS WRONG
//		//displayPostOrder(nodePtr->right);
//		//std::cout << nodePtr->TreeNode::data.getBirthdate() << std::endl;
//
//
//	
//}



template <typename T>
void BinaryTree<T>::displayBreadthFirst(TreeNode* nodePtr) const
{
	ListQueue<TreeNode*> q;
	q.enqueue(nodePtr);

	while (!q.isEmpty()) {
		TreeNode* current = q.peekFirst();
		std::cout << current->TreeNode::data.getBirthdate() << std::endl;
		if (current->left != nullptr)
			q.enqueue(current->left);

		if (current->right != nullptr)
			q.enqueue(current->right);
		q.dequeue();

	}

}


template <typename T>
void BinaryTree<T>::removeNode(Person&) {

}

template <typename T>
bool BinaryTree<T>::searchNode(Person&) {

}