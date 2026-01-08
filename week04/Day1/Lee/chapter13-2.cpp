//<클래스 템플릿>

#include <iostream>
#include <cstdlib>
using namespace std;

class Point2 {
private:
	int xxpos, yypos;
public:
	Point2(int x = 0, int y = 0) : xxpos(x), yypos(y) {}
	friend ostream& operator<<(ostream& os, const Point2& pos);
};
ostream& operator<<(ostream& os, const Point2& pos) {
	os << '[' << pos.xxpos << ", " << pos.yypos << ']' << endl;
	return os;
}

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
	
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}
template <typename T>
void Point<T>::ShowPosition() const {
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}


//<배열 클래스의 템플릿화>
template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len) : arrlen(len) {
		arr = new T[len];
	};
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
};

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}

int main(void) {
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	//템플릿 클래스의 객체를 생성할 때에는 <int> 등의 자료형 정보 생략 불가능
	Point<char> pos2('P', 'F');
	pos2.ShowPosition();
	cout << "--------------------" << endl;

	/*** int형 정수 저장 ***/
	BoundCheckArray<int> iarr(5);
	for (int i = 0; i < 5; i++) {
		iarr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 5; i++)
		cout << iarr[i] << endl;

	/*** Point 객체 저장 ***/
	BoundCheckArray<Point2> oarr(3);
	oarr[0] = Point2(3, 4);
	oarr[1] = Point2(5, 6);
	oarr[2] = Point2(7, 8);
	for (int i = 0; i < oarr.GetArrLen(); i++)
		cout << oarr[i];
	
	/*** Point 객체의 주소 값 저장 ***/
	typedef Point2* POINT_PTR;
	BoundCheckArray<POINT_PTR> parr(3);
	parr[0] = new Point2(3, 4);
	parr[1] = new Point2(5, 6);
	parr[2] = new Point2(7, 8);
	for (int i = 0; i < parr.GetArrLen(); i++)
		cout << *(parr[i]);

	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}
