#include <iostream>

template <typename T>
class Node {
public:
	T value;
	Node* left;
	Node* right;
	Node(T val) :value(val)
};

template <typename T>
class Tree {
public:
	Node<T>* root;
	void preorder(Node<T>* node ) {
		cout << node.value << endl;
		if(node->left)
		preorder(node->left);
		if(node->right)
		preorder(node->right);
	}

	void inorder(Node<T>* node) {
		if (node->left)
			inorder(node->left);
		cout << node.value << endl;
		if (node->right)
			inorder(node->right);
	}

	void postorder(Node<T>* node) {
		if (node->left)
			postorder(node->left);
		if (node->right)
			postorder(node->right);
		cout << node.value << endl;
	}
};

int main() {
	Tree<int> A;
	A.root = new Node<int>(0);
	A.root->left = new Node<int>(1);
	A.root->right = new Node<int>(2);
	A.root->left->left = new Node<int>(3);
	A.root->left->right = new Node<int>(4);
	A.root->right->left = new Node<int>(5);
	A.root->right->right = new Node<int>(6);

	A.preorder(A.root);
	A.inorder(A.root);
	A.postorder(A.root);

}