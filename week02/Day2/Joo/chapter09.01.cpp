#include <iostream>

using namespace std;

class sim1 {
public:
	void simplefunc() {
		cout << "sim1" << endl;
	}
};

class sim2 {
public:
	void simplefunc() {
		cout << "sim2" << endl;
	}
};

class MultiDerived : public sim1, protected sim2 {		// 다중상속
public:
	void complexfunc() {
		sim1::simplefunc();		// 다중 상속받은 부모클래스의 함수 이름이 같을 경우
		sim2::simplefunc();		// 모호성을 해결해줘야함
	}
};

class base {
public:
	void simplefunc() {
		cout << "simple!" << endl;
	}
};

class derived1:public base {
public:
	void func1(){
		cout << "func1!" << endl;
	}
};

class derived2 :public base {
public:
	void func2() {
		cout << "func2!" << endl;
	}
};

class last : public derived1, public derived2{
public:
	void complex() {
		func1();
		func2();
		derived1::simplefunc();			// base 클래스가 last 클래스에 두번 상속되기 때문에,
		derived2::simplefunc();			// derived1,2 중간 상속 클래스 중 하나를 골라 모호성을 해결 시켜야함
	}
};

class virbase {
public:
	void simplefunc() {
		cout << "simple!" << endl;
	}
};

class virderived1 : virtual public virbase {	// virtual 상속
public:
	void func1() {
		cout << "func1!" << endl;
	}
};

class virderived2 : virtual public virbase {
public:
	void func2() {
		cout << "func2!" << endl;
	}
};

class virlast : public virderived1, public virderived2 {
public:
	void complex() {
		func1();
		func2();
		simplefunc();			// virtual 상속을 이용해 중간 클래스가 하나의 부모 클래스를 상속하게 해,
	}							// 모호성 해결
};