#include <iostream>
#include <string>
using namespace std;

template <class T>
class Point {
private:
	T x, y;
public:
	Point(T x, T y) : x(x), y(y) {

	}
	void showPoint() {
		cout << x << ", " << y << endl;
	}
	friend Point<T> operator+<T> (const Point<T>&, const Point<T>&);//operator+ 뒤의 <T> 필요 
};

template<class T>//이렇게 하면 연산자 오버로딩 함수마저 템플릿 T에 대하여 만들 수 있음!!!
Point<T> operator+ (const Point<T>& a, const Point<T>& b) {
	return Point<T>(a.x + b.x, a.y + b.y);
}

template <>//이런 식으로 특수화 사용 가능
class Point<string> {
private:
	string x, y;
public:
	Point(string x, string y) : x(x), y(y) {

	}
	void showPoint() {
		cout << x << ", " << y << "네, 스트링입니다" << endl;
	}
};
template<class T1, class T2>//템플릿 동시에 여러개도 쓸 수 있음 이런식으로
class Part {
public:
	T1 a;
	T2 b;
	void hamsu() {
		cout << a << endl << b << endl;
	}
};
//여러개 쓸때 하나만 특수화 할수도 ㄷㄷ
template<class T2>
class Part<int, T2> {
public:
	int a;
	T2 b;
	Part<int, T2>(int a, T2 b) : a(a), b(b) {}
	void hamsu() {
		cout << "저는 일부만 특수화된 클래스 템플릿 입니다."<<endl;
		cout << a << endl << b << endl;
	}
};
template<class T, int a=1>//템플릿 인자 인자 값에 의해 자료형을 나누어야할 때 사용하면 좋다. 또 디폴트 값도 지정 가능
class inza {
public:
	static int s;
	T b;
	inza(int b) : b(b) {};
	void hamsu()
	{
		cout << a << endl << b << endl;
	}
};
template<class T, int a>
int inza <T, a>::s = 0;//클래스 템플릿을 쓰려면 이런 식으로 꼭 밖에서 초기화를 해주어야한단다~
template<>
int inza <int, 3>::s = 10000;
int main()
{
	Point<int> A(1,2); // 일반 클래스 처럼 템플릿 클래스 데이터도 저장 가능
	Point<int> B(2, 3);
	Point<int> C = A + B;
	Point<string>  D("스트링", "입니까?");
	C.showPoint();
	D.showPoint();
	Part<int, string> E(0, "ㅎㅇ");
	E.hamsu();
	inza<int, 3> F(4);//근데 그냥 변수같은데 왜쓰냐? -> 자료형을 구분지을 필요가 있을 떄 사용하면 됨
	F.hamsu();
	inza<int, 4> G(4);
	inza<int, 2>::s = 3;
	inza<int, 4>::s = 4;

	cout << inza<int, 2>::s << endl;//3출력. 템플릿에 들어가있는게 다르면 다른 자료형으로 인식되기 때문에 스태틱 변수도 여러개 저장되는 것.
	cout << inza<int, 3>::s << endl;//이런식으로 템플릿 클래스에 있는 스태틱 변수도 특수화가 가능하다. 이런식으로 int형 인자 자체를 특수화하는 것도 가능
}
