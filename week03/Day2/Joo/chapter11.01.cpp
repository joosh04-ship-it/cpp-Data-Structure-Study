#include <iostream>
#include <string>

using namespace std;

class simple {
	int num;
	string name;
public:
	simple(int num1,const string &name):num(num1),name(name){}
	~simple() {
		cout << "destructor!" << endl;
	}
	void showdata(){
		cout << num << " " << name << " ";
	}
	simple& operator=(const simple& ref) {					
		cout << "simple class";
		num = ref.num;
		name = ref.name;
		return *this;
	}
};

class simple2 :public simple {
	int num;
	string name;
public:
	simple2(int num1, const string& name1,int num2, const string &name2) :simple(num1, name1),num(num2), name(name2){}
	~simple2() {
		cout << "destructor!" << endl;
	}
	void showdata() {
		simple::showdata();
		cout << num << " " << name << " ";
	}
	simple2& operator=(const simple2& ref) {	
		cout << "simple2 class" << endl;;
		num = ref.num;
		name = ref.name;
		return *this;
	}
};

int main() {
	simple a(1,"joo");
	simple b = a;					// operator=() 없어도, 디폴트 대입 연산자	(string 사용 시 메모리 누수, 소멸자 문제 해결)
	simple2 c(2,"park",3,"lee");
	simple2 d(1, "joo", 0, "");		
	d = c;							// 대입 연산 진행 시, simple2에 선언되어있는 operator=() 연산만 진행하여,
	d.showdata();					// simple 클래스의 멤버변수는 바뀌지 않음.
									// -> 자식클래스에 operator 연산자 오버로딩이 있을 경우, 부모클래스의 연산자는 호출X (오버라이딩)
}

// 대입연산자와 복사생성자를 클래스의 private에 넣어, 복사 및 대입을 방지 시킬 수 있다.

//클래스가 힙 영역을 “직접” 사용하면
//소멸자·복사 생성자·대입 연산자를 제대로 선언하지 않을 경우
//메모리 누수 또는 잘못된 해제가 발생할 수 있다.