#include <iostream>
using namespace std;

void Divide(int num1,int num2) {
	if (num2 == 0) {
		throw num2;										// 예외데이터 전달은 함수의 반환과 유사.
	}
	cout << "나눗셈 몫: " << num1 / num2 << endl;
	cout << "나눗셈 나머지: " << num1 % num2 << endl;
}

void Try(int num1,int num2) {
	try {														//예외발생 검사의 범위를 지정하는 try 블록
		Divide(num1, num2);
		cout << "나눗셈 끝~" << endl;
	}
	catch (int expn) {												//try블록에서 발생한 예외를 처리하는 코드(반드시 try블록 뒤에 와야함)
		cout << "제수는 " << expn << "이 될 수 없습니다" << endl;	//catch블록의 매개변수는 throw절에 의해 던져진 변수와 자료형이 동일 해야함(아니면 예외처리 안됨)
	}
}
void simple3() {
	throw -1;
}
void simple2() {
	simple3();
}
void simple1() {
	simple2();
}

void OneTTwoC(int num1) throw(int,char) {				//어떤 자료형을 던지는지 명시
	if (num1 == 0) {
		throw 1;
	}
	if (num1 == 1) {
		throw 'i';
	}
}

class Error {											// 예외 클래스, 상속을 이용하면 정리해서 사용 가능
public:
	int num1;
	Error(int num1):num1(num1){}
	virtual void showerror() const {

	}
};

class FileError : public Error{
public:
	FileError(int num): Error(num){}
	void showerror() const{
		cout << "FileError: " << num1 << endl;
	}
};

class ServerError : public Error {
public:
	int num;
	ServerError(int num) :Error(num){}
	void showerror() const {
		cout << "ServerError: " << num1 << endl;
	}
};

void func(int num) {
	if (num == 1) {
		throw FileError(100);
	}
	else if(num==2){
		throw ServerError(200);
	}
	else {
		throw Error(300);
	}
}


int main() {
	int num1, num2;
	num1 = 100;
	num2 = 0;
	
	Try(num1, num2);

	//////////////////////////////////////////////////////////////////////////////////////////////

	try {
		simple1();									//main->simple1->simple2->simple3 순으로 스택 쌓임
	}												//simple3->simple2->simple1->main 순으로 스택 풀림
	catch(int expn){	
		cout << "예외코드: "<< expn << endl << endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	int num3 = 0;
	try {
		OneTTwoC(num3);
	}
	catch (int expn) {
		cout << "인트 예외! " << expn <<endl << endl;
	}
	catch (char expn) {
		cout << "차 예외! " << expn << endl << endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	try {
		func(0);
	}
	catch (const FileError& e) {   // 자식 -> 부모 순서
		e.showerror();             // FileError에서 처리
	}
	catch (const ServerError& e) {
		e.showerror();             // ServerError에서 처리
	}
	catch (const Error& e) {
		e.showerror();             // 그 외 Error에서 처리
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	try {

	}
	catch (...) {				//catch가 자료형에 상관없이 모든 예외를 받겠다는 선언

	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	int num5 = 0;
	try {
		try {
			if (num5 == 0){
				throw 1;
			}
		}
		catch (int a) {
			cout << "first catch" << endl;
			throw 1;								//예외 다시 던지기
		}
	}
	catch (int a) {
		cout << "second catch" << endl << endl;
	}
	cout << "end of main" << endl;
}