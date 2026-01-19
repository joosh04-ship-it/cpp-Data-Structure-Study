// Singly Linked List
// push_front, push_back, insert, erase, find 구현

#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

template<typename T>
class LinkedList {
public:
	T data;
	LinkedList* next;

public:
	LinkedList(T data):data(data){
		next = NULL;
	}
	
	void push_back(LinkedList* &head,T data) {
		while (head) {
			head = head->next;
		}
		head->next = new LinkedList(data);
	}

	void print() {
		LinkedList* node = this;
		while (node->next != NULL) {
			cout << node->data << endl;
			node = node->next;
		}
		cout << node->data<<endl;
	}

	static void push_front(LinkedList* &head,T data) {
		LinkedList* newnode = new LinkedList(data);
		newnode->next = head;
		head= newnode;
	}

	void insert(int num, T data) {
		LinkedList* node = this;
		for (int i = 0;i<num-2;i++) {
			node = node->next;
		}
		LinkedList* tmp = node->next;	
		node->next = new LinkedList(data);
		node->next->next = tmp;
	}

	int find(T data) {
		LinkedList* node = this;
		int index = 1;
		while (index != data) {
			node = node->next;
			index++;
		}
		return index;
	}

	void erase(int num) {
		LinkedList* node = this;
		if (num == 1) {
			
		}
		for (int i = 0; i < num-2; i++) {
			node = node->next;
			if (node == NULL) {
				cout << "연결리스트 index초과";
			}
		}
		LinkedList* tmp = node->next->next;
		delete node->next;
		node->next = tmp;
	}

	int size() {
		LinkedList* node = this;
		int num=0;
		while (node != NULL) {
			node = node->next;
			num++;
		}
		return num;
	}

	void clear() {
		LinkedList* node = this->next;
		LinkedList* tmp;
		while (node->next != NULL) {
			tmp = node->next;
			delete node;
			node = tmp;
			cout << "지우기~" << endl;
		}
		delete node;
		delete this;
	}
};


int main() {
	LinkedList<int>* head = nullptr;
	head->push_back(head,2);
	head->push_back(head, 3);

	head->print();
}
