#include <iostream>

#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

using namespace std;

class car {
private:	//클래스 내(클래스 내에 정의된 함수)에서만 접근허용
			//클래스에서는 별도의 선언이 없으면 private 선언 된 것으로 인식
	char gamerID[20];
	int fuelGauge;
	int curSpeed;

public:		//어디서든 접근 허용
			//구조체에서는 별도의 선언이 없으면 public 선언 된 것으로 인식

	void InitMember(const char *ID,int fuel);
	void ShowCarState();		
	void Accel();
};

void car::InitMember(const char *ID,int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}		// private에 gamerID등.. 변수가 선언되었으므로 
		// car JooCar = {"JooCar",100,0}; 불가능

void car::ShowCarState() {
	cout << "소유자 ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << endl;
	cout << "현재속도 : " << curSpeed << endl;
}

void car::Accel() {
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= FUEL_STEP;

	if (curSpeed + ACC_STEP >= MAX_SPD) {
		curSpeed = MAX_SPD;
		return;	
	}

	curSpeed += ACC_STEP;
}

int main() {
	car JooCar;
	car* ParkCar = new car;		//class 동적할당 방식으로 선언
	JooCar.InitMember("JooCar", 100);
	ParkCar->InitMember("ParkCar", 50);
	delete ParkCar;				//해제
}


