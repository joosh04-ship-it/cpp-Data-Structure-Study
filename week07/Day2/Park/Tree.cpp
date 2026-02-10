#include <iostream>
#include <vector>
#include <ctime>
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
	Node<T> * root = nullptr;
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
	void insert(T val) {
		Node<T>* pointer = root;
		if (!root) {
			root = new Node<T>(val);
			return;
		}
		while (true) {
			if (pointer->value > val) {
				if (pointer->left) {
					pointer = pointer->left;
				}
				else {
					pointer->left = new Node<T>(val);
					break;
				}
			}
			else {
				if (pointer->right) {
					pointer = pointer->right;
				}
				else {
					pointer->right = new Node<T>(val);
					break;
				}
			}
		}
	}
	Node<T>* find(T val) {
		Node<T>* pointer = root;
		if (!root) {
			return nullptr;
		}
		while (true) {
			if (pointer->value > val) {
				if (pointer->left) {
					pointer = pointer->left;
				}
				else {
					return nullptr;
				}
			}
			else if(pointer -> value < val) {
				if (pointer->right) {
					pointer = pointer->right;
				}
				else {
					return nullptr;
				}
			}
			else {
				return pointer;
			}
		}
	}
	Node<T>* findParent(T val) {
		Node<T>* pointer = root;
		Node<T>* maybeParent = nullptr;
		if (!root) {
			return nullptr;
		}
		while (true) {
			if (pointer->value > val) {
				if (pointer->left) {
					maybeParent = pointer;
					pointer = pointer->left;
				}
				else {
					return nullptr;
				}
			}
			else if (pointer->value < val) {
				if (pointer->right) {
					maybeParent = pointer;
					pointer = pointer->right;
				}
				else {
					return nullptr;
				}
			}
			else {
				return maybeParent;
			}
		}
	}
	void _delete(T val) {
		Node<T>* parent = findParent(val);
		Node<T>* pointer = find(val);
		if (!parent) {
			parent = root;
		}
		if (pointer) {
			bool isLeft = (parent->value > pointer->value);
			if (!(pointer->left) && !(pointer->right)) {
				delete pointer;
				if (isLeft) {
					parent->left = nullptr;
				}
				else {
					parent->right = nullptr;
				}
			}
			else if ((pointer->left) && !(pointer->right)) {
				Node<T>* tmp = pointer->left;
				delete pointer;
				if (isLeft) {
					parent->left = tmp;
				}
				else {
					parent->right = tmp;
				}
			}
			else if (!(pointer->left) && (pointer->right)) {
				Node<T>* tmp = pointer->right;
				delete pointer;
				if (isLeft) {
					parent->left = tmp;
				}
				else {
					parent->right = tmp;
				}
			}
			else {
				Node<T>* _pointer = nullptr;
				pointer = pointer->right;
				while (pointer->left) {
					_pointer = pointer;
					pointer = pointer->left;
				}
				_pointer->left = nullptr;
				if (isLeft) {
					pointer->right = parent->left->right;
					pointer->left = parent->left->left;
					delete parent->left;
					parent->left = pointer;
				}
				else {
					pointer->right = parent->right->right;
					pointer->left = parent->right->left;
					delete parent->right;
					parent->right = pointer;
				}
				
			}
		}
		else {
			cout << "val이 없슴"<<endl;
			return;
		}
	}
};

int main()
{
	srand(time(NULL));
	Tree<int> A;
	for (int i = 0; i < 30; i++) {
		A.insert(rand());
	}

	A.inOrder(A.root);

	A._delete(A.root->value);

	A.inOrder(A.root);
	cout << endl;
}
