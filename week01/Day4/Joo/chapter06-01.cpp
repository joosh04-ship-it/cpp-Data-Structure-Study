#include <iostream>

using namespace std;

class Joo;

class Park {
private:
	int height;
	friend class Joo;					//friend 선언으로 class Joo에서 Park의 private에 접근 할 수 있도록 함
										//frined class Joo::touchpark(Park &);로 함수에만 접근 할 수 있게 할 수 있음
public:
	Park(int x):height(x){}
};

class Joo {
private:
	int age;
	int height;
public:
	void touchpark(Park &park){
		cout << "평준이의 키는 " << park.height<<endl ;		//Park의 private 멤버 변수에 접근
	}
};

class LeesGirlfriend {
public:
	static int num;											//static 멤버변수
	const static int num1 = 1;								//const static 멤버변수 (const 멤버변수는 이니셜라이저를 통해 초기화 해야하지만,
															//const static 멤버변수는 선언과 동시에 초기화 가능
public:
	LeesGirlfriend() {
		num++;
		cout <<"진서의 남자	친구 : " << num << "명" << endl;
	}
	static void Hoo(){										//static 멤버함수
		cout << num << endl;								//static 멤버변수와 static 멤버함수만 호출 가능
	}														//class이름으로 함수 접근 가능
};

class simple {
	int num1;
	mutable int num2;										//mutable 키워드를 통해 const 함수 내부에서 값 변경을 가능하도록 함
public:
	simple(int n1,int n2):num1(n1),num2(n2){}

	void chgconst() const{
		num2 = num1;										//const 함수 임에도 mutable에 의해 num2의 값 변경 가능
	}
};

int LeesGirlfriend::num = 0;								//static 멤버변수 초기화

int main() {
	Park park(160);
	Joo joo;
	joo.touchpark(park);
	
	LeesGirlfriend kang;
	LeesGirlfriend choi;
	LeesGirlfriend kim;

	cout << LeesGirlfriend::num << endl;					// public 으로 선언된 static 멤버변수는 객체(kim, choi)와 
	cout << kim.num << endl;								// class의 이름을 통해서도 접근 가능
	cout << choi.num << endl;
}