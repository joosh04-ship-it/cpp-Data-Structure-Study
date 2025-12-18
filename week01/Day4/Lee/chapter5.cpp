#include <iostream>
using namespace std;

class SomSimple {
private:
	int num1;
	int num2;
public:
	SomSimple(int n1, int n2) : num1(n1), num2(n2) {}\
		//복사 생성자 &묵시적 변환 막기(explicit)
	explicit SomSimple(SomSimple& copy) : num1(copy.num1), num2(copy.num2) {
		cout << "Copy constructor called." << endl;
	}
	void ShowData() {
		cout << "num1: " << num1 << ", num2: " << num2 << endl;
	}
};

int main() {
	SomSimple obj1(10, 20);
	//SomSimple obj2 = obj1; // Error: 묵시적 변환이 막힘
	SomSimple obj2(obj1); // Copy constructor is called here
	obj1.ShowData();
	obj2.ShowData();
	return 0;
}

