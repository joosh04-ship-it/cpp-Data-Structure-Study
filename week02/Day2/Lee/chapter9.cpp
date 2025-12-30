// <<다중상속>>

#include <iostream>
using namespace std;

class BaseOne {
public:
	void SimpleFuncOne() { cout << "BaseOne" << endl; }
	void Attack() { cout << "베이스 원 공격!" << endl; }
};

class BaseTwo {
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
	void Attack() { cout << "베이스 투 공격!" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo {
public:
	void ComplexFunc() {
		SimpleFuncOne();
		SimpleFuncTwo();
	}
	// <다중상속의 모호성>
	// "도대체 어느 클래스에 선언된 멤버에 접근 하라는거야?!"	
	//두 부모 클래스의 멤버함수가 같은 이름일 시의 해결 방법
	void DoubleAttack() {
		BaseOne::Attack();
		BaseTwo::Attack();
	}
};

int main(void) {
	MultiDerived mdr;
	mdr.ComplexFunc();
	mdr.DoubleAttack();
	return 0;
}
