#include <iostream>

using namespace std;
double aaa = 1000;
//그 외의 연산자 오버로딩
	//new, delete
	//new 연산자의 역할
	//1. 메모리 공간의 할당
	//2. 생성자의 호출
	//3. 주소 값 반환
	//이 중 메모리 공간의 할당 부분만을 오버로딩 가능
	//반드시 이렇게만 오버로딩 해야함!
class A {
public: 
	int a;
	int b;
	A(int a, int b) : a(a), b(b){}
};
//void* operator new (size_t size) {//이런식으로 주소로 직접 지정해줘버리면 그 주소를 덮어 씌우는 ub문제를 발생 시킨다.
//	return &aaa;
//}
void* operator new (size_t size) {
	cout << "new 연산자 오버로딩!!!!" << endl;
	void* p = malloc(size);
	return p;
}
void* operator new[] (size_t size) {
	cout << "new 연산자 오버로딩!!!!" << endl;
	void* p = malloc(size);
	return p;
}
void operator delete(void* addr) {
	cout << "delete 연산자 오버로딩~~!~!~!" << endl;
	free(addr);
}
void operator delete[](void* addr) {
	cout << "delete 연산자 오버로딩~~!~!~!" << endl;
	free(addr);
}
//멤버 연산자로 오버로딩을 하더라도, 클래스 생성 등을 할 수 있는데 그 이유는 static으로 간주 되기 때문이다.
int main1()
{
	A* hello = new A(1, 2);

	cout << hello -> b << endl << aaa << endl;

	delete hello;

	cout << aaa << endl;

	return 0;
}
