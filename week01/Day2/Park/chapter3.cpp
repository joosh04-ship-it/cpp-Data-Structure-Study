#include <iostream>

using namespace std;
// 구조체 선언
struct University {
	string unv;
	string dept;
};
struct  Student {
	string name;
	int age;
	double grade;
	University unv; //구조체 안에 구조체도 가능
	void newYear() {
		age++;
	}
	Student(string name, int age, double grade, University unv) //생성자
		: name(name), age(age), grade(grade), unv(unv) {}
};

// 클래스 선언
class Car {
private:
	string model;
	int number;
	int speed;
public:
	Car(string m, int n, int s)//생성자
		: model(m), number(n), speed(s) {
	}
	Car(int n)//생성자 오버로딩도 가능!
		: model("Unknown"), number(n), speed(0) {
	}
	~Car() {//소멸자
	}
	static int count; //정적 멤버 변수
	void setSpeed(int s) {//세터
		if (s < 0) {
			this->speed = 0;//this 포인터 : 멤버 변수와 매개변수 이름이 같을 때 구분하기 위해 사용
		}
		else {
			speed = s;
		}
	}
	int getSpeed() const {//게터, const 멤버함수 : 멤버 변수를 변경하지 않음을 보장
		return speed;
	}
};
int Car::count = 0; //정적 멤버 변수 초기화

class Animal {
protected://자식클래스에서 접근 가능
	void eat() {
		cout << "Eating...\n";
	}
public:
	void sleep() {//정적 바인딩
		cout << "Sleeping...\n";
	}
	virtual void move() {//동적 바인딩
		cout << "Moving...\n";
	}
	virtual ~Animal() {} //가상 소멸자 상속 가능성이 있으면 소멸자도 반드시 가상으로 선언
};
class Dog : public Animal { //상속
public:
	void bark() {
		cout << "Barking...\n";
	}
	void dogEat() {
		eat(); //부모 클래스의 protected 멤버에 접근 가능
	}
	void sleep() {// 오버라이딩 자식 클래스에서 부모 클래스의 멤버 함수를 재정의
		cout << "Dog Sleeping...\n";
	}
	void move() override { //오버라이딩
		cout << "Dog Moving...\n";
	}
};
// 퍼블릭 상속 : 부모 클래스의 퍼블릭, 프로텍티드 멤버가 자식 클래스에서 퍼블릭, 프로텍티드로 접근 가능
// 프라이빗 상속 : 부모 클래스의 퍼블릭, 프로텍티드 멤버가 자식 클래스에서 프라이빗으로 접근 가능
// 프로텍티드 상속 : 부모 클래스의 퍼블릭, 프로텍티드 멤버가 자식 클래스에서 프로텍티드로 접근 가능

int main() {
// 구조체
	// 여러 값을 묶어서 새로운 타입을 만드는 문법
	// 구조체 사용
	/*Student S;
	S.name = "PJ";
	S.age = 22;
	S.grade = 4.5;*/
	// 다른 초기화 방법
	Student a = { "JS", 22, 4.5 ,{} };
	//Student b = { .name = "HS", .age = 23, .grade = 4.3 }; C++20부터 지원
	//기본적으로 구조체 멤버는 Public 접근 지정자를 가짐
	a.newYear();// c++이기 때문에 구조체 안에 함수도 넣을 수 있음 -> 정보 은닉 필요시 class 사용
	cout << a.name << " " << a.age << " " << a.grade << "\n";
	//구조체 생성자 사용 : 생성자 있을 시 반드시 사용해야 함
	Student c("SH", 22, 4.5, {});
	cout << c.name << " " << c.age << " " << c.grade << "\n";
	//포인터 접근 시
	Student* p = &c;
	p->newYear();
	cout << p->name << " " << p->age << " " << p->grade << "\n";
	// 함수에 넘길 시 const 레퍼런스 권장

//클래스
	//캡슐화, 추상화 등의 객체지향 프로그래밍 지원
	//기본 접근 지정자가 private
	//클래스 사용
	Car myCar("Sonata", 1234, 0);
	const Car yourCar("BMW", 5678, 0); //const 객체 : 멤버 변수 변경 불가
	//yourCar.setSpeed(1); 불가능
	yourCar.getSpeed(); //가능
	Car newCar(9999); //생성자 오버로딩
	cout << newCar.getSpeed() << endl;
	//상속
	Dog dog;
	//dog.eat();//불가능, 부모 클래스의 protected 멤버는 자식 클래스에서만 접근 가능
	dog.dogEat();//가능
	dog.sleep(); //오버라이딩 된 자식 클래스의 sleep() 호출
	dog.move(); //오버라이딩 된 자식 클래스의 move() 호출
}