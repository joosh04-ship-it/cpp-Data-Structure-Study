#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(T data) : data(data), next(nullptr) {}

};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        clear();
        
    }

    void push_back(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* val = head;
            while (val->next != nullptr) {
                val = val->next;
            }
            val->next = new Node<T>(data);
        }
        
        
    }

    void push_front(T data) {
        
        Node<T>* newval = new Node<T>(data);
        newval->next = head;
        head = newval;
    }

    void insert(int position, T data) {
        if (position < 0) {
            cout << "인덱스 값이 0 미만일 순 없습니다!" << endl;
            return;
        }
        Node<T>* val = head;
        if (position == 0) {
            push_front(data);
            return;
        }
        else {
            for (int i = 1; i < position; i++) {
                if (val->next == nullptr) {
                    cout << "범위를 초과한 인덱스 값입니다!" << endl;
                    return;
                }
                val = val->next;
            }
            Node<T>* newval = new Node<T>(data);
            newval->next = val->next;
            val->next = newval;
        }
        
        
    }

    int find(T data) {
        Node<T>* val = head;
        int cnt = 0;
        while (val != nullptr) {
            if (val->data == data) {
                cout << data << "는 현재 " << cnt << "번째에 있습니다!" << endl;
                return cnt;
            }
            val = val->next;
            cnt += 1;
        }
        std::cout << data << "가 없습니다!" << std::endl;
        return -1;
        
    
    }
    void erase(int position) {
        if (position < 0) {
            cout << "인덱스를 0미만으로 작성할 수 없습니다!" << endl;
            return;
        }

        Node<T>* val = head;

        if (position == 0) {
            Node<T>* val2 = val->next;
            delete head;
            head = val2;
        }
        else {
            for (int i = 1; i < position; i++) {
                if (val->next == nullptr) {
                    cout << "인덱스가 너무 커서 지우기 불가능!" << endl;
                    return;
                }
                val = val->next;
            }
            if (val->next == nullptr) {
                cout << "인덱스가 너무 커서 지우기 불가능!" << endl;
                return;
            }
            Node<T>* val2 = val->next;
            val->next = val->next->next;
            delete val2;
        }
        
    }

    void size() {
        Node<T>* val = head;
        int cnt = 0;
        
        while (val != nullptr) {
            cnt += 1;
            val = val->next;   
        }
        cout << "연결리스트의 크기는 현재 " << cnt << "입니다!" << endl;
    
    }

    void clear() {
        Node<T>* val = head;

        while (val != nullptr) {
            Node<T>* val2 = val->next;
            delete val;
            val = val2;
        }
        head = nullptr;
    }

    void print() {
        Node<T>* val = head;
        while (val!= nullptr) {
            cout << val->data << endl;
            val = val->next;
            
        }
    }
};

int main() {
    LinkedList<int> list;

    cout << "=== push_back 테스트 ===" << endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.print();   // 10 20 30

    cout << "\n=== push_front 테스트 ===" << endl;
    list.push_front(5);
    list.print();   // 5 10 20 30

    cout << "\n=== insert 테스트 (position = 3, value = 25) ===" << endl;
    list.insert(3, 25);
    list.print();   // 5 10 20 25 30

    cout << "\n=== find 테스트 ===" << endl;
    list.find(5);  // 위치 출력

    cout << "\n=== size 테스트 ===" << endl;
    list.size();    // 크기 출력

    cout << "\n=== erase 테스트 (position = 0) ===" << endl;
    list.erase(0);
    list.print();   // 10 20 25 30

    cout << "\n=== erase 범위 초과 테스트 ===" << endl;
    list.erase(100);

    cout << "\n=== clear 테스트 ===" << endl;
    list.clear();
    list.print();   // 아무것도 출력 안 됨

    cout << "\n=== 프로그램 종료 ===" << endl;
    return 0;
}


