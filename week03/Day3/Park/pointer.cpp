#include <iostream>
#include <memory>

using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point(int x): x(x), y(0){}
	Point(int x, int y) :x(x), y(y) {
		cout << "객체 생성" << endl;
	}
	~Point() {
		cout << "객체 소멸" << endl;
	}
	void showPoint() {
		cout << x << endl << y << endl;
	}
	operator int() {// 형변환 연산자
		return x;
	}
};
class SmartPtr {//스마트 포인터는 자동으로 delete를 해주는 포인터이다.
private:
	Point* pointer;
public:
	SmartPtr(Point* ptr) : pointer(ptr) {

	}
	Point& operator*() const {
		cout << "*연산" << endl;
		return *pointer;
	}
	Point* operator ->() const {
		cout << "->연산" << endl;
		return pointer;
	}
	~SmartPtr() {
		delete pointer;
	}
};
class Adder {//()연산자의 오버로딩을 이용한 클래스를 함수처럼 이용하기 //펑터라고 부름
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
int main() {
// 포인터 연산자의 오버로딩
	//-> , *
	Point point(1,2);
	SmartPtr ptr1(new Point(1, 2));//내가만든 스마트 포인터
	ptr1->showPoint();

	Adder adder;
	cout << adder(1, 2) << endl;//펑터 사용

	int x = point + 3;//Point 클래스의 int형으로의 형변환
	cout << x << endl;


	//실제 스마트 포인터 사용해보기//auto는 컴파일러에게 형을 추론하도록 맡기는 것.
	auto p = make_unique<Point>(1,2); // make_unique 하면 객체 하나의 주소를 딱 하나의 포인터만 소유하게 됨
	p->showPoint();
	//auto p2 = p; 컴파일 에러 유니크 포인터기 때문
	auto p1 = make_shared<Point>(2, 3);//얘는 shared기 때문에 여러 주소변수가 하나의 객체를 가리켜도 문제되지 않음
	auto p2 = p1;// 얘는 가능
	weak_ptr<Point> w = p2;
	if (auto sp = w.lock()) {//lock을 이용해서만 참조 가능 평소엔 참조 못함
		sp->showPoint();
	}
}