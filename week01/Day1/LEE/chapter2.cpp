
/* 
#include <iostream>
using namespace std;

namespace AAA {
	namespace BBB {
		namespace CCC {
			void func() {
				cout << "Inside func of namespace AAA::BBB::CCC" << endl;
		}
	}
	

	}
}

namespace Parent {
	int num = 2;
	
	namespace Child {
		int num = 5;
		int val = 50;
	}
	namespace GrandChild {
		int num = 10;

	}
}

int val = 100;

int SimpleFunc() {
	int val = 200;
	val += 3; //지역변수 val에 접근
	::val += 7; //전역변수 val에 접근
	return val;
}


int main()
{
	int val = 200;
	cout << "Hello, World!" << endl;
	namespace ABC = AAA::BBB::CCC;
	
	using namespace Parent;
	ABC::func();
	cout << "Parent num: " << num << endl;
	cout << "Child num: " << Child::num << endl;
	cout << "GrandChild num: " << GrandChild::num << endl;
	cout << ::val << endl;
	cout << val << endl;
	cout << Child::val << endl;
	return 0;
}



#define SQUARE(x) x * x
#include <iostream>
using namespace std;

int add(int x, int y) {
	return x + y;
}
double add(double x, double y) {
	return x + y;
}
int add(int x) {
	return x;
}

template <typename T> //매크로와 인라인 차이점 2: 변수의 type설정이 매크로는 데이터 손실이 없는데, 인라인은 template를 써야 손실이 없음
inline T multiply(T x, T y) {
	return x * y;
}
int main()
{
	cout << "Hello, World!" << endl;
	cout << "add(2, 3): " << add(2, 3) << endl;
	cout << "add(2.5, 3.5): " << add(2.5, 3.5) << endl;
	cout << "add(5): " << add(5) << endl;
	cout << "multiply(2, 3): " << multiply(2, 3) << endl;
	int a = SQUARE(1 + 2);
	cout << "SQUARE(1 + 2): " << a << endl; //매크로와 인라인 차이점 1: 매크로는 (1+2) * 1 + 2가 됨. 인라인 뷰 - 9가 나옴.
	return 0;
}
*/
/*
#include <iostream>
using namespace std;

bool IsPositive(int num) {
	if (num > 0) {
		return true;
	}
	else {
		return false;
	}
}
*/

/*
void Swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
} //내부에서만 값이 바뀌고, 실제로는 바뀌지 않음!, Swap(num1, num2);

void SwapRef(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
} //참조자를 사용하여 실제 값이 바뀜, SwapRef(num1, num2); + 매개변수에 const를 붙이면 값이 바뀌지 않음

void Swqptr(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
} //포인터를 사용하여 실제 값이 바뀜, SwapPtr(&num1, &num2);

*/



/*
int& RefRetFuncOne(int &ref) {
	ref ++;
	int num = 20; //return num;은 안됨(지역변수이기 때문에)
	return ref;
} //참조자를 반환하는 함수, RefRetFuncOne(num1) = 30; 가능

int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
} //참조자를 반환하는 함수, RefRetFuncOne(num1) = 30; 가능



int Adder(const int& a, const int& b) {
	//a++; //const로 선언된 참조자는 값을 변경할 수 없음
	return a + b;
} //const 참조자 매개변수, 원본 데이터를 보호하기 위해 사용

int main(void)
{
	
	int num = 10;
	int i = 0;
	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	while (true) {
		cout << i++ << ' ';
		if (i > num) {
			break;
		}
	}
	cout << endl;

	cout << "size of true: " << sizeof(true) << endl;
	cout << "size of false: " << sizeof(false) << endl;
	cout << "sizeof 10: " << sizeof(1023) << endl;



	
	bool isPos; //true/false 값을 저장하는 변수
	int val;
	cout << "Enter an integer: ";
	cin >> val;
	isPos = IsPositive(val);
	if (isPos) {
		cout << val << " is a positive number." << endl;
	}
	else {
		cout << val << " is not a positive number." << endl;
	}





	//int *ptr = &num1;은 변수 num1의 주소를 포인터 ptr에 저장
	//int &num2 = num1;은 변수 num1에 대한 참조자 num2를 선언
	
	int num1 = 1020;
	int& num2 = num1; //num1에 대한 참조자 num2 선언, 쉽게 이해하자면 num2는 num1의 별명
	//변수에 대해서만 참조자를 만들 수 있음, int &ref = 10;, int &ref, &ref=NULL;도 불가능

	num2 = 3047; //num2를 통해 num1의 값을 변경
	cout << "첫 변경num1: " << num1 << endl;
	cout << "첫 변경num2: " << num2 << endl;

	num1 = 5000; //num1의 값을 변경
	cout << "두번째 변경num1: " << num1 << endl;
	cout << "두번째 변경num2: " << num2 << endl;



	int num3 = 12;
	int* ptr = &num3; //포인터 ptr이 num3의 주소를 가리킴
	int& ref = num3; //참조자 ref가 num3을 참조
	int* (&pref) = ptr; //참조자 pref가 포인터 ptr을 참조

	cout << "num3: " << num3 << endl;
	cout << "*ptr: " << *ptr << endl;
	
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1); //num1에 대한 참조자를 반환하는 함수 호출
	int num3 = RefRetFuncOne(num1); //값을 반환하는 함수 호출
	int num4 = RefRetFuncTwo(num1); //값을 반환하는 함수 호출, int &num4 = RefRetFuncTwo(num1); //이건 안됨(참조자를 반환하는게 아니니까)
	num1++;
	num2++;
	num3+=100;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "num3: " << num3 << endl;
	cout << "num4: " << num4 << endl;


	const int num5 = 50;
	const int& ref2 = num5; //const 변수에 대한 참조자 생성
	const int& ref3 = 100; //임시변수에 대한 참조자 생성, 상수화된 변수

	cout << "Adder(num5, 20): " << Adder(num5, 20) << endl;
	return 0;

}*/

#define _CRT_SECURE_NO_WARNINGS   // ★ 반드시 include 위에

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* MakeStrAdr(int len) {
	char* str = new char[len];
	return str;
}

int main(void) {
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	delete[] str;
	return 0;
}