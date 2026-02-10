#include <iostream>
#include <time.h>
using namespace std;

template <typename T>
class Node {
public:
	T value;
	Node* left;
	Node* right;
	Node(T val) :value(val) {}
};

template <typename T>
class Tree {
public:
	Node<T>* root = nullptr;
	void preorder(Node<T>* node) {
		cout << node.value << endl;
		if (node->left)
			preorder(node->left);
		if (node->right)
			preorder(node->right);
	}

	void inorder(Node<T>* node) {
		if (node->left)
			inorder(node->left);
		cout << node->value << endl;
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

	void insert(T value) {
		Node<T>* copy = root;
		if (root == nullptr) {
			root = new Node<T>(value);
			return;
		}

		while (1) {
			if (value < copy->value) {
				if (copy->left == nullptr) {
					copy->left = new Node<T>(value);
					break;
				}
				else {
					copy = copy->left;
				}
			}
			else {
				if (copy->right == nullptr) {
					copy->right = new Node<T>(value);
					break;
				}
				else {
					copy = copy->right;
				}
			}
		}
	}

	Node<T>* find(T value) {
		Node<T>* copy = root;
		if (root == nullptr) {
			cout << "root에 값이 없습니다." << endl;
			return 0;
		}

		while (1) {
			if (value < copy->value) {
				if (copy->left == nullptr) {
					return nullptr;
				}
				copy = copy->left;
			}else if (value > copy->value) {
				if (copy->right == nullptr) {
					return nullptr;
				}
				copy = copy->right;
			}
			else {
				return copy;
			}
		}
	}

	Node<T>* Pfind(T value) {
		Node<T>* copy = root;
		Node<T>* parent = root;
		while (1) {
			if (value < copy->value) {
				if (copy->left == nullptr) {
					return nullptr;
				}
				parent = copy;
				copy = copy->left;
			}
			else if (value > copy->value) {
				if (copy->right == nullptr) {
					return nullptr;
				}
				parent = copy;
				copy = copy->right;
			}
			else {
				return parent;
			}
		}
	}
	
	void Delete(T value) {
		if (root == nullptr) {
			cout << "root에 값이 없습니다." << endl;
			return;
		}

		Node<T>* copy = find(value);
		Node<T>* parent = Pfind(value);
		bool IsLeft = (parent->value < copy->value);
		if (copy->left != nullptr && copy->right != nullptr) {
			Node<T>* copycopy=nullptr;
			copy = copy->right;
			while (copy->left) {
				copycopy = copy;
				copy = copy->left;
			}
			if (IsLeft) {
				Node<T>* tmp = parent->left;
				parent->left = copy;
				copycopy->left = nullptr;
				delete tmp;
			}
			else {
				Node<T>* tmp = parent->right;
				parent->right = copy;
				copycopy->left = nullptr;
				delete tmp;
			}
		}
		else if (copy->left != nullptr) {
			if (IsLeft) {
				Node <T>* tmp = parent->left;
				tmp = copy->left;
				delete copy;
			}
			else {
				Node <T>* tmp = parent->right;
				tmp = copy->left;
				delete copy;
			}
		}
		else if (copy->right != nullptr) {
			if (IsLeft) {
				Node <T>* tmp = parent->left;
				tmp = copy->right;
				delete copy;
			}
			else {
				Node <T>* tmp = parent->right;
				tmp = copy->right;
				delete copy;
			}
		}
		else {
			delete copy;
		}
	}

};

int main() {
	srand(time(NULL));
	Tree<int> A;
	A.insert(8);
	A.insert(4);
	A.insert(1);
	A.insert(3);
	A.insert(7);
	A.insert(6);
	A.insert(5);
	A.insert(2);
	A.insert(10);
	A.insert(9);

	A.Delete(4);

	A.inorder(A.root);
	
}