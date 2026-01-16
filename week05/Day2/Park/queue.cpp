#include <iostream>
using namespace std;

template<class T>
class Queue {
public:
	T* data;
	int front = 0;
	int rear = 0;
	int capacity;
public:
	Queue(int capacity) : capacity(capacity <= 1 ? 2 : capacity) {
		if (capacity <= 0) {
			cout << "capacity는 0일 수 없어서 2로 함" << endl;
		}
		data = new T[capacity];
	}
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;

	void expand() {
		if ((front == 0 && rear == capacity - 1) || front - 1 == rear) {
			capacity *= 2;
			T* newData = new T[capacity];
			for (int i = front; i < capacity / 2 + front; i++) {
				newData[i - front] = data[i < capacity / 2 ? i : i - capacity / 2];
			}

			front = 0;
			rear = capacity / 2 -1;
			delete[] data;
			data = newData;
		}
	}

	void enqueue(T val) {
		expand();
		data[rear] = val;
		rear = rear == capacity - 1 ? 0 : rear+1;
	}
	bool empty() {
		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}
	T dequeue() {
		if (empty()) {
			cout << "비어있어서 dequeue불가능" << endl;
			return T();
		}
		T r;
		if (front == capacity - 1){
			r = data[front];
			front = 0;
		}
		else {
			r = data[front];
			front++;
		}
		return r;
	}
	int size() {
		return front <= rear ? rear - front : capacity + rear - front;
	}
	~Queue(){
		delete[] data;
	}
};

int main()
{
	Queue<int> q(2);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();   // 1 제거
	q.enqueue(4);
	q.enqueue(5); // expand 발생

	cout << q.dequeue() << endl; // 기대: 2
	cout << q.dequeue() << endl; // 기대: 3
	cout << q.dequeue() << endl; // 기대: 4
	cout << q.dequeue() << endl; // 기대: 5
}
