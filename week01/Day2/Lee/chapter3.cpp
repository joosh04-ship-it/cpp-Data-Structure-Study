
#include <iostream>
#include "Car.h"
using namespace std;


/*
namespace CAR_CONST {
    enum {
        ID_LEN = 20,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
        MAX_SPD = 200,
        MIN_SPD = 0
    };
}
*/

// 구조체: 관련된 변수와 함수를 묶어서 관리하는 사용자 정의 자료형

/* 

struct Car {
    enum {
        ID_LEN = 20,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
        MAX_SPD = 200,
        MIN_SPD = 0
    };

	char gamerID[ID_LEN]; //위 주석처럼 enum 선언 시 namespace CAR_CONST::ID_LEN
    int fuelGauge;
    int curSpeed;
    //c++은 구조체 안에서 함수 선언가능!
    void ShowCarState() {
        cout << "소유자 ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << endl;
		cout << "현재 속도: " << curSpeed << endl << endl;
    }

    void Accel() { // struct문 밖이였으면 void Accel(Car &car)
        fuelGauge -= FUEL_STEP;
    }

    void Break(); //함수를 외부로 뺄 수도 있음 = 45번째 줄

};

void Car::Break() {
    curSpeed -= BRK_STEP;
    return;
}

int main()
{
    Car run99 = { "run99", 100, 0 };
    run99.Accel();
	run99.Break();
    run99.ShowCarState();

}
*/

// 클래스: 구조체의 기능을 확장한 사용자 정의 자료형
/*
class Car {
    enum {
        ID_LEN = 20,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10,
        MAX_SPD = 200,
        MIN_SPD = 0

    };

    private: //접근 지정자: 멤버변수와 멤버함수의 접근 범위를 지정
        char gamerID[ID_LEN];
        int fuelGauge;
		int curSpeed;
    public:

       //void Cart(char* ID, int fuel) { // 함수 호출
		Car(const char* ID, int fuel) { //생성자 호출, const가 붙는 이유는 문자열 리터럴은 변경 불가능하기 때문
            strcpy_s(gamerID, ID);
            fuelGauge = fuel;
            curSpeed = 0;
        }
        void ShowCarState() {
            cout << "소유자 ID: " << gamerID << endl;
            cout << "연료량: " << fuelGauge << endl;
            cout << "현재 속도: " << curSpeed << endl << endl;
        }
        void Accel() {
            if (fuelGauge <= 0) return;
            fuelGauge -= FUEL_STEP;
            curSpeed += ACC_STEP;
            if (curSpeed > MAX_SPD)
                curSpeed = MAX_SPD;
        }
        void Break() {
            curSpeed -= BRK_STEP;
            if (curSpeed < MIN_SPD)
                curSpeed = MIN_SPD;
		}

};
*/
int main()
{
	Car run99;
	Car* pCar = new Car();
    run99.InitMembers("run99", 100);
	//Car run99("run99", 100);

    run99.Accel();
    run99.Break();
    run99.ShowCarState();
}