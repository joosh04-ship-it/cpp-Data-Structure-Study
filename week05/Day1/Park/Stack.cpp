#include <iostream>
using namespace std;
template <class T>
class stack {
private:
	T *data;
	int idx = 0;
	int size;
public:
	stack(int size): size(size){
		if (size <= 0) {
			cout << "size는 자연수입니다 ㅎㅎ 1로 바꿔드림 ㅎㅎ" << endl;
			size = 1;
			this->size = 1;
		}
		data = new T[size];
	}
	stack(const stack& other) : size(other.size), idx(other.idx) {
		data = new T[size];
		for (int i = 0; i < idx; i++) {
			data[i] = other.data[i];
		}
	}
	stack& operator=(const stack& other) {
		if (this == &other) return *this; 

		T* newData = new T[other.size];   
		for (int i = 0; i < other.idx; i++) {
			newData[i] = other.data[i];   
		}

		delete[] data;                    
		data = newData;                   
		size = other.size;
		idx = other.idx;

		return *this;
	}
	void DynamicStack() {
		if (idx >= size) {
			size *= 2;
			T* newData = new T[size];
			for (int i = 0; i < idx; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
	}
	void push(T val) {
		DynamicStack();
		data[idx] = val;
		idx++;
	}
	bool empty() const {
		if (idx == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	T pop() {
		if (empty()) {
			cout << "스택이 비어있어서 pop 불가능" << endl;
			return T();
		}
		return data[--idx];
	}
	T top() const {
		if (empty()) {
			cout << "스택이 비어있어서 top 불가능" << endl;
			return T();
		}
		return data[idx-1];
	}
	int checkSize() const {
		return idx;
	}
	~stack(){
		delete[] data;
	}
};

int main()
{
}