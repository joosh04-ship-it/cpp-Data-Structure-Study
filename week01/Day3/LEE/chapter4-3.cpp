// chapter4-3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class TwoNumber {
	private:
	int num1;
	int num2;
	public:
		TwoNumber(int num1, int num2) {
			this->num1 = num1; //this는 멤버 함수 내에서 객체 자신을 가리키는 포인터
			this->num2 = num2;
		}
		TwoNumber& Adder(int n) {
			this->num1 += n;
			this->num2 += n;
			return *this; //현재 객체의 참조자를 반환)
			}
		TwoNumber& shownumber() {
			cout << "num1: " << this->num1 << ", num2: " << this->num2 << endl;
			return *this; //현재 객체의 참조자를 반환)
		}

};

int main()
{
	TwoNumber obj(10, 20);
	TwoNumber& ref = obj.Adder(5); //obj의 num1과 num2에 각각 5를 더함
	obj.shownumber(); //obj의 num1과 num2 출력
	ref.shownumber(); //ref는 obj를 참조하므로 obj의 num1과 num2 출력
	obj.Adder(5).shownumber().Adder(10).shownumber(); //체이닝 기법
	ref.Adder(10).shownumber(); //ref는 obj를 참조하므로 obj의 num1과 num2 출력
	return 0;
}
