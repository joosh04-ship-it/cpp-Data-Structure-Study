#include <iostream>

using namespace std;

class Point {
private:			//정보은닉, 멤버변수를 private로 선언하여 
					//임의의 값이 저장되는것을 막음
	int xpos;
	int ypos;

public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	};
	void ShowPointInfo() {
		cout << "[" << xpos << "," << ypos << "]" << endl;
	};
};

class Circle{		
private:
	int rad;
	Point center;

public:
	void Init(int x, int y, int r) {
		rad = r;
		center.Init(x, y);
	}
	void ShowCircleInfo() {
		cout << "radius=" << rad<<endl;
		center.ShowPointInfo();
	};
};

class Ring {			
private:
	Circle outter;		//캡슐화(코드 복잡도 낮춤, 위험성 낮춤)
	Circle inner;
public:
	void Init(int x, int y, int r, int x1, int y1, int r1) {
		inner.Init(x, y, r);
		outter.Init(x1, y1, r1);
	}
	void ShowRingInfo() {
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};

int main() {
	Ring ring;
	ring.Init(1,1,4,2,2,9);
	ring.ShowRingInfo();
}