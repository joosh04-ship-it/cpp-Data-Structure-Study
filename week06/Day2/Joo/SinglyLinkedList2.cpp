// Singly Linked List
// push_front, push_back, insert, erase, find 구현

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
	LinkedList(){
		head = nullptr; 
	}

	void push_front(T data) {
		Node* newnode = new Node(data);
		newnode->next = head;
		head = newnode;
	}

	void push_back(T data) {
		if (head == nullptr) {
			head = new Node(data);
		}
		else {
			Node* cycle = head;
			while (cycle->next) {
				cycle = cycle->next;
			}
			cycle->next = new Node(data);
		}
	}	
	
	int size() {
		int num = 0;
		Node* cycle = head;
		while (cycle != NULL) {
			cycle = cycle->next;
			num++;
		}
		return num;
	}

	void insert(int num, T data) {
		if (num == 0) {
			push_front(data);
		}
		else if(num==size()){
			push_back(data);
		}
		else if (num<size()) {
			Node* cycle = head;
			for (int i = 0; i < num - 1; i++) {
				cycle = cycle->next;
			}
			Node* tmp = cycle->next;
			cycle->next = new Node(data);
			cycle->next->next = tmp;
		}
		else {
			cout << "범위가 안맞아요~";
		}
	}

	void print() {
		if (head == nullptr) {
			cout << "안됨~" << endl;
		}
		else {
			Node* cycle = head;
			while (cycle->next != NULL) {
				cout << cycle->data << endl;
				cycle = cycle->next;
			}
			cout << cycle->data << endl;
		}
	}

	int find(T data) {
		int index = 0;
		Node* cycle = head;
		while (cycle != nullptr) {
			if (cycle->data == data) {
				return index;
			}
			else {
				index++;
				cycle = cycle->next;
			}
		}
		cout << "찾는 값 없음~";
		return -1;
	}

	void erase(int num) {
		if (head == nullptr) {
			cout << "head값 없음";
			return;
		}
		if (num < 0 || num >= size()) {
			cout<<"안됨";
			return;
		}

		Node* cycle = head;
		if (num == 0) {
			Node* tmp1 = head;
			head = head->next;
			delete tmp1;
		}
		else {
			for (int i = 0; i < num - 1; i++) {
				cycle = cycle->next;
				if (cycle == nullptr) {
					cout << "연결리스트 index초과";
					return;
				}
			}
			Node* tmp = cycle->next->next;
			delete cycle->next;
			cycle->next = tmp;
		}
	}

	void clear() {
		if (head == nullptr) {
			cout << "지울게 없어요~" << endl;
		}
		else {
			Node* cycle = head;
			Node* tmp;
			while (cycle->next != NULL) {
				tmp = cycle->next;
				delete cycle;
				cycle = tmp;
				cout << "지우기~" << endl;
			}
			delete cycle;
			head = nullptr;
		}
	}
};

int main() {
	LinkedList<int> a;
	a.push_front(4);
	a.push_front(3);
	a.push_front(1);
	a.insert(1, 2);
	a.push_back(5);

	a.erase(4);

	a.print();
}