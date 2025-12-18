//복사 생성자 호출 위치

#include <iostream>
using namespace std;

class SoSimple {
private:
	int num1;
public:
	SoSimple(int n1) : num1(n1) {}
	SoSimple(const SoSimple& copy) : num1(copy.num1) {
		cout << "복사완료!" << endl;
	}
	void ShowData() const {
		cout << "num1: " << num1 << endl;
	}
	SoSimple& AddNum(int n) {
		num1 += n;
		return *this;
	}
	~SoSimple() {
		cout << "Destructor called:" <<num1 << endl;
	}
	

};
//복사 생성자 호출은 함수의 (1)매개변수로 객체가 전달될 때와 (2)함수가 객체를 반환할 때 발생
SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "함수 중간"<< endl;
	return ob;
}

int main() {
	SoSimple obj1(7);
	cout << "함수 호출 전" << endl;
	SimpleFuncObj(obj1).AddNum(5).ShowData(); 
	cout << "함수 호출 후" << endl;
	const SoSimple& refObj = SoSimple(23423);
	cout << "int main의 끝" << endl;
	return 0;
}
