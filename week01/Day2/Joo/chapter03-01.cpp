#include <iostream>

#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

using namespace std;

struct car {
	char gamerID[20];
	int fuelGauge;
	int curSpeed;
	
	void ShowCarState() {					//단순 출력만을 위한 함수 -> const 참조자 사용
		cout << "소유자 ID : " << gamerID << endl;	//구조체안에 함수 생성 가능
		cout << "연료량 : " << fuelGauge << endl;
		cout << "현재속도 : " << curSpeed << endl;
	}													

	void ShowMyName();						// 함수의 원형선언
}; 

void car::ShowMyName() {					// 함수의 정의를 구조체 밖으로 빼냄
	cout << gamerID << endl;
}

void Accel(car& car) {
	if (car.fuelGauge <= 0)
		return;						//연료량이 0이거나 더 작을경우 리턴
	else
		car.fuelGauge -= FUEL_STEP;
	
	if (car.curSpeed + ACC_STEP >= MAX_SPD) {
		car.curSpeed = MAX_SPD;
		return;						//현재속도가 최고속도일경우 리턴
	}

	car.curSpeed += ACC_STEP;		
}			

int main() {
	car JooCar = { "JooCar",100,0 };	// 별도의 typedef없이 변수 선언 가능
										// typedef car { 
										//	 ~~~~	
										//   }JooCar;
	Accel(JooCar);
	JooCar.ShowCarState(JooCar);
}