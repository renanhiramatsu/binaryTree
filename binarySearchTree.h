#pragma once
#include "person.h"
#include "treeNode.h"

template <typename T>

class BinaryTree {
private:
	TreeNode<T>* root;

public:
	void insert(TreeNode<T> node);
	T findSmallest();
	T findLargest();
	void deleteTreeNode(TreeNode<T> node);
	void displayPreOrder();
	void displayPostOrder();
	void displayInOrder();
	void displayBreadthFirst();
};

template <typename T>
void BinaryTree<T>::insert(TreeNode<T> node) {
	TreeNode<T> temp = node;
	if (!root) {
		root = node;
	}
	else if(node->data > root->data){

		while (root-> )
	}

	

}