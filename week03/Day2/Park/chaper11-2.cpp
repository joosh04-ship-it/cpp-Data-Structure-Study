//#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
//
//class A {
//public:
//	int a, b;
//	A(int a, int b) : a(a), b(b) {}
//	A& operator=(A& ref) {
//		a = ref.a;
//		b = ref.b;
//		return *this;
//	}
//};
//class B : public A {
//public:
//	int c, d;
//	B(int a, int b, int c, int d) : A(a,b), c(c), d(d) {}
//	B& operator=(B& ref) {//자식 클래스에서 대입연산자 오버로딩을 할 때는 반드시
//		A::operator=(ref);//이거 넣어주기
//		c = ref.c;
//		d = ref.d;
//		return *this;
//	}
//};
//
//int main() { 
//	B bb(1, 2, 3, 4);
//	B cc(0, 0, 0, 0);
//	cc=bb;
//	cout << cc.a << cc.b << cc.c << cc.d << endl;
//}