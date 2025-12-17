/*
#include <iostream>
using namespace std;

class SinivelCap {
	public:
		void Take() const{
			cout << "SinivelCap taken. Feeling better!\n";
		}
};

class SneezeCap {
	public:
		void Take() const { //const를 붙이는 이유: 멤버 함수가 객체의 상태를 변경하지 않음을 보장하기 위해
			cout << "SneezeCap taken. Achoo! Feeling relieved!\n";
		}
};

class CONTAC600 {
	private:
		SinivelCap sin;
		SneezeCap snee;

	public:
		void Take() const {
			sin.Take(); //void Take() const가 아니면 오류 발생 -> const 멤버 함수 내에서는 non-const 멤버 함수를 호출할 수 없음
			snee.Take();
			cout << "CONTAC600 taken. You should feel much better now!\n";
		}
};

class ColdPatient {
	public:
		void TakeContac600(const CONTAC600& medicine) const {
			medicine.Take();
		}
};

int main()
{
	CONTAC600 contac;
	ColdPatient patient;
	patient.TakeContac600(contac);
	return 0;
} // 캡슐화 예제: ColdPatient가 CONTAC600의 내부 구조를 알 필요 없이 복합 약물을 복용할 수 있음
// 캡슐화 = 객체 내부의 데이터와 동작을 하나로 묶고,
//외부에는 필요한 것만 공개하여 내부를 보호하는 것
*/


#include <iostream>
using namespace std;

class SimpleClass {
	private:
		int num;
	public:
		SimpleClass(int n) { num=n; } //const int &n으로 해도 됨
		
		SimpleClass() : num(0) {} //이니셜라이저 리스트를 사용한 기본 생성자, num을 0으로 초기화, 바이너리 호환성 유지에 유리
		//const 맴버 변수를 초기화할 때 반드시 이니셜라이저 리스트를 사용해야 함
		void ShowNum() const { cout << "Number: " << num << endl; }
};

int main()
{
	SimpleClass obj1(42); //매개변수가 있는 생성자 호출
	SimpleClass obj2;     //기본 생성자 호출 
	SimpleClass* pObj = new SimpleClass(); //동적 할당 시에도 매개변수 있는 생성자 호출 가능
	// SimpleClass obj2()가 안되는 이유: 함수 선언으로 해석되기 때문
	obj1.ShowNum();
	obj2.ShowNum();
	pObj->ShowNum();
	return 0;
} // 생성자 오버로딩 예제: 다양한 방법으로 객체 초기화 가능

//SimpleClass obj2() {
//		내용;
//}
