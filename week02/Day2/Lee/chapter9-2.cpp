//  <<가상 상속>>
#include <iostream>
using namespace std;

class Base {
public:
	Base() { cout << "Base Constructor!" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base {
public:
	MiddleDerivedOne() : Base() {
		cout << "MiddleDerivedOne Constructor!" << endl;
	}
	void MiddleFuncOne() {
		SimpleFunc();
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base {
public:
	MiddleDerivedTwo() : Base() {
		cout << "MiddleDerivedTwo Constructor!" << endl;
	}
	void MiddleFuncTwo() {
		SimpleFunc();
		cout << "MiddleDerivedTwo" << endl;
	}
};
//아래 클래스에 조상 클래스는 하나만 존재
class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo {
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo() {
		cout << "LastDerived Constructor!!" << endl;
	}
	void ComplexFunc() {
		MiddleFuncOne();
		MiddleFuncTwo();
		//가상 상속을 하지 않으면 컴파일 에러
		//"어느 조상 객체의 멤버인거야?!"
		SimpleFunc();
	}
};

int main(void) {
	cout << "객체 생성 전...." << endl;
	LastDerived ldr;
	cout << "객체 생성 후...." << endl;
	ldr.ComplexFunc();
	return 0;
}
