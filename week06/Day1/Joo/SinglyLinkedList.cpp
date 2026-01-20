// Singly Linked List
// push_front, push_back, insert, erase, find ±¸Çö

#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* next;
		Node(T data) :data(data), next(nullptr) {};
	};

	Node* head;

public:
	LinkedList()

	void push_front(T data) {
		Node* newnode = new Node(data);
		newnode->next = head;
		head = newnode;
	}

	void push_back(T data) {
		while (head) {
			head = head->next;
		}
		head->next = new Node(data);
	}
};