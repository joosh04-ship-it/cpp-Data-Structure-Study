#include <iostream>
using namespace std;

template<class T>
class linkedList {
private:
	T data;
	linkedList* next;
public:
	linkedList(T data):data(data){
		next = nullptr;
	}
	void pushBack(T newData) {
		linkedList* node = this;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new linkedList(newData);
	}
	void pushFront(T newData) {
		linkedList* newNode = new linkedList(newData);
		linkedList* tmpNode = this->next;
		this->next = newNode;
		this->next->next = tmpNode;
	}
	void insert(int idx, T newData) {
		if (idx <= 0) {
			cout << "인덱스가 너무 작아서 인서트 불가" << endl;
			return;
		}
		if (idx == 1) {
			pushFront(newData);
			return;
		}
		linkedList* node = this;
		for (int i = 0; i < idx-1; i++) {
			if (node->next == nullptr) {
				cout << "인덱스가 너무커서 인서트 불가"<<endl;
				return;
			}
			node = node->next;
		}
		linkedList* newNode = new linkedList(newData);
		linkedList* tmpNode = node->next;
		node->next = newNode;
		node->next->next = tmpNode;
	}
	int find(T checkData) {
		linkedList* node = this;
		int cnt = 0;
		while (node->next != nullptr) {
			node = node->next;
			cnt++;
			if (node->data == checkData) {
				return cnt;
			}
		}
		return -1;
	}
	void erase(int idx) {
		if (idx <= 0) {
			cout << "0번 이하 인덱스라 이레이즈 불가" << endl;
			return;
		}
		linkedList* node = this;
		for (int i = 0; i < idx-1;i++) {
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
		linkedList* tmp = node->next->next;
		delete node->next;
		node->next = tmp;

	}
	int size() {
		linkedList* node = this;
		int cnt = 0;
		while (node->next != nullptr) {
			node = node->next;
			cnt++;
		}
		return cnt;
	}
	void print() {
		linkedList* node = this;
		while (node->next != NULL) {
			node = node->next;
			cout << node->data << endl;
		}
	}
	void clear() {
		linkedList* node = this->next;
		while (node != nullptr) {
			linkedList* tmp = node;
			node = node->next;
			delete tmp;
		}
		this->next = nullptr;
	}

	~linkedList() {

	}
};

int main()
{
	linkedList<int> *head = new linkedList<int>(0);
	head->pushBack(1);
	head->pushBack(2);
	head->pushFront(0);
	head->pushFront(-1);
	head->insert(5, 100);
	head->erase(1);
	cout << head->find(100)<<endl;
	head->print();
	cout << head->size() << endl;
	head->clear();
}
