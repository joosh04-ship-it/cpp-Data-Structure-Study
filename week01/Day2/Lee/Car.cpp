#include <iostream>
#include "Car.h"
using namespace std;

void Car::InitMembers(const char* ID, int fuel) {
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState() {
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << endl;
	cout << "현재 속도: " << curSpeed << endl << endl;
}

void Car::Accel() {
	fuelGauge -= FUEL_STEP;
	if (fuelGauge <= 0) {
		fuelGauge = 0;
		return;
	}
	else {
		curSpeed += ACC_STEP;
		if (curSpeed >= MAX_SPD) {
			curSpeed = MAX_SPD;
			return;
		}
	}
}





