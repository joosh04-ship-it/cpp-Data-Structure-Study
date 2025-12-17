#include <iostream>
using namespace std;
//friend
class LEE;
class PARK;
void voiceFishing(PARK&);
class JOO {
private:
	void JooshPrivate() {
		cout << "주승현 비밀 접근" << endl;
	}
	friend class LEE;// 특정 클래스를 프랜드로 지정 시 그 클래스에서 이 클래스의 private과 protected를 접근할 수 있음
};
class PARK {
private:
	friend void voiceFishing(PARK&);//전역함수도 프랜드로 지정 가능
	void ParkPJPrivate() {
		cout << "박평준은 비밀이 없음" << endl;
	}
public:
	void hackingJS(LEE&);
};
class LEE {
private:
	void LeeJSPrivate() {
		cout << "이진서 비밀 정보" << endl;
	}
	friend void PARK::hackingJS(LEE& lee);//다른 클래스의 멤버함수 하나만 지정해서 친구로 지정도 할 수 있음
public:
	JOO joo;
	void hackingSH() {
		joo.JooshPrivate();
	}

};
void PARK::hackingJS(LEE& lee) {
	lee.LeeJSPrivate();
}
void voiceFishing(PARK& park) {
	park.ParkPJPrivate();
}
int main()
{
//friend
	LEE JS;
	JS.hackingSH();
	PARK PJ;
	PJ.hackingJS(JS);
	voiceFishing(PJ);
}
//mutable: const 함수에서도 변경 가능
//static함수 : static 변수만 내부에 사용 가능
//class명::함수명으로 사용 가능
