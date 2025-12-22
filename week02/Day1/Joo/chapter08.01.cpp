#include <iostream>

using namespace std;

class animal {
public:
	void Print() { 
		cout << "PTR" << endl; }
	virtual void vir() {
		cout << "Iamanimal" << endl;
	}
};

class dog : public animal {
public:
	void sound() {
		cout << "wal wal" << endl;
	}
	void vir() {							// 별도의 가상함수 선언 없이도, 부모클래스의 가상함수를 상속하여
		cout << "iamdog" << endl;			// 가상함수로 선언됨
	}
};

class breed : public dog {
public:
	void sound() {
		cout << "wang wang" << endl;
	}
	virtual void vir() {
		cout << "iambreed" << endl;
	}
};

class breedvir : public dog {
	void sound() {
		cout << "wang wang " << endl;
	}
};

int main() {
	animal* ptr = new animal();		
	animal* ptr1 = new dog();		// 부모클래스형 포인터 변수는 자식클래스 객체도 가리킬 수 있음
	animal* ptr2 = new breed();		// 자식클래스를 상속하는 클래스의 객체도 가리킬 수 있음
	//breed* ptr3 = ptr1; 컴파일 오류 ( 컴파일러가 ptr2가 animal형 객체라고 인식)
	animal* ptr3 = ptr;				// 가능 -> 포인터 형에 해당하는 클래스에 정의된 멤버에만 접근 가능

	animal* vptr = new animal();
	animal* vptr1 = new dog();
	animal* vptr2 = new breed();

	dog choco;
	breed chiwawa;

	ptr1->Print();
	ptr2->Print();

	chiwawa.sound();				// 함수오버라이딩으로 인해 자식클래스의 함수를 호출

	chiwawa.dog::sound();			// chiwawa 객체의 dog 클래스에 정의된 sound 함수 호출

	vptr1->vir();					// virtual 함수이므로, 부모 타입 포인터로 호출해도
	vptr2->vir();					// 실제 객체 타입(breed)의 vir()가 실행됨			
}


//virtual 사용 이유 : 새 클래스를 추가해도 main(또는 공통 처리 코드)을 안 고치기 위해서