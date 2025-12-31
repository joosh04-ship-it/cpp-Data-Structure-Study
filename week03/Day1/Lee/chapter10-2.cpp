#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << "[" << xpos << ',' << ypos << ']' << endl;
	}
	//왼쪽 피연산자는 반드시 그 클래스의 타입
	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

//ostream을 쓰는 이유 ①왼쪽 피연산자가 cout ②연쇄 연산자여야 함 ③표준 출력과 섞어 쓰려면
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ',' << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

Point operator*(int times, Point& ref) {
	return ref * times;
}

int main(void) {
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	//하지만 3 *pos는 안됨(이를 해결하기 위해 전역함수로 해야함)
	cpy.ShowPosition();
	
	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	cout << cpy;
	cin >> cpy;
	cout << cpy <<endl;
	return 0;
}
