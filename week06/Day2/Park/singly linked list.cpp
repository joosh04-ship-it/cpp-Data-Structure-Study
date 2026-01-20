#include <iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next;
public:
	Node(T data): data(data){
		next = nullptr;
	}
	Node(){
		data = T();
		next = nullptr;
	}
};

template <class T>
class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList() {
		head = nullptr;
	}
	void pushBack(T newData) {
		if (head == nullptr) {
			head = new Node<T>(newData);
			return;
		}
		Node<T>* node = head;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node<T>(newData);
	}
	void pushFront(T newData) {
		Node<T>* newNode = new Node<T>(newData);
		Node<T>* tmpNode = head;
		head = newNode;
		head->next = tmpNode;
	}
	void insert(int idx, T newData) {
		if (idx < 0) {
			cout << "인덱스가 너무 작아서 인서트 불가" << endl;
			return;
		}
		if (idx == 0) {
			pushFront(newData);
			return;
		}
		Node<T>* node = head;
		for (int i = 0; i < idx-1; i++) {
			if (node->next == nullptr) {
				cout << "인덱스가 너무커서 인서트 불가" << endl;
				return;
			}
			node = node->next;
		}
		Node<T>* newNode = new Node<T>(newData);
		Node<T>* tmpNode = node->next;
		node->next = newNode;
		node->next->next = tmpNode;
	}
	int find(T checkData) {
		Node<T>* node = head;
		int idx = 0;
		while (node != nullptr) {
			if (node->data == checkData) {
				return idx;
			}
			node = node->next;
			idx++;
		}
		return -1;
	}

	void popFront() {
		if (head==nullptr) {
			cout << "pop할거 없음" << endl;
			return;
		}
		Node<T>* tmp = head->next;
		delete head;
		head = tmp;
	}
	void erase(int idx) {
		if (idx < 0) {
			cout << "0번 미만 인덱스라 이레이즈 불가" << endl;
			return;
		}
		if (idx == 0) {
			popFront();
			return;
		}
		Node<T>* node = head;
		for (int i = 0; i < idx - 1; i++) {
			if (node->next == nullptr) {
				cout << "인덱스가 너무 커서 이레이즈 불가" << endl;
				return;
			}
			node = node->next;
		}
		if (node->next == nullptr) {
			cout << "삭제할 노드 없음" << endl;
			return;
		}
		Node<T>* tmp = node->next->next;
		delete node->next;
		node->next = tmp;
	}
	int size() {
		Node<T>* node = head;
		if (head == nullptr) {
			return 0;
		}
		int cnt = 1;
		while (node->next != nullptr) {
			node = node->next;
			cnt++;
		}
		return cnt;
	}
	void print() {
		if (head == nullptr) {
			return;
		}
		Node<T>* node = head;
		while (node->next) {
			cout << node->data << endl;
			node = node->next;
		}
		cout << node->data << endl;
	}
	void clear() {
		Node<T>* node = head;
		while (node != nullptr) {
			Node<T>* tmp = node;
			node = node->next;
			delete tmp;
		}
	}
	~LinkedList(){
		clear();
	}
};

int main()
{
	LinkedList<int> *head = new LinkedList<int>;
	head->pushBack(1);
	head->pushBack(2);
	head->pushFront(0);
	head->pushFront(-1);
	head->insert(4, 100);
	head->erase(1);
	cout << head->find(100)<<endl;
	head->print();
	cout << head->size() << endl;
	delete head;
}
