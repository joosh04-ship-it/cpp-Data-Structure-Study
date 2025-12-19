#include <iostream>

using namespace std;

class simple {
private:
	int num1;
protected:
	int num2;
public:
	int num3;
};

class simple2 : public simple {			//public 상속, private를 제외한 나머지를 그대로 상속 (대부분 public 상속 사용)
public:
	void shownum() {
		/*cout << num1; */		// 자식클래스에서 부모클래스의 private에 접근 불가능
		cout << num2;			
		cout << num3;			// 자식클래스에서 부모클래스의 protacted,public 접근 가능
	}
};

class simple3 : protected simple {		// protected 상속, public 멤버를 protected로 변경시켜서 상속

};

class simple4 : private simple {		// private 상속, public,protected 멤버를 private로 변경시켜서 상속

};

// 상속은 IS A 관계에서만 사용하는게 좋음 ex) dog is an animal. 
//		-> class animal{};  class dog : public animal{};
// Has a 관계에서는 되도록이면 사용 X, 포함을 사용하도록 한다. ex)car has an engine.
//		-> class engine{};	class car{ engine Engine};