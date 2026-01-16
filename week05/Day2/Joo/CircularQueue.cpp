// Queue - Circular Queue
// First In First Out
// EnQueue, DeQueue, Size, Empty 

#include <iostream>
using namespace std;

template<typename T>
class Queue {
public:
	T* data;
	int front = 0;
	int rear = 0;
	int capacity;
public:
	Queue(int size) :capacity(size <=1 ? 2 : size) {
		data = new T[capacity];
	}
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;

	void Expand() {
		if (front == (rear+1)%capacity) {
			int OldCapacity = capacity;
			capacity *= 2;
			T* cpydata = new T[capacity];
			int num = 0;
			if (front != 0) {
				for (int i = front; i < OldCapacity; i++) {
					cpydata[num] = data[i];
					num++;
				}
				for (int i = 0; i < rear; i++) {
					cpydata[num] = data[i];
					num++;
				}
			}
			else {
				for (int i = front; i < OldCapacity - 1; i++) {
					cpydata[num] = data[i];
					num++;
				}
			}
			
			delete[] data;
			data = cpydata;
			front = 0;
			rear = num;
		}
	}

	bool empty() {
		if (rear == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void EnQueue(T tmp) {
		Expand();
		data[rear] = tmp;
		rear = (rear + 1) % capacity;
	}

	T DeQueue() {
		if (empty()) {
			throw runtime_error("큐 비어있음 DeQueue 불가능");
		}
		T tmp = data[front];
		front = (front + 1) % capacity;
		return tmp;
	}

	int size() {
		return front < rear ? rear - front : capacity - front + rear;
	}

	~Queue() {
		delete[] data;
	}

	void Print() {
		int i = front;
		while (i != rear) {
			cout << data[i] << " ";
			i = (i + 1) % capacity;
		}
		cout << endl;
	}
};

int main() {
	Queue<int> q(8);
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.EnQueue(5);
	q.EnQueue(6);

	// 2) 앞에서 2개 빼서 front 이동
	q.DeQueue(); // 1 제거
	q.DeQueue(); // 2 제거

	// 현재 상태:
	// front != 0
	// 원형 구조 형성

	// 3) 다시 채워서 꽉 차게 만들기
	q.EnQueue(7);
	q.EnQueue(8);
	q.EnQueue(9);
	q.EnQueue(10);
	for (int i = 0; i < 15; i++) {
		cout << q.data[i] << endl;
	}
	cout << q.front<<endl;
	cout << q.capacity << endl;
	cout << q.size() << endl;

}