#include <iostream>
using namespace std;
class Exception {
public:
	virtual void showExceptReason() const = 0;
};
class DevideInZeroException: public Exception {//예외상황을 알리고자 만드는 클래스
private:
	int b;
public:
	DevideInZeroException(int b) : b(b) {

	}
	void showExceptReason() const{
		cout << b << "로 나눌 수는 없습니다...예외클래스" << endl;
	}
};
class DevideException : public Exception {//이런식으로 상속받으면 여러가지 형태의 예외를 부모클래스인 동일한 형태로 내보낼 수 있음
private:
	int b;
public:
	DevideException(int b) : b(b) {

	}
	void showExceptReason() const {
		cout << b << "로 나눌 수 있는데 예제라서 예외로했습니다." << endl;
	}
};

void devide(int a, int b) {
	if (b == 0) {
		throw b;
	}
	if (b == 1) {
		string s = "스트링던지기!";
		throw s;
	}
	if (b == -1) {
		throw DevideInZeroException(b);
	}
	if (b == 2) {
		throw DevideException(b);
	}
	if (b == 3) {
		throw "이건 어떻게할래?";
	}
	cout << a / b << endl;
}
void catchBall2(int ball);
void catchBall1(int ball) {
	try {
		if (ball < 90) {
			cout << ball << "던져" << endl;
			throw ball + 1;
		}
		cout << "캐치볼 끝~" << endl;
	}
	catch (int b) {
		catchBall2(b);
		//여기 안에 throw를 넣는 것도 가능
	}
}
void catchBall2(int ball) {
	try {
		if (ball < 90) {
			cout << ball << "던져" << endl;
			throw ball + 1;
		}
		cout << "캐치볼 끝~" << endl;
	}
	catch (int b) {
		catchBall1(b);
	}
}
int main()
{
//예외처리
	//ifelse문을 이용
	int a = 2;
	int b;
	cin >> b;
	if (b == 0) {
		cout << "0으로 나눌 수 없습니다 ifelse" << endl;
	}
	else {
		cout << a / b << endl;
	}
	//try catch throw
	try {//코드 외부에서 예외처리를 하는 의미가 있다.
		if (b == 0) {
			throw b;//여기서 던지는 자료형이랑
		}
		cout << a / b << endl;
	}
	catch(int expn){//여기서 받는 자료형이 동일해야함.
		cout << "0으로 나눌 수 없습니다 catch" << endl;
	}

	try {//함수의 경우 throw만해주면 사용하는 곳에서 try catch로 감싸면 됨
		devide(a, b);
	}
	catch (int expn) {
		cout << "0으로 나눌 수 없습니다 hamsu" << endl;
	}
	catch (string) {//catch를 여러개 해서 여러 종류를 던질수도있음
		cout << "스트링을 던졌습니다" << endl;
	}
	catch (const Exception& exp) {//예외클래스의 이용
		exp.showExceptReason();
	}
	catch (...) {//프로그램이 터져버리는 것을 막는 코드라고한다. 예외의예외임.
		cout << "예외의예외" << endl;
	}
	//catch 여러개 쓸떄는 구체적인걸 위로 why? ifelse문처럼 작동하기때문
	//throw가 try catch에 감싸져있지 않으면 프로그램 종료
	//참고 : 책에는 void withdraw(int money) throw (WithdrawException) {} 이라는 함수 정의를 사용하고 있는데 C++14 이후로는 이와 같은 문법을 지원하지 않는다
	catchBall1(0);
}