#include <iostream>

using namespace std;

class parent {
public:
	parent() {
		cout << "부모생성" << endl;
	}
	virtual ~parent() {
		cout << "부모 삭제" << endl;
	}
};

class leftHand :public parent {
public:
	leftHand() { 
		cout << "왼손생성" << endl; 
	}
	virtual ~leftHand() {
		cout << "왼손절단" << endl;
	}
	void shake() {
		cout << "왼손흔들기" << endl;
	}
};

class rightHand : public parent {
public:
	rightHand() {
		cout << "오른손생성" << endl;
	}
	virtual ~rightHand() {
		cout << "오른손절단" << endl;
	}
	void shake() {
		cout << "오른손흔들기" << endl;
	}
};

class Hand : virtual public leftHand, virtual public rightHand {
public:
	Hand() {
		cout << "양손생성" << endl;
	}
	virtual ~Hand() {
		cout << "양손절단" << endl;
	}
};

int main()
{
//멤버함수
	//객체마다 존재하는 것이 아니고, 메모리의 특정 부분에 존재
	//객체 내에는 주소의 값으로 존재
//가상함수의 동작 원리
	//가상함수가 포함된 각 class는 가상함수 테이블을 가지고, 멤버함수가 호출될 때 가상함수테이블에서 참조하여 호출될 함수를 결정하는 방식이다.

//다중 상속
	//한 클래스가 상속을 두개 이상 받는 것
	//모호하기 때문에 가능한 사용하지 않을 것
	leftHand *l = new leftHand;
	rightHand *r = new rightHand;
	Hand* h= new Hand;
	//h->shake();모호함
	h->leftHand::shake();
	//추가로 다이아몬드 다중상속에서 문제를 발생시키지 않으려면 가상상속을 해야함.
	delete l;
	delete r;
	delete h;
}
