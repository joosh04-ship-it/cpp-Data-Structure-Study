#include <iostream>
using namespace std;
namespace A {
	int x = 1;
	void hello() {
		cout << "helloWorld" << endl;
	}
}
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
	}
	namespace GrandChild {
		int num = 10;
	}
}
inline int inlinesquare(int x) {
	return x * x;
}
#define definesquare(x) x*x
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
inline int add1(int a, int b) { return a + b; }
void foo(int a, int b = 0) {
	cout << a + b << endl;
}
template <typename T>
inline T multiply(T x, T y) {
	return x * y;
}
int val = 100;
int main() {
//입출력 함수
	int a;
	cin >> a;
	cout << a << endl;
	//endl -> 느려서 문제풀때 안쓰는게 좋다.

//오버로딩
	cout << add(1, 2) << endl;
	cout << add(1.1, 1.2) << endl;
	cout << add(1, 2, 3) << endl;
	// 출력값만 다르고 같은 입력 값을 가지게 만들면 오류 발생
	// 입력값이 다르더라도 디폴트 값이 있어서 상관 없는 경우에도 오류 발생할 수 있음

//매개변수 기본 값
	foo(1, 2);
	foo(1);
	
//인라인
	cout << add1(1, 3) << endl;
	//인라인함수는 헤더파일에 함수 정의할 떄, 클래스 멤버 함수를 클래스 안에서 바로 정의할 때, 짧고 자주 호출되는 유틸 함수일 때 선언함
	//인라인 함수는 함수를 호출하는 방식이 아니라 코드를 펼쳐 넣는 방식으로 진행됨
	//컴파일러가 봤을 때 그냥 함수를 호출하는 방식이 더 성능면에서 좋을 때는 inline이 무시됨
	//매크로함수와 다른점
	cout << inlinesquare(1 + 2) << endl; //(1+2) * (1+2) -> 9출력
	cout << definesquare(1 + 2) << endl; //1+2*1+2 -> 5출력
	
	//매크로함수는 타입지정이 필요없다. but 인라인은 타입지정이 필요하기 때문에 제한이 있다.
	//템플릿을 이용하면 해소 가능
	cout << multiply(3, 2) << endl;

//namespace
	using A::hello;//특정 함수만 사용하게 지정할 수도 있음
	cout << A::x << endl;
	hello();
	//같은 이름의 함수명이 필요할 때 사용 가능
	//중첩 namespce 예제
	namespace ABC = AAA::BBB::CCC;
	ABC::func();
	using namespace Parent;
	cout << "Parent num: " << num << endl;
	cout << "Child num: " << Child::num << endl;
	cout << "GrandChild num: " << GrandChild::num << endl;
//scope연산
	int val = 200;
	cout << val << endl; // 지역
	cout << ::val << endl; // 전역
//bool
	bool a = true;
	bool b = false;
	bool c = 1;//0이면 false 아니면 true
	cout << a << endl;
	return 0;
}