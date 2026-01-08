//<Point 클래스 템플릿과 배열 클래스 템플릿>
#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) {};
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
		
	}
	//특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend선언
	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
	//friend Point<T> operator+<T> (const Point<T>&, const Point<T>&);
};

//template<class T>
//Point<T> operator+ (const Point<T>&, const Point<T>&); {
	//return Point<T>(a.x +......

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) {
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

ostream& operator<<(ostream& os, const Point<int>& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len) : arrlen(len) { arr = new T[len]; };
	T& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
		}
		return arr[idx];
	}
	T operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
		}
		return arr[idx];
	}
	int GetArrLen() const;
	~BoundCheckArray() {
		delete[]arr;
	}
};

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

int main(void) {
	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(5, 6);
	oarr1[2] = Point<int>(7, 8);

	for (int i = 0; i < oarr1.GetArrLen(); i++)
		oarr1[i].ShowPosition();

	
	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.14, 4.31);
	oarr2[1] = Point<double>(5.09, 6.07);
	oarr2[2] = Point<double>(7.82, 8.54);

	for (int i = 0; i < oarr2.GetArrLen(); i++)
		oarr2[i].ShowPosition();

	//저장대상이 클래스의 객체가 아닌 Point<int>형 포인터라면 이렇게
	typedef Point<int>* POINT_PTR;
	BoundCheckArray<POINT_PTR> oparr3(3);
	oparr3[0] = new Point<int>(11, 12);
	oparr3[1] = new Point<int>(21, 22);
	oparr3[2] = new Point<int>(31, 32);

	for (int i = 0; i < oparr3.GetArrLen(); i++)
		oparr3[i]->ShowPosition();

	delete oparr3[0]; delete oparr3[1]; delete oparr3[2];

	cout << " -------------------------------- " << endl;
	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	cout << pos1<<pos2<<pos3;
	return 0;
}


