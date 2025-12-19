// protected선언

#include <iostream>
using namespace std;


class Base {
private:
	int num1;
protected:
	int num2;
public:
	int num3;
	Base() : num1(1), num2(2), num3(3) {}
	void ShowData() {
		cout << num1 << num2 << num3;
	}
};

//public Base는 private를 제외한 나머지를 그대로 상속하겠다

class Derived : protected Base { //protected보다 접근의 범위가 넓은 멤버는 protected로
public:
	void ShowBaseMember() {

	}
};

//protected도 private형태로 취급
class DeDerived : private Derived {};

//이미 위 명령어로 인해 private형태가 되어서 위 상태랑 똑같음
class DeDeDerived : public DeDerived {};

int main(){
	Derived drv;
	//cout<<drv.num3 -> protected상속으로 인해 컴파일 에러
}