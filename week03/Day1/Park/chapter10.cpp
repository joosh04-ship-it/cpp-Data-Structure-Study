#include <iostream>

using namespace std;
class Point {
private:
	int x, y;
public:
	Point(int x, int y) : x(x),y(y) {};
	void showPoint() {
		cout << x << "," << y << endl;
	}
	Point operator+(const Point& ref) {
		return Point(x + ref.x, y + ref.y);
	}
	//단항 연산자 오버로딩의 경우
	const Point &operator++(int) {//후위 - 계수에 int로 구분
		cout << "후위 연산자 호출" << endl;
		this->x += 1;
		this->y += 1;
		return *this;
	}
	Point &operator++() {//전위
		cout << "전위 연산자 호출" << endl;
		this->x += 1;
		this->y += 1;
		return *this;
	}
	//교환법칙 불가
	Point operator*(int times) {
		return Point(x * times, y * times);
	}
};
//교환법칙 가능하게 만들기
Point operator*(int times, Point& ref) {
	return ref * times;
}
namespace PJstd {
class ostream {
public:
	ostream& operator<<(const char* str) {
		printf("%s", str);
		return *this;
	}
	ostream& operator<<(char ch) {
		printf("%c", ch);
		return *this;
	}

	ostream& operator<<(int num) {
		printf("%d", num);
		return *this;
	}

	ostream& operator<<(double e) {
		printf("%g", e);
		return *this;
	}
	ostream& operator<<(ostream& (*fp)(ostream&)) {
		return fp(*this);
	}
};
inline ostream& endl(ostream& os) {
	os << '\n';
	fflush(stdout);
	return os;
}
ostream cout;
}
int main()
{
//연산자 오버로딩
	//기본 연산자를 오버로딩 할 수 있는 기능
	Point a(1, 1);
	Point b(2, 3);
	Point c = a + b;
	c.showPoint();
	c++;
	++(++c);
	c.showPoint();
	c = c * 10;
	c.showPoint();
	c = 10 * c; // 전역에서 오버로딩 해두었기에 사용 가능
	c.showPoint();
	PJstd::cout << "이거 잘 되나?"<<PJstd::endl;
}
