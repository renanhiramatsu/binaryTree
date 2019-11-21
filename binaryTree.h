#pragma once
#include "person.h"
#include "queueADT.h"
//#include "treeNode.h"

template <typename T >
class BinaryTree {
private:
	template <typename T>
	struct TreeNode: public BinaryTree {
		T data;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};
	
	std::string treeType;
	TreeNode<T>* root;
	TreeNode<T>* getNewNode(Person& data)
	{
		TreeNode<T>* newNode = new TreeNode<T>;
		newNode->data = data;
		newNode->left = newNode->right = nullptr;
		return newNode;
	};

	friend struct TreeNode<T>;
	friend class Person;
	TreeNode<T>* getLeft() { return TreeNode<T>::left; }
	TreeNode<T>* getRight() { return TreeNode<T>::right; }
	void insert(TreeNode<T>*&, TreeNode<T>*&, std::string);
	void displayInOrder(TreeNode<T>*) const;
	void displayPreOrder(TreeNode<T>*) const;
	void displayPostOrder(TreeNode<T>*) const;
	void displayBreadthFirst(TreeNode<T>*) const;
	void destroySubTree(TreeNode<T>*);
	void deleteNode(T, TreeNode<T>*&);
	void completeDelete(TreeNode<T>*&);
	

	//	BinaryTree<T> operator<(const BinaryTree& *);

public:

	TreeNode<T>* getRoot();
	T getData();
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	void displayBreadthFirst() const { displayBreadthFirst(root); }

	//template <typename U>
	friend std::ostream& operator <<(std::ostream& out, const TreeNode<T>& obj);
	void insertNode(Person&, std::string);
	void removeNode(T&);
	bool searchNode(T&);

	BinaryTree<T>();
	BinaryTree<T>(std::string type);
	~BinaryTree<T>();

};

template <typename T>
BinaryTree<T>::TreeNode<T>* BinaryTree<T>::getRoot() { 
	return root;
}

template <typename T>
T BinaryTree<T>:: getData(){
	return BinaryTree<T>::TreeNode<T>::data; 
}


//
////overloading the output operator
////ISNT WORKING PROPERLY
//template <typename T>
//std::ostream& operator << (std::ostream& out, const typename BinaryTree<T>::TreeNode<T>&obj) {
//	out << obj.BinaryTree<Person>::TreeNode::data.getFirstName() << " " ;
//	out << obj.BinaryTree<Person>::TreeNode::data.getLastName() << "\t" ;
//	out << "no";
//	
//	return out;
//}

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
BinaryTree<T>::~BinaryTree<T>() {
	destroySubTree(root);
	std::cout << "destructor called" << std::endl;
}




//*************************************************************************************************************
//							void insert(TreeNode*& , TreeNode*& , std::String)
// PRE: a TreeNode nodePtr, a TreeNode newNode to compare with, and a string representing the type of data 
//		that is being implemented 
// POS:  node has been inserted into the tree  
// depending on the string parameter passed by the insertNode(), the function seraches for the appropiate 
// location within subtree for node insertion.
//**************************************************************************************************************
template <typename T>
void BinaryTree<T>::insert(TreeNode<T>*& nodePtr, TreeNode<T>*& newNode, std::string type)
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
	TreeNode<T>* newNode = new TreeNode<T>;
	newNode->data = data;
	newNode->left = newNode->right = nullptr;   // leaf nodes

												// Insert the node.
	root->insert(root, newNode, type);
}



//************************************************************************************
//							void displayInOrder(TreeNode*) const
// PRE: recieves a TreeNode nodePtr used to traverse through the tree
// POS: the tree has been displayed through in order traversal
// the function traverses through the array and displays through in order
//************************************************************************************
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		std::cout << nodePtr->TreeNode<T>::data.getFirstName() << " "
				  << nodePtr->TreeNode<T>::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode<T>::data.getBirthdate() << std::endl;
		displayInOrder(nodePtr->right);
	}

}




//************************************************************************************
//						void displayPreOrder(TreeNode*) const				
// PRE: a TreeNode* nodePtr used to for the traversal
// POS: all the values within each subtree will have been displayed 
// the function displays all the values through recursion and preOrder traversing 
// (Node - left - right)
//*************************************************************************************
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		//std::cout << nodePtr << std::endl;
		std::cout << nodePtr->TreeNode<T>::data.getFirstName() << " "
				  << nodePtr->TreeNode<T>::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode<T>::data.getBirthdate() << std::endl;

		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}

}


//******************************************************************************
//						void displayPostOrder(TreeNode*) const
// PRE: a TreeNode* nodePtr used for the traversal
// POS: all the values in the subtree is displayed in postOrder
// the function displays each value in the subtree through recursion 
// and postOrder ( Left - Right - Node )
//******************************************************************************
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode<T>* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		std::cout << nodePtr->TreeNode<T>::data.getFirstName() << " "
				  << nodePtr->TreeNode<T>::data.getLastName() << "\t\t Birthday: ";
		std::cout << nodePtr->TreeNode<T>::data.getBirthdate() << std::endl;

	}

}




//**********************************************************************************
//					void displayBreadthFirst(TreeNode*) const
// PRE: a TreeNode* nodePtr which is used for traversing
// POS: all treeNode members displayed by using breadth traversal.
// The function traverses the tree and displays the nodes by each level. 
// ex:
//					20
//				   /   \		 would display 20 - 10 - 23 - 8 - 13 - 21 - 30
//				10		 23
//			   /  \	    /  \
//			 8     13  21    30
//
//
//***********************************************************************************
template <typename T>
void BinaryTree<T>::displayBreadthFirst(TreeNode<T>* nodePtr) const
{
	ListQueue<TreeNode<T>*> q;
	q.enqueue(nodePtr);

	while (!q.isEmpty()) {
		TreeNode<T>* current = q.peekFirst();
		std::cout << current->TreeNode<T>::data.getBirthdate() << std::endl;
		if (current->left != nullptr)
			q.enqueue(current->left);

		if (current->right != nullptr)
			q.enqueue(current->right);
		q.dequeue();

	}

}



//****************************************************************************
//						void removeNode (T& data)
// PRE: receives a data of type T to be removed
// POS: nothing
// this function calls for the inside function deleteNode which begins
// the actual process of deleting node
//*****************************************************************************
template <typename T>
void BinaryTree<T>::removeNode(T& data) {
	deleteNode(data, root);
}


//***************************************************************************************
//					void deleteNode ( T, TreeNode*&)
// PRE: receives the value to be dleted along with the root of the binary tree
// POS: the deletion is processed
// this function finds the node where the data is and calls for another function 
// to completely delete the node from the binary tree
//***************************************************************************************

template <typename T>
void BinaryTree<T>::deleteNode(T val, TreeNode<T>*& nodePtr) {

	if (val.getFullName() < nodePtr->TreeNode<T>::data.getFullName())
		deleteNode(val, nodePtr->left);
	else if (val.getFullName() > nodePtr->TreeNode<T>::data.getFullName())
		deleteNode(val, nodePtr->right);
	else
		completeDelete(nodePtr);
}


//*******************************************************************************
//						void completeDelete(TreeNode&)
// PRE: receives the node that is going to be deleted
// POS: the node is deleted from the tree
// the function deletes the node from the tree while taking into account 
// the differnet scenarios that could occur while it is being run
//*******************************************************************************

template <typename T>
void BinaryTree<T>::completeDelete(TreeNode<T>*& nodePtr) {
	TreeNode<T>* temp = nullptr;
	bool d = false;
	// null nodePtr signifies an empty tree
	if (nodePtr == nullptr)
		std::cout << "There is nothing to delete!" << std::endl;

	// attaching the left node back to the tree
	else if (nodePtr->right == nullptr) {
		temp = nodePtr;
		nodePtr = nodePtr->left;
		delete temp;
		d = true;
	}

	// attaching the right node back to the tree
	else if (nodePtr->left == nullptr) {
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
		d = true;
	}

	//in the case of if there are two child nodes from the parent
	else{
		temp = nodePtr->right;
		while (temp->left) {
			temp = temp->left;
		}
		temp->left = nodePtr->left;
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
		d = true;
	}
	if (d == false)
		std::cout << "data not within tree" << std::endl;
	else
		std::cout << "ye" << std::endl;
}


//**********************************************************************************
//						void destroySubTree(TreeNode*)
// PRE: receives the treeNode pointer 
// POS: an individual node has been deleted from the binary tree
// the function deletes all of the subtrees(individual child nodes) 
// within the main binary tree
//***********************************************************************************

template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode<T>* nodePtr) {
	if (nodePtr) {
		std::cout << "inside subtree destructor! " << std::endl;
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}



//***********************************************************************
//						bool searchNode (T&)
// PRE: recieves a value for the function tosearch for 
// POS: returns whether or not the value has been found
// the function searches through the tree in order to find the 
// desired value specified
//***********************************************************************

//template <typename T>
//bool BinaryTree<T>::searchNode(T& val,std::string type) {
//	TreeNode<T>* nodeIter = root;
//	while (nodeIter) {
//		if (nodeIter->getData() == val)
//			return true;
//		else if (nodeIter->data > val)
//			nodeIter = nodeIter->right;
//		else 
//			nodeIter = nodeIter->left;
//	}
//	return false;
//}
template <typename T>
bool BinaryTree<T>::searchNode(T& val) {
	TreeNode<T>* nodeIter = getRoot();
	while (nodeIter)
	{
		if(nodeIter->data.getFullName() == val.getFullName() ) {
			std::cout << "Entry was found!" << std::endl;
			return true;
		}
		else if (nodeIter->data.getFullName() > val.getFullName())
			nodeIter = nodeIter->right;
		else
			nodeIter = nodeIter->left;
	}
	
	std::cout << "Entry was not found! " << std::endl;
	return false;
}