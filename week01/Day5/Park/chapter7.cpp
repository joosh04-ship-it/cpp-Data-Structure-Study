#include <iostream>
#include <string>
using namespace std;

class animal {
protected:
	int age;
	string name;
	void protectedIssue() {
		cout << "animal의 protected 이슈입니다\n";
	}
public:
	animal(int a, string n) : age(a),name(n){}
	void publicIssue() {
		cout << "animal의 public 이슈입니다\n";
	}
	void eating() {
		cout << "animalEating" << endl;
	}
};
class dog1 : public animal {//퍼블릭상속 : 부모의 접근 수준을 그대로 유지 : 디폴트는 퍼블릭 상속
protected:
public:
	dog1() : animal(1,"개1") {}
	void eating() {
		cout << "dogEating" << endl;
	}
	void barking() {
		cout << "dogBarking" << endl;
	}
	void PublicIssueTeller() {
		publicIssue();
		protectedIssue();
	}
};
class dog2 : protected animal {//프로텍티드상속 : 부모의 public을 protected로 수정
protected:
public:
	dog2() : animal(2, "개2") {}
	void eating() {
		cout << "dogEating" << endl;
	}
	void barking() {
		cout << "dogBarking" << endl;
	}
	void PublicIssueTeller() {
		publicIssue();
		protectedIssue();
	}
};
class dog3 : private animal {//프라이빗 상속 : 부모의 모든 멤버 함수 및 변수를 private으로 수정
protected:
public:
	dog3() : animal(3, "개3") {}
	void eating() {
		cout << "dogEating" << endl;
	}
	void barking() {
		cout << "dogBarking" << endl;
	}
	void PublicIssueTeller() {
		publicIssue();
		protectedIssue();
	}
};
class jindo2 : public dog2 {
public:
	void jindoTeller() {
		publicIssue();
	}
};
class jindo3 : public dog3 {
public:
	void jindoTeller() {
		//publicIssue();//animal의 정보를 jindo3에게 숨김 즉 부모가 할머니를 private으로 상속받으면서 손자에게 할머니의 정보 접근을 숨김
	}
};
int main()
{
//상속
	//사용 요건
		//is-a관계가 성립할 때 사용
		//has-a관계일 시 복합관계로 대체하여 사용(사용하지 않는 것이 바람직)
		//부모의 기능을 자식들이 그대로 사용할 수 있어야함
	animal Animal(1,"멍멍이");
	dog1 Dog1;
	dog2 Dog2;
	dog3 Dog3;
	Animal.eating();
	Dog1.eating();
	Dog1.barking();
	Dog1.PublicIssueTeller();
	Dog2.PublicIssueTeller();
	Dog3.PublicIssueTeller();
	Dog1.publicIssue();
	//Dog1.protectedIssue();//부모의 프로텍티드 인자는 외부에서 접근 불가
	//Dog2.PublicIssue();//부모의 퍼블릭 인자가 프로텍티드로 수정되는 프로텍티드 상속
	//Dog3.publicIssue();//부모의 퍼블릭 인자가 프라이빗으로 수정되는 프라이빗 상속
	//프라이빗상속과 프로텍티드상속의 차이점:
	//어차피 외부에서만 못쓰는 것은 똑같지만 손자에게 정보를 물려줄지의 여부를 결정할 수 있음
	//
	//자식생성자를 사용하면 부모생성자가 먼저 호출되고나서 자식이 생성됨.
	//부모의 생성자가 디폴트 생성자가 아니라면 자식생성자를 쓸 때 값을 잘 지정해줘야함
}
