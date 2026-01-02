#include <iostream>

using namespace std;

class number {
	int num;
	int num1;
public:
	number(int n) :num(n) {
		
	}
	number(int n,int n1):num(n),num1(n1){}
	number* operator ->() {
		return this;
	}
	number& operator *() {
		return *this;
	}
	void showdata() {
		cout << num << "," << num1 << endl;
	}

	~number() {
		cout << "소멸~" << endl;
	}
};

class smartptr {								// 스마트 포인터
	number* numptr;
public:
	smartptr(number *ptr):numptr(ptr){}

	number* operator ->() {
		return numptr;
	}
	number& operator *() {
		return *numptr;
	}
	~smartptr() {
		delete numptr;							// number객체 소멸
	}
};

int main() {
	number num(30);
	num.showdata();

	(*num) = 20;
	num->showdata();
	
	smartptr p(new number(30,20));				// new로 만들어도 smartptr에 의해 자동 소멸 가능
	p->showdata();

	(*p) = 20;
	p->showdata();
}