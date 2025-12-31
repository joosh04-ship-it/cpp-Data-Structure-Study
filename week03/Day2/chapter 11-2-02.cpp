// <<객체의 저장을 위한 배열 클래스의 정의>>
//기본 자료형 배열은 ‘값 복사’만 신경 쓰면 되지만,
//객체 배열은 ‘생성 · 복사 · 소멸’ 전 과정을 책임져야 한다는 점
//객체의 주소 값을 저장하는 배열 기반의 클래스

#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << "[" << pos.xpos << ", " << pos.ypos << endl;
	return os;
}

//포인터 배열임을 강조하기 위한 기독성 목적
typedef Point* POINT_PTR;
//POINT_PTR == Point*
//POINT_PTR* arr = Point** arr

class BoundCheckPointArray {
private:

	//여러 개의 Point* (주소)를 배열에 담으려면,
	//	그 배열을 가리키는 타입은 Point** 가 될 수밖에 없다.
	POINT_PTR* arr;
	int arrlen;
	//[구조]
	//arr  →[Point*][Point*][Point*]
	//			|        |        |
	//		  Point    Point    Point

	//복사 방지
	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}

public:
	BoundCheckPointArray(int len) : arrlen(len) {
		//포인터 배열만 생성
		//Point 객체는 생성X
		arr = new POINT_PTR[len];
	}

	//실제 포인터 저장공간에 접근해야하기에 참조 반환
	POINT_PTR& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GerArrLen() const { return arrlen; }

	//Pointer 객체는 삭제X, 포인터 배열만 삭제
	~BoundCheckPointArray() { delete []arr; }
};

int main(void) {
	BoundCheckPointArray arr(3);

	//Point 객체는 동적 생성, 배열은 주소만 저장
	//arr[0]에 “Point 객체가 있는 위치 정보”만 있음
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GerArrLen(); i++)
		//*역참조 역할 - 포인터가 가리키는 실제 Point객체를 가리킴
		cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
	//직접 삭제 안하면 메모리 누수남
	return 0;

}
