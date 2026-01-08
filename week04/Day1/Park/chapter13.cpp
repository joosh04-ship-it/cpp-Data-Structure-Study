#include <iostream>
#include "templatePractice.h"
#include <string>
#include <vector>
using namespace std;

template <typename T>
//template <class T> 라고 써도 무관
T Add(T num1, T num2) {
	return num1 + num2;
}
template<>// 특정 자료형에 대하여 특수화
const char * Add(const char * num1, const char * num2) {
	return "문자열을 더할 순 없습니다";
}
template <typename T1, typename T2>
void showData(T1 A, T2 B) {
	cout << A << endl << B << endl;
}
template<typename T>//클래스 탬플릿
class point{
public:
	T x;
	T y;
	point(T x, T y) : x(x), y(y){}
	T gop();
};
template<typename T>
T point<T>::gop() {
	return x * y;
}
//template<typename T>//템플릿 클래스의 멤버를 다른 파일에서 컴파일할 수 없음 하려면 cpp 파일을 헤더파일에 include 해주어야함.
//T Practice<T>::hamsu1() {
//	return x + y;
//}
int main()
{
//템플릿
	cout << Add<int>(1, 2) << endl;//T에 int 대입
	cout << Add<double>(1.1, 2.2) << endl;
	cout << Add(1, 2) << endl;//컴파일러에게 자료형 선택을 맡김
	cout << Add("이건 어때", "????") << endl;
	showData(1, "이렇게도 됨?");
	//오버로딩을 굉장히 자유롭게 할 수 있는 느낌?
	//point(1.1, 2.2); 클래스 탬플릿은 자료형 선택을 컴파일러에게 맡길 수는 없나봄 c++17부턴 가능
	point<double> a = point<double>(1.1, 2.2);
	cout << a.gop() << endl;
	Practice<int> b = Practice<int>(1, 2);
	//cout << b.hamsu1() << endl; //이거 안됨
	cout << b.hamsu2() << endl;

	//size를 먼저 지정해두지 않아도 됨.
	//그러면 어떤 식으로 실행이 되느냐? -> 임시로 사이즈를 미리 가지고 있다가 만약에 그것보다 더 커질 것 같다? -> 기존 벡터 파괴 후 다시 더 크게 만듦
	// -> 동적으로 크기 만들 수 있음
	vector<int> x = { 1,2,3,4,5 };
	vector<vector<int>> y;
	x.push_back(6);
	x.pop_back();
	x.insert(x.begin(), 0);
	cout << x.front();
}
