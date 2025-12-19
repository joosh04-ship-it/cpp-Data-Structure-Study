//상속자
//7-4설명도 겸비 <<상속을 위한 조건>>
#include <iostream>
#include <cstring>

using namespace std;

class Person {
	private:
	string name;
	int age;
public:
	Person(const string& n , int a ) : age(a), name(n) {}
	void WhatYourName() const {
		cout << "My name is " << name << "." << endl;
	}
	void HowOldAreYou() const {
		cout << "I am " << age << " years old." << endl;
	}
};

//UnivStudent의 멤버함수 내에서는 Person의 멤버변수에 직접 접근 불가
//UnivStudent → Person의 public 함수 호출
//Person → 자신의 private 멤버 접근
class UnivStudent : public Person { // Person 클래스를 상속
	private:
		string major;
public:
	UnivStudent(const string& n = "noname", int a = 20, const string& m = "Nothing")
		: Person(n, a), major(m) {}
	void WhoAreYou() const {
		WhatYourName();
		HowOldAreYou(); // 상속받은 메서드 호출
		cout << "My major is " << major << "." << endl;
		cout << "---------------" << endl;
	}
};

int main() {
	UnivStudent ustd1("Alice", 20, "Computer Science");
	UnivStudent ustd2("kevin");
	UnivStudent ustd3;
	ustd1.WhoAreYou(); // UnivStudent의 메서드 호출
	ustd2.WhoAreYou();
	ustd3.WhoAreYou();
	return 0; 
}

//IS-A관계 "대학생은 일종의 사람이다"
//HAS-A관계 "경찰은 총을 소유한다"
//EX)기초 클래스 "총" - 유도 클래스 "경찰"