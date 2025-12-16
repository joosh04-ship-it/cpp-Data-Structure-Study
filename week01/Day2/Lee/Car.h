#ifndef __CHAPTER3_CAR_H__
#define __CHAPTER3_CAR_H__
class Car {
	enum {
		ID_LEN = 20,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10,
		MAX_SPD = 200,
		MIN_SPD = 0
	};
private: // 이게 없어도 기본 접근 지정자는 private
		char gamerID[ID_LEN];
		int fuelGauge;
		int curSpeed;
	public:
		void InitMembers(const char* ID, int fuel); //초기화 멤버 함수 선언
		void ShowCarState();
		void Accel();
		inline void Break() { //inline 함수는 헤더파일에 작성, 이유는 컴파일러가 호출되는 곳에 코드를 삽입하기 때문
			curSpeed -= BRK_STEP;
			if (curSpeed <= 0) {
				curSpeed = 0;
				return;
			}
		}

		

};
#endif 
