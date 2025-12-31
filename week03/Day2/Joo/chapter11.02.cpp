#include <iostream>
#include <string>

using namespace std;

class simple {
	int* arr;
	int arrlen;
public:
	simple(int len):arrlen(len){
		arr = new int[arrlen];
	}

	int& operator[](int ii) {
		if (ii < 0 || ii >= arrlen) {
			cout<< "array index out of bound exception" << endl;
			
		}
		return arr[ii];
	}
	~simple() {
		delete []arr;
	}
};

int main() {
	simple a(5);
	for (int i = 0; i < 5; i++)					// 기본 배열은 경계 검사를 하지 않아, 엉뚱한 코드가 만들어 질 수 있는 반면,
		a[i] = (i + 1) * 11;					// 배열 클래스는 arr[-1] 등의 엉뚱한 코드를 막을 수 있다.
	for (int i = 0; i < 9; i++)					
		cout << a[i] << endl;
}

// new등을 이용해 클래스가 직접 자원을 관리하면 1.소멸자 2.복사 생성자 3.대입 연산자를 직접 선언 해줘야함.
// -> string 사용 시 따로 대입 연산자, 복사 생성자 선언 필요 없는 이유