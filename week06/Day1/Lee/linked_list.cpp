#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
    T data;
    LinkedList* next;
public:
    LinkedList(T data) : data(data) { next = nullptr; }
    void push_back(T data) {
        LinkedList* node = this;
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = new LinkedList(data);
    }

    void print() {
        LinkedList* node = this;
        while (node->next != nullptr) {
            node = node->next;
            cout << node->data << endl;
            
        }
    }

    void push_front(T data) {
        LinkedList* node = this;
        LinkedList* newNode = new LinkedList(data);
        newNode->next = node->next;
        node->next = newNode;
    }

    void insert(int position, T data) {
        LinkedList* node = this;
        for (int i = 1; i < position; i++) {
            node = node->next;
        }
        LinkedList* newNode = new LinkedList(data);
        newNode->next = node->next;
        node->next = newNode;
    }

    void find(T data) {
        LinkedList* node = this;
        int cnt = 1;
        node = node->next;
        while (node->data != data) {
            node = node->next;
            cnt += 1;
        }
        cout << data << "는 현재 " << cnt << "번째에 있습니다!" << endl;
    }

    void erase(int position) {
        if (position <= 0) {
            cout << "인덱스를 0이하로 작성할 수 없습니다!" << endl;
            return;
        }

        LinkedList* node = this;
        
        
        for (int i = 1; i < position; i++) {
            if (node->next == nullptr) {
                cout << "인덱스가 너무 커서 지우기 불가능!" << endl;
                return;
            }
            node = node->next;
        }

        if (node->next == nullptr) {
            return;
        }

        LinkedList* node2 = node->next;
        node->next = node->next->next;
        delete node2;
    }

    void size() {
        LinkedList* node = this;
        int cnt = 1;
        node = node->next;
        while (node->next != nullptr) {
            node = node->next;
            cnt += 1;
        }
        cout <<"연결리스트의 크기는 현재 " << cnt << "입니다!" << endl;
    }

    void clear() {

        LinkedList* node = this->next;
        
        while (node != nullptr) {
            LinkedList* node2 = node->next;
            delete node;
            node = node2;
            
        }
        
        this->next = nullptr;
    }
};



int main()
{
    LinkedList<int>* head = new LinkedList(0);
    head->push_back(2);
    head->push_back(3);
    head->push_front(1);
    head->push_front(5);
    head->insert(2, 8);
    head->insert(1, 100);
    head->find(3);
    head->print();
    head->erase(1);
    cout << endl;
    cout << "--erase 후--" << endl;
    head->find(1);
    head->erase(-1);
    head->erase(100);
    head->size();
    head->print();
    cout << "--clear 후--" << endl;
    head->clear();
    
    head->print();

}


