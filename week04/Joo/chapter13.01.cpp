#include<iostream>
#include <cstring>

using namespace std;

template <typename T>					// 함수 템플릿 기본형, typename 대신 class 써도 됨
T add(T num1, T num2) {					// 컴파일 할 때 함수가 만들어짐 -> 컴파일 속도 감소, 실행 속도는 그대로
	return num1 + num2;
}

template<typename A, typename B>
void showdata(double num) {
	cout << (A)num << ", " << (B)num << endl;
}

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

template<>
char* Max(char* a, char* b) {
	cout << "special char* "<<endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b) {					// template에서 문자열을 받으면 const char* 형으로 생각하기 때문에
	cout << "special const char* "<<endl;
	return strcmp(a,b)>0 ? a : b;								// string 사용 시 stirng(a)처럼 변환 해줘야함
}

//int main() {
//	cout << add<int>(15, 20) << endl;	
//	cout << add(15, 20) << endl;		
//	cout << add<double>(3.12, 5.33) << endl;
//	cout << add(3.12, 5.33) << endl; 
//	
//	showdata<char, int>(65);
//
//	cout << Max(11, 15)<<endl;
//	cout << Max('T', 'Q') << endl;
//	cout << Max("stad", "best") << endl;
//
//	char str1[] = "simple";
//	char str2[] = "best";
//	cout << Max(str1, str2) << endl;
//}