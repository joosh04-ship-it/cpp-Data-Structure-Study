#include <iostream>

using namespace std;

class life {

};
class human : public life{

};
class A{
public:
	virtual void f() {
		cout << "원본" << endl;
	}//퍼블릭에 버츄얼 함수 선언
	virtual ~A() {
		cout << "소멸자는 항상 가상함수로 만들자. 안그러면 이렇게 호출이 안됨" << endl;
	}
};
class B : public A {
public:
	void f() override {//뒤에 오버라이드는 생략 가능하지만 안하는 것이 바람직
		cout << "버츄얼오버라이드" << endl;//동적 바인딩
	}
	virtual ~B() {
		cout << "소멸자는 항상 가상함수로 만들자. 안그러면 이렇게 호출이 안됨" << endl;
	}
};
class A1 {
public:
	void f() {
		cout << "원본" << endl;
	}//퍼블릭에 버츄얼 함수 선언
	virtual ~A1() = default;// 가상 소멸자를 하고싶은데 특별한 정의를 넣지는 않을 계획일 때
};
class B1 : public A1 {
public:
	void f(){
		cout << "일반오버라이드" << endl;//정적바인딩
	}
	virtual ~B1() {
		cout << "소멸자는 항상 가상함수로 만들자." << endl;
	}
};
int main()
{
	//human* PJ = new life(); 이건 안됨. 더 자세한 것에 더 큰 범위를 넣을 수 없음
	life* JS = new human();
	//가상 함수
	A* a = new A();
	A* b = new B();
	a->f();
	b->f();
	A1* a1 = new A1();
	A1* b1 = new B1();
	a1->f();
	b1->f();
	B1 a123;
	A1& refA = a123;//레퍼런스로도 자식클래스를 받을 수 있음
	delete b;//소멸자 호출이 안되는 모습
	delete b1;
}
