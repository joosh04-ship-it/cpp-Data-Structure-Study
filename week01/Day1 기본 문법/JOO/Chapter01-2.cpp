#include <iostream>
#include <string>
using namespace std;

void SwapByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}	//Call by value 

void SwapByRef(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}	//Call by reference

void SwapByRef2(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}	//Call by reference2 + 메인 함수의 값을 변경하지 않기 위해서는 const int &a... const 참조자 사용

int& reffunc(int& ref) {
	ref++;
	return ref;
}

char* MakeStr(int len) {
	char* str = new char[len];	// char *str=(char*)malloc(sizeof(char)*len);
	return str;
}

int main() {
	int num1 = 2025;
	int& num2 = num1;	// 참조자는 선언과 동시에 누군가를 참조해야함
						// int &ref = 20; --> (X) 상수를 대상으로 참조 불가능
	
	int arr[3] = { 1,3,5 };
	int& ref1 = arr[0];	//
	int& ref2 = arr[1];	// 배열요소도 변수로 간주되어 참조 가능
	int& ref3 = arr[2];	//
	
	int num3 = 100;		
	int* ptr = &num3;
	int** dptr = &ptr;

	int& ref = num3;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;		// 결과값 3개 전부 100
	cout << *pref << endl;		// -> 포인터도 변수이므로 참조 가능
	cout << **dpref << endl;	// 

	int val1 = 100;
	int val2 = 200;
	SwapByValue(val1, val2);		/* CallByValue의 형태로 정의된 함수는 함수 외부의 변수에 접근 불가
									   --> 값 변경 X
									*/
	cout << val1 << val2 << endl;

	SwapByRef(&val1, &val2);		/* CallByValue의 형태로 정의된 함수는 함수 외부의 변수에 접근 불가
									   --> 값 변경 O
									*/

	cout << val1 << val2 << endl;
	SwapByRef2(val1, val2);			/* 매개변수로 선언된 참조자가 main함수에서 선언된 변수의 또 다른 이름이 되어 값을 교환함 
									   --> 값 변경 O
									*/

	int num4 = reffunc(num3);		// 함수의 반환형이 참조자일 경우 참조자형, 기본자료형에 모두 변수값 저장 가능 
	int& num5 = reffunc(num3);		// 반환형이 기본자료형일 경우 참조자형은 X (반환값이 상수이기 때문) 

	const int num6 = 20;			// int &ref4=num6; 컴파일 에러 
	const int& ref4 = num6;			// const 참조자로 const 자료형 참조가능

	const int& ref5 = 30;			// const 참조자는 임시변수를 만들고 상수를 저장
									// --> 참조자가 임시변수를 참조하기에 상수 참조 가능

	int num7 = 20;
	const int & ref6 = num7;
	//ref6+=1; 불가능
	//

	char* str = MakeStr(20);
	strcpy(str, "I am happy~");
	cout << str << endl;
	delete[]str;					//free(str);

}