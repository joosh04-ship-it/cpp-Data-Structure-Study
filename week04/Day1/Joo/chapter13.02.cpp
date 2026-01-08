#include <iostream>

using namespace std;

template <class T>				//class 템플릿
class simple {
	T num1;
	T num2;
public:
	simple(T n1, T n2) :num1(n1), num2(n2){}
	void showposition();
};

template <class Ts>						//class 외부에 함수 선언 시 template를 설명 해줘야함.
void simple<Ts>::showposition() {
	cout << '[' << num1 << "," << num2 << "]" << endl;
}

int main() {
	simple<int> pos1(3,4);				//int 생략 가능 (C++ 17 이후)
	pos1.showposition();
}