#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
class point {
private:
	T xpos, ypos;
public:
	point(T x = 0, T y = 0);
	void showposition() const;

};

template <typename T>
point<T>::point(T x, T y) :xpos(x), ypos(y){}

template <typename T>
void point<T>::showposition() const {
	cout << '[' << xpos << ',' << ypos <<']' << endl;
}

template <class T>
class BoundCheckArray {
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr){}
	BoundCheckArray &operator=(const BoundCheckArray& arr){}
public:
	BoundCheckArray(int len) :arrlen(len) {
		arr = new T[len];
	}
	T& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "¾ÈµÅ¿ä." << endl;
			exit(1);
		}
		return arr[idx];
	}

	const T& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "¾ÈµÅ¿ä." << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const {
		return arrlen;
	}
	~BoundCheckArray() {
		delete[]arr;
	}
};

int main1() {
	BoundCheckArray<point<int>> oarr(3);
	oarr[1] = point<int>(3, 4);
	oarr[2] = point<int>(5, 6);

	BoundCheckArray<point<double>> oarr1(3);
	oarr1[0] = point<double>(14.44, 1324.55);
	oarr1[1] = point<double>(3.04, 5.55);
	oarr1[2] = point<double>(4.50, 6.66);

	for (int i = 0; i < oarr1.GetArrLen(); i++) {
		oarr1[i].showposition();
	}
	BoundCheckArray<point<int>*> oarr3(3);
	return 0;
}