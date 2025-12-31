#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrlen;
	Array(const Array& arr) {};//복사를 막아버리겠다!
	Array& operator =(const Array& arr) {};//대입을 막아버리겠다!
public:
	Array(int len) :arrlen(len) {//생성은 이렇게 가능
		arr = new int[len];
	}
	int getArrlen() const {
		return arrlen;
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "배열 범위 오류" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "배열 범위 오류" << endl;
			exit(1);
		}
		return arr[idx];
	}
	~Array() {
		delete[] arr;
	}
};
void showArr(const Array& ref) {
	for (int i = 0; i < ref.getArrlen(); i++) {
		cout << ref[i] << " ";
	}
	cout << endl;
}
class Person {//대충만든 클래스
public:
	int age;
	int num;
};
class PersonArr {//객체의 배열도 이런 식으로 정의할 수 있다!!!!
public:
	Person* arr;
	int arrlen;
	PersonArr(int len) :arrlen(len) {//생성은 이렇게 가능
		arr = new Person[len];
	}
	int getArrlen() const {
		return arrlen;
	}
	Person& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "배열 범위 오류" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Person& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "배열 범위 오류" << endl;
			exit(1);
		}
		return arr[idx];
	}
	~PersonArr() {
		delete[] arr;
	}
};
int main() {
	Array arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
	//for (int i = 0; i < 6; i++) {
	//	cout << arr[i];//오류 메시지가 출력되고 접근이 막아짐
	//}
	showArr(arr);
	PersonArr PArr(5);
	PArr[1].age = 1;
	PArr[2].num = 2;
}