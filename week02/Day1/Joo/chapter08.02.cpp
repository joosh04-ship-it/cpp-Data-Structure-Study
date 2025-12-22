#include <iostream>

using namespace std;

class animal {							// animal 객체는 생성시키지 않을 것. -> animal class는 추상 class
public:
	virtual void vir() =  0;			// 순수가상함수, 자식클래스의 객체를 생성하기 위해서는 자클래스에서 vir()을 반드시 정의해줘야함

	virtual ~animal() {					// 가상소멸자( 메모리 누수 방지)

	}
};

class dog : public animal {
public:
	void sound() {
		cout << "wal wal" << endl;
	}
	virtual void vir() {
		cout << "iamdog" << endl;
	}
	~dog(){								// 부모클래스의 소멸자가 가상소멸자면, 자식클래스의 소멸자도 자동으로 가상 소멸자로 선언
	}
};

class breed : public dog {
public:
	void sound() {
		cout << "wang wang" << endl;
	}
	virtual void vir() override{		// override를 적어줘 코드에 명시적으로 표현
		cout << "iambreed" << endl;
	}
	~breed(){
	}
};

class breedvir : public dog {
	void sound() {
		cout << "wang wang " << endl;
	}
};

int main() {
	animal* vptr1 = new dog();
	animal* vptr2 = new breed();	

	animal* ptr = new dog();
	ptr->vir();
	delete ptr;

	ptr = new breed();
	ptr->vir();					// 같은 ptr->vir(); 호출이지만, 객체 자료형이 달라 다른 결과 출력 ( C++에서의 다향성)
	delete ptr;

	breed poodle;
	animal& ref = poodle;
	ref.vir();					// 참조형도 동일하게 작용
}