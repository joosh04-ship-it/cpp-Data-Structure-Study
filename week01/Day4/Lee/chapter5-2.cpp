//깊은 복사 - 포인터로 참조하는 메모리까지 복사하는 것

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(string n, int a) : name(n), age(a) {}
	Person(const Person& copy) : name(copy.name), age(copy.age) {
		cout << "Copy constructor called." << endl;
	}
	void ShowData() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
	~Person() {
		// delete[] name; // string 타입은 delete[]로 해제하면 안 됩니다. 자동으로 관리됩니다.
		cout << "Destructor called for " << name << endl;
	}
};

int main() {
	Person person1("Alice", 30);
	Person person2(person1); // Copy constructor is called here
	person1.ShowData();
	delete[] & person1; // person1 소멸자 호출
	person2.ShowData(); 
	return 0;
}
