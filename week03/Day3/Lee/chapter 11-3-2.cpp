// <<임시객체로의 자동 형 변환과 형 변환 연산자>>

#include <iostream>
using namespace std;

class Number {
private:
	int num;
public:
	Number(int n = 0) : num(n) {
		cout << "Number(int n = 0)" << endl;
	}
	Number& operator=(const Number& ref) {
		cout << "oparator=()" << endl;
		num = ref.num; //ref.num = Number(30)
		return *this; //num1
	}
	operator int() {
		return num;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void) {
	Number num1;
	num1 = 30;
	//num1 = Number(30);  ①임시객체의 생성
	//num1.operator = (Number(30)); ②임시객체를 대상으로 하는 대입 연산자의 호출
	Number num2 = num1 + 20;
	num2.ShowNumber();
	return 0;
}
