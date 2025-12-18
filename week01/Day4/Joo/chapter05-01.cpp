#include <iostream>

using namespace std;

void jj(int x) {
	int num1(x);		// 새로운 초기화 방식
						// num1=x;
}

class simple {
	int num1;
	int num2;
public:
	simple(int n1, int n2) : num1(n1), num2(n2){}

	simple(const simple &copy) : num1(copy.num1),num2(copy.num2){}	// 복사생성자
																	// 디폴트 복사생성자
																	// + 복사생성자 호출 시점
																	// 1.기존의 객체를 이용해 새로운 객체 초기화
																	// 2.call by value 방식의 함수호출(함수의 매개변수로 값 전달/참조호출 X)일 때
																	// 3.값을 반환할 때(참조형태로 반환은 X)
																	// 4.임시 객체로 초기화할 때 (A a = A();) 
																	//   4번 항목 - C++17 이후 대부분 복사 생략으로 직접 생성
																	
																	// 임시객체는 다음행으로 넘어갈 때 바로 소멸 -> 소멸자 호출 
																	// + 참조되는 객체 제외
};
class DeepCopy {
	int *num1;
public:
	DeepCopy(const DeepCopy& copy) {			//깊은 복사생성자		(const reference 사용 이유 : class의 주소만 가져오 되,
		num1 = new int(*copy.num1);				//클래스가 new/delete , 포인터멤버 등등 소유하고 있을 때 반드시 사용
	}											//얕은 복사에 비해(복사된 객체에 새 메모리 할당, 안전성, 이중해제 X, 등..)의 이점 
};
class NoCopy {
	int num1;
	int num2;
public:
	explicit NoCopy(const NoCopy &copy):num1(copy.num1),num2(copy.num2){}	//묵시적변환을 막음 ex) NoCopy2=NoCopy1;
																			//-> 대입 연산자를 이용한 객체의 생성 및 초기화 불가능
};

//int main() {
//	simple simp1(15,20);
//	simple simp2(simp1);	// 객체의 새로운 초기화 방식
//							// simp2=simp1;
//							// 복사생성자 호출
//}