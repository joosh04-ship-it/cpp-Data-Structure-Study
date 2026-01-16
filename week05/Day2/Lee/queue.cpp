// queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T* data;
    int front = 0;
    int rear = 0;
    int capacity;
public:
    Queue(int sz) : front(0), rear(0), capacity(sz <= 0 ? 2 : sz + 1) {
        if (sz <= 0) {
            cout << "capacity가 0이하는 에바여서 2로 바꿔줌 ㅎㅎ" << endl;
        }
        data = new T[capacity];
    }

    bool Empty() const {
        return front == rear;
    }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    void Expand() {
        if ((rear + 1) % capacity == front) {
            int oldCap = capacity;
            capacity *= 2;
            T* cpydata = new T[capacity];
            int num = 0;
            for (int i = front; i != rear; i = (i+1) % oldCap) {
                cpydata[num] = data[i];
                num++;
                
            }

            front = 0;
            rear = num;

            delete[] data;
            data = cpydata;
        }
    }

    void Enqueue(T val) {
        Expand();
        data[rear] = val;
        rear = (rear + 1) % capacity;
    }
    T Dequeue() {
        if (Empty()) {
            cout << "비어있따. 끄지라" << endl;
            return T();
        }

        T res = data[front];
        front = (front + 1) % capacity;
        return res;
    }

    int checksize() const {
        return (rear - front + capacity) % capacity;
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue<int> q(3);   // 내부 capacity = 4 (한 칸 비움)

    cout << "=== Enqueue 1 ~ 6 ===\n";
    for (int i = 1; i <= 6; i++) {
        q.Enqueue(i);
        cout << "push " << i
            << " | size = " << q.checksize() << '\n';
    }

    cout << "\n=== Dequeue 3 ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "pop " << q.Dequeue()
            << " | size = " << q.checksize() << '\n';
    }

    cout << "\n=== Enqueue 7 ~ 10 ===\n";
    for (int i = 7; i <= 10; i++) {
        q.Enqueue(i);
        cout << "push " << i
            << " | size = " << q.checksize() << '\n';
    }

    cout << "\n=== Dequeue all ===\n";
    while (!q.Empty()) {
        cout << q.Dequeue() << ' ';
    }
    cout << "\n";

    return 0;
}





