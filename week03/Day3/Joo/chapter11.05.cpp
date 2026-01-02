#include <iostream>

using namespace std;

class point {
	int xpos;
	int ypos;
public:
	
	point(int x, int y) : xpos(x), ypos(y) {}
	point operator+(const point& pos1) const{
		return point(xpos+pos1.xpos, ypos+pos1.ypos);
	}
	friend ostream& operator<<(ostream& os, const point& pos);
};

ostream& operator<<(ostream& os, const point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class adder {
public:	
	int operator()(const int& n1, const int& n2) {						// operator() 형, 객체의 동작방식에 유연함을 제공 할 수 있음(버블정렬 알고리즘 등등..)
		return n1 + n2;
	}
	double operator()(const double& n1, const double& n2) {
		return n1 + n2;
	}
	point operator()(const point& pos1, const point& pos2) const{
		return pos1 + pos2;
	}
};

int main1() {
	adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(point(3, 4), point(7, 9));
	return 0;
}