#include <queue>

template <typename T>
void BinaryTree<T>::displayBreadthFirst(TreeNode* nodePtr) const
{
	std::queue<TreeNode*> q;
	q.push(nodePtr);

	while (!q.empty()) {
		TreeNode* current = q.front();
		std::cout << current->TreeNode::data.getBirthdate() << std::endl;
		if (current->left != nullptr)
			q.push(current->left);

		if (current->right != nullptr)
			q.push(current->right);
		q.pop();

	}

}
