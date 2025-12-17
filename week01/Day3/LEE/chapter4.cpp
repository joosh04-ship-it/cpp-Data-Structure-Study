
/*
#include <iostream>
using namespace std;

class Point {
    public:
		int x;
		int y;
};

class Rectangle {
	public:
		Point upLeft;
		Point lowRight;

	public:
		void ShowRecInfo() {
			cout << "Upper Left Point: (" << upLeft.x << ", " << upLeft.y << ")\n";
			cout << "Lower Right Point: (" << lowRight.x << ", " << lowRight.y << ")\n";
		}
};

int main()
{
	Point pos1 = { -2, 4 }; //setter함수가 없어도 초기화 가능 -> public 멤버이기 때문
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos1, pos2 };
	rec.ShowRecInfo();
	return 0;
}

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(): x(0), y(0) {} // 디폴트 생성자
	//디폴트 생성자가 없으면 Point pos1;에서 오류 발생
	Point& CreatePoint(int xpos, int ypos) { // Point 객체를 초기화하는 멤버 함수
		x = xpos;
		y = ypos;
		return *this; // 현재 객체의 참조자를 반환
	}

	bool InitMember(int xpos, int ypos) {

		if (xpos < 0 || ypos < 0) {
			cout << "Negative values are not allowed.\n";
			return false;
		}
		x = xpos;
		y = ypos;
		return true;
	}

	int GetX() const { return x; } // const 멤버 함수: 객체의 상태를 변경하지 않음을 보장
	int GetY() const { return y; }
	~Point() {} // 소멸자
private:
	Point(int xpos, int ypos) : x(xpos), y(ypos) {} // private 생성자, 있는 이유는 외부에서 직접 객체 생성을 막기 위해
};

class Rectangle {
private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& ul, const Point& lr) { 
		// const Point& ul, const Point& lr : 상수 참조자, 복사본을 만들지 않고 원본을 읽기 전용으로 사용
		// const char* str과 같은 맥락, 포인터는 Null이 될 수 있지만 참조자는 Null이 될 수 없음
									 // 따라서 참조자는 항상 유효한 객체를 가리킴
									 // 복사본을 만들지 않으므로 성능 향상
									 // 원본 객체를 보호하기 위해 const 사용
		if (ul.GetX() >= lr.GetX() || ul.GetY() >= lr.GetY()) {
			cout << "Invalid rectangle coordinates.\n";
			return false;
		}
		upLeft = ul;
		lowRight = lr;
		return true;
	}

	void ShowRecInfo() {
		cout << "Upper Left Point: (" << upLeft.GetX() << ", " << upLeft.GetX() << ")\n";
		cout << "Lower Right Point: (" << lowRight.GetX() << ", " << lowRight.GetY() << ")\n";
	}
};

int main()
{
	Point a(2, 3);
	Point base;
	Point& obj1 = base.CreatePoint(10, 20); //private 생성자이므로 Point obj1(10, 20); 불가
	Point pos1;
	if (!pos1.InitMember(2, 4)) {
		return -1; // 초기화 실패 시 프로그램 종료
	}
	Point pos2;
	if (!pos2.InitMember(5, 9)) {
		return -1; // 초기화 실패 시 프로그램 종료
	}
	Rectangle rec;
	if (!rec.InitMembers(pos1, obj1)) {
		return -1; // 초기화 실패 시 프로그램 종료
	}
	rec.ShowRecInfo();
	
	
	return 0;
};


