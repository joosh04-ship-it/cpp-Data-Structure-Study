// stack
// 후입선출의 방식으로 동작하는 선형 자료구조(LIFO, Last In First Out)
// 마지막에 들어온 데이터가 가장 먼저 나간다.ex) 되돌리기 등..

#include <iostream>
using namespace std;

template<typename T>
class Stack {
public:
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;

	T *data;
	int idx = 0;
	int size;

	Stack(int size) :size(size) {
		if (size <= 0) {
			cout << "size는 0이하 일 수 없음" << endl;
			size = 1;
			this->size = 1;
		}
		data = new T[size];
	}

	void DynStack() {
		if (idx < size) {
			return;
		}
		size = size * 2;
		T *cpydata = new T[size];
		for (int i = 0; i < idx; i++) {
			cpydata[i] = data[i];
		}
		delete[] data;
		data = cpydata;
	}

	void push(T val) {
		DynStack();
		data[idx++] = val;
	}

	bool empty() const{
		if (idx == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	T pop() {
		if (empty()){
			throw runtime_error("스택 비어있음 pop 불가능");

		}
		return data[--idx];
	}

	T top() const{
		if (empty()) {
			throw runtime_error("스택 비어있음 top 불가능");

		}
		return data[idx - 1];
	}

	int CheckSize() const{
		return size;
	}
	
	~Stack() {
		delete[] data;
	}
};

int main() {

}