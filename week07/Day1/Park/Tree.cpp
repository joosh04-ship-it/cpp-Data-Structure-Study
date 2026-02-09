#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node {
public:
	T value;
	Node * left = nullptr;
	Node * right = nullptr;
	Node(T val):value(val){}
};

template <class T>
class Tree {
public:
	Node<T> * root;
	void preOrder(Node<T>* node) {
		cout << node->value << endl;
		if(node->left)
		preOrder(node->left);
		if(node->right)
		preOrder(node->right);
	}
	void inOrder(Node<T>* node) {
		if (node->left)
			inOrder(node->left);
		cout << node->value << endl;
		if (node->right)
			inOrder(node->right);
	}
	void postOrder(Node<T>* node) {
		if (node->left)
			postOrder(node->left);
		if (node->right)
			postOrder(node->right);
		cout << node->value << endl;
	}
};

int main()
{
	Tree<int> A;
	A.root = new Node<int>(0);
	A.root->left = new Node<int>(1);
	A.root->right = new Node<int>(2);
	A.root->left->left = new Node<int>(3);
	A.root->left->right = new Node<int>(4);
	A.root->right->left = new Node<int>(5);
	A.root->right->right = new Node<int>(6);
	A.preOrder(A.root);
	cout << endl;
	A.inOrder(A.root);
	cout << endl;
	A.postOrder(A.root);
}
