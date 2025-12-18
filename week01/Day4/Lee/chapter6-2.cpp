//static이란 
//static: c++에서는 멤버변수나 멤버함수에 선언을 할 수 있음
//객체의 멤버가 아닌 클래스의 멤버로 존재


#include <iostream>
using namespace std;

class SoSimple {
private:
	static int simObjCnt; //정적 멤버 변수 선언
	int num;
public:
	static int testy;
	const static int Korea = 888888222222; //정적 상수 멤버 변수 선언 및 초기화


	SoSimple() {
		simObjCnt++;
		testy++;
		cout << simObjCnt << "번쨰SoSimple 생성자 호출!" << endl;
	}
	static void ShowObjectCnt() { //정적 멤버 함수 선언
		//num++; //에러: 정적 멤버 함수에서는 비정적 멤버 변수에 접근 불가
		cout << "SoSimple 객체 수: " << simObjCnt << endl;
	}
};
//static 변수를 클래스 내부에서 초기화할 시 오류 발생
//이유: 정적 멤버 변수는 클래스의 모든 객체가 공유하는 변수이기 때문에, 클래스 정의 외부에서 한 번만 초기화
int SoSimple::simObjCnt = 0; //정적 멤버 변수 정의 및 초기화
int SoSimple::testy = 0;


class SoComplex {
	private:
		static int cmxObjCnt;
public:
	SoComplex() {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 생성자 호출!" << endl;
	}
	SoComplex(const SoComplex& copy) {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 복사 생성자 호출!" << endl;
	}
};

int SoComplex::cmxObjCnt = 0; //정적 멤버 변수 정의 및 초기화



//mutable: 상수 멤버 함수 내에서도 수정할 수 있는 멤버 변수를 선언할 때 사용
class mtblExample {
private:
	mutable int callCount; //mutable 멤버 변수 선언
	int data;
public:
	mtblExample(int d) : data(d), callCount(0) {}
	void ShowData() const { //상수 멤버 함수
		callCount++; //mutable 멤버 변수는 상수 멤버 함수 내에서도 수정 가능
		cout << "Data: " << data << ", ShowData 호출 횟수: " << callCount << endl;
	}
	void CopyData() const {
		callCount = data;
	}
};




int main() {
	SoSimple obj1;
	SoSimple obj2;

	//obj1.simObjCnt = 100; //-> 에러: 정적 멤버 변수는 객체를 통해 접근 불가
	//SoSimple::simObjCnt = 100; -> 에러: private 멤버 변수이므로 클래스 이름으로 접근 불가
	obj1.ShowObjectCnt();
	//SoSimple::testy = 100; -> 정상: public 멤버 변수이므로 클래스 이름으로 접근 가능
	obj1.testy = 100;
	cout << "testy: " << obj2.testy << endl;
	SoComplex obj3;
	SoComplex obj4 = obj3; //복사 생성자 호출
	SoComplex();


	cout << "Korea constant: " << SoSimple::Korea <<obj1.Korea << endl;

	mtblExample mtbl(20);
	mtbl.ShowData();
	mtbl.CopyData();
	mtbl.ShowData();


	return 0;
}
