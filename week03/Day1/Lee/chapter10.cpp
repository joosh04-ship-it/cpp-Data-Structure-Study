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

	//멤버함수에 의한 연산자 오버로딩
	Point operator+(const Point& ref) {
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}

	//증가 연산자의 오버로딩
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point operator+(const Point &pos1, const Point &pos2);
	friend Point operator--(Point& ref);
	//후위감소
	friend const Point operator--(Point& ref, int);
};

//전역함수에 의한 연산자 오버로딩
Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

//감소 연산자의 오버로딩
Point operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

//const가 붙는 이유는 operator--함수의 반환으로 인해서 생성되는 임시객체를 const 객체로 생성!
const Point operator--(Point& ref, int) { //int는 후위 연산자임을 표시하는 더미 인자
	const Point retobj(ref); //const 객체라 함
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;	//Point pos3 = pos1.operator+(pos2);
	Point pos4 = operator+(pos2, pos3);
	//연산자 오버로딩 확인 코드
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	//증가, 감소 연산자 오버로딩 확인 코드
	Point pos(1, 2);
	Point cpy;
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition();
	++(pos.operator++());
	pos.ShowPosition();
	
	cout << "후위감소 예시" << endl;
	cpy = pos--;
	//(pos-- = cpy)-- (x) : (Point형 const 임시 객체)++ (1, 3) (1, 3) c++ 논리적으로 금지시 코딩 문법적으로 컴파일 에러나게 만들자!
	//애초에 감소 대상이 원본 객체여야 하는데 위는 임시 객체를 감소시키는 행위
	cpy.ShowPosition();
	pos.ShowPosition();

	int x, y;
	y = 3;
	x = 0;
    // x = (y++)++; 부분을 아래와 같이 수정하세요.
    // 후위 증가 연산자(y++)의 결과는 임시 객체(값)로 lvalue가 아니므로 다시 ++를 적용할 수 없습니다.
    // 만약 y를 두 번 증가시키고 싶다면 아래처럼 작성해야 합니다.

    y++;
    x = y++;
}
