
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <class T>
class Node {
public:
    T value;
    Node<T>*left = nullptr;
    Node<T>*right = nullptr;
public:
    Node(T val) : value(val) {}

};

template <class T>
class Tree {
public:
    Node<T> *root = nullptr;
    void preOrder(Node<T>* node) {
        
        cout << node->value << endl;
        if (node->left)
        preOrder(node->left);
        if (node->right)
        preOrder(node->right);
    }
    void inOrder(Node<T>* node) {
        
        if (node->left)
            inOrder(node->left);
        cout << node->value << endl;
        if (node->right)
            inOrder(node->right);
    }
    void inOrder() {
        inOrder(root);
    }
    void postOrder(Node<T>* node) {
        if (node->left)
            postOrder(node->left);
        if (node->right)
            postOrder(node->right);
        cout << node->value << endl;
    }

    void insert(T value) {
        if (root == nullptr) {
            root = new Node<T>(value);
            return;
        }
        Node<T>* copy = root;
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
                else { copy = copy->right; }
            }
        }
    }
    

    Node<T>* find(T value) {
        Node<T>* copy = root;
        if (root == nullptr) { 
            cout << "값이 없는데 무엇을 찾으리..." << endl; 
            return nullptr; }

        while (copy != nullptr) {
            if (value < copy->value) {
                copy = copy->left;
            }
            else if (value > copy->value) {
                copy = copy->right;
            }
            else {
                cout << "Find it!" << endl;
                return copy;
            }
        }

        cout << "값이 없당께" << endl;
        return nullptr;
    }

    Node<T>* Pfind(T value) {
        Node<T>* copy = root;
        Node<T>* parent = nullptr;
        if (root == nullptr) {
            cout << "값이 없는데 무엇을 찾으리..." << endl;
            return nullptr;
        }

        while (copy != nullptr) {
            if (value < copy->value) {
                parent = copy;
                copy = copy->left;
            }
            else if (value > copy->value) {
                parent = copy;
                copy = copy->right;
            }
            else {
                
                return parent;
            }
        }

        
        return nullptr;
    }




    void Delete(T value) {
        
        Node<T>* pointer = find(value);
        Node<T>* parent = Pfind(value);
        bool isLeft = (parent->value > pointer->value);
        if (pointer != nullptr) {
            if (pointer->left == nullptr && pointer->right == nullptr) {
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
                Node<T>* copy;
                pointer = pointer->right;
                while (pointer->left) {
                    copy = pointer;
                    pointer = pointer->left;
                }
                copy->left = nullptr;
                if (isLeft) {
                    pointer->right = parent->left->right;
                    pointer->right = parent->left->left;
                    delete parent->left;
                    parent->left = pointer;
                }
                else {
                    pointer->right = parent->right->right;
                    pointer->right = parent->right->left;
                    delete parent->right;
                    parent->right = pointer;
                }
            }
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
    A.inOrder();
}


