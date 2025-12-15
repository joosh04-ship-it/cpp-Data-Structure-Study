#include <iostream>
#include <cstdio>
using namespace std;
void plus1(int& a) { a++; }
struct Point {
	int x;
	int y;
};
int main() {
//bool
	bool a = true;
	bool b = false;
	bool c = 1;//0이면 false 아니면 true
	cout << a << endl<<b<<endl;//true는 1, false는 0 출력
	//사용 예시
	if (0) {//0일때
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (100) {//!0일때
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
//reference
	//포인터와 차이점 : 눌포인터 불가, 대상 변경 불가, *기호 사용 안해도 됨

	int ref = 10;
	//int& r; 컴파일 에러. 반드시 선언과 동시에 초기화 해주어야함
	int& r = ref;//한번 설정되면 다른 것을 가리킬 수 없음
	cout << r << endl;

	r = 20;
	cout << r << endl;//원본 값이 수정되어 20 출력
	cout << ref << endl;//원본 값이 수정되어 20 출력

	//사용 이유 : 함수에서 원본 값을 수정하고 싶을때, 복사 비용이 커서 주소를 복사해야할 때
	// 
	//사용 예시
	//void plus1(int& a) { a++; }
	plus1(ref);

	cout << ref << endl; // 원본 값이 수정되어 21 출력
	//void Swap(int a, int b) {
	//	int temp = a;
	//	a = b;
	//	b = temp;
	//}
	////내부에서만 값이 바뀌고, 실제로는 바뀌지 않음!, Swap(num1, num2);

	//void SwapRef(int& a, int& b) {
	//	int temp = a;
	//	a = b;
	//	b = temp;
	//} 
	////참조자를 사용하여 실제 값이 바뀜, SwapRef(num1, num2); + 매개변수에 const를 붙이면 값이 바뀌지 않음

	//void Swqptr(int* a, int* b) {
	//	int temp = *a;
	//	*a = *b;
	//	*b = temp;
	//} 
	////포인터를 사용하여 실제 값이 바뀜, SwapPtr(&num1, &num2);

//const 레퍼런스
	//포인터에 비해 const를 적용하기 간편함
	int cref = 10;
	const int& cr = cref;
	//cr +=1; 불가
	cref += 1; //가능
	cout << cr << endl;
	//사용 예시
	////함수에서 값은 수정하고싶지 않은데, 값 전체를 복사하기 싫을 때
	//void print(const string & s) {}
	////임시 객체를 저장해두고 싶을 때
	//int& tmp = 5; 일반 레퍼런스의 경우 오류발생
	const int& tmp = 5;//가능
	cout << tmp << endl;

//동적 메모리
	//freeStore에 공간을 할당하는 new
	int* p = new int;
	*p = 3;
	cout << *p << endl;
	//공간을 해지하는 delete
	delete p;
	p = nullptr;//delete 이후에 그 값을 nullptr로 바꾸어주는 것이 좋음 그래야 더미 값을 사용하는 것을 방지

	//구조체 포인터
	Point* point = new Point;
	(*point).x = 1;
	point->y = 2;

	//동적 배열 할당
	int* arr = new int[2];
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 0; i < 2; i++) {
		cout << arr[i] << endl;
	}
	delete[] arr;// 배열 delete 시에는 delete[] 사용해야함
	arr = nullptr;

	//new와 delete가 쌍을 이루지 않는 경우 메모리 누수가 발생하므로 반드시 쌍을 이룰 것.
//c언어 표준함수 사용하기
	//#include <cstdio>등 .h 빼고 앞에 c 붙여서 사용 가능
	return 0;
}