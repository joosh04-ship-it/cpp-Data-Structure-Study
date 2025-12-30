#include <iostream>

using namespace std;

class epoint {
	int x, y;
public:
	epoint(int x, int y) :x(x), y(y){}

	void showpoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class point {
private:
	int x;
	int y;
public:
	point(int x, int y) : x(x), y(y) {};
	void showpoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	point operator+(const point& ref) {								// operator+ 함수 선언(멤버함수)
		point pos(x + ref.x, y + ref.y);
		return pos;
	}

	friend point operator+(const point& ref1, const point& ref2);	// operator+ 함수 선언(전역함수) +
																	// 멤버함수로 오버로딩한 이항 연산자는 매개변수를 1개만 가질 수 있음
																	// -> friend 선언

	point &operator++() {											// operator++ 함수 선언(멤버함수) + 참조 반환 형태 (++(++pos)) 이런 형태 사용 가능
		x += 1;														// 후위 연산으로 선언하고 싶으면 point &operator++(int)의 형태로 선언
		y += 1;														// + 후위 연산으로 선언 할 때는 앞에 const를 붙힌다. ( (pos1--)--) 를 막기 위해
		return *this;
	}

	friend point &operator--(point &ref);							// operator-- 함수 선언(전역함수) + 참조 반환 형태

	point operator*(int time) {										// operator* 함수 선언
		point a(x * time, y * time);
		return a;
	}
	friend point operator*(int time, point& ref);
};

point operator+(const point& ref1, const point& ref2) {
	point pos(ref1.x + ref2.x, ref1.y + ref2.y);
	return pos;
}

point &operator--(point& ref1) {
	--ref1.x;
	--ref1.y;
	return ref1;
}

point operator*(int time, point& ref) {
	return ref * time;
}

int main(){

	// epoint epos1(3, 4);
	// epoint epos2(10, 20);
	// epoint epos3 = epos1 + epos2;		객체 간의 연산 불가

	point pos1(3, 4);
	point pos2(10, 20);

	point pos3 = pos1.operator+(pos2);						// operator+ 함수를 멤버함수로 오버로딩
	point pos4 = pos1 + pos2;								// 위 줄과 같은 문장 ( pos1+pos2 == pos1.operator+(pos2))
	point pos5 = operator+(pos1, pos2);

	pos3.showpoint();
	pos4.showpoint();
	pos5.showpoint();

	++(++pos1);

	pos1.showpoint();

	point pos6(1, 2);
	point cpy = pos6 * 3;								// 그냥은 cpy = 3 * pos6 안됨 --> 함수 선언 해줘야함 ex) point operator*(int time,point &ref){
	point cpy1 = 3 * pos6;								//														return ref*times; }
}

// 오버로딩이 불가능한 연산자의 종류 . .* :: ?: sizeof typeid static_cast dynamic_cast const_cast reinterpret_cast

// 멤버함수 기반으로만 오버로딩이 가능한 연산자 = () [] ->

// cout 과 endl 또한, << 연산자의 오버로딩을 이용 하여 선언됨
// << 는 전역함수 오버로딩으로만 사용


