#include <iostream>

using namespace std;

class Simple {
private:
	int num1;
	int num2;
	const int num3;

public:
	Simple() : num3(0){		//이니셜라이저로 const값 초기화 가능
		num1 = 0;			//생성자로 디폴트값 설정 가능
		num2 = 0;
	}
	Simple(int x, int y) : num3(0){		//생성자 오버로딩 가능
		num1 = x;
		num2 = y;
	}
	Simple(int x) : num1(x),num2(0),num3(0){}		//이니셜라이저를 이용한 초기화
	
	void Print(){
		cout << "HI" << endl;
	}

	~Simple() {							// 객체 소멸과정에서 자동 호출
		cout << "사라집니당~";			// 소멸자는 생성 순서의 역순으로 소멸
	}
};

class soso {
	int num1;
	int num2;
public:
	soso() {		//디폴트 생성자, 생성자를 넣지 않으면 자동 삽입

	}
private:
	soso(int n):num1(n){}	//private에 생성자 생성가능(외부에서 직접적으로 객체 생성 불가능.
							//따로 함수를 만들어 (예" create함수) 객체 생성 경로 지정 가능
};


int main() {
	Simple s1();	//컴파일러가 원형 선언문인지 객체생성문인지 알 수 없음
					//Simple s1; 으로 고쳐야함
	Simple s2(100, 200);
	Simple* ptr1 = new Simple();	//생성자 동적할당
	delete ptr1;

	Simple parr[3];		//객체 배열

	Simple* parr2[3];	//객체 포인터 배열
	parr2[1]->Print();
}