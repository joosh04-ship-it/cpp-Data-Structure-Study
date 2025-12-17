#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int coin = 0;
class champion {
private://정보은닉을 위해 private 접근지정자 사용
	string name;
	int cost;
	int star;
public:
	champion(string n, int c, int s) : name(n), cost(c), star(s) {}//생성자
	~champion() {//소멸자
		int coinChange;
		if (cost == 1||star==1) {
			coinChange = cost * pow(3,star-1);

		}
		else {
			coinChange = cost * pow(3, star - 1) - 1;
		}
		coin += coinChange;
		cout << name <<" " << star << "성 판매" << endl << coinChange << "코인 획득" << endl << "현재 코인 : " << coin << endl<<endl;
	}
	string getName() {
		return name;
	}
	int getCost() {
		return cost;
	}
	int getStar() {
		return star;
	}
	void setStar(int star) {
		if (star < 1 || star > 4) {
			cout << "Error1" << endl;
			return;
		}
		this->star = star;//this포인터, 멤버변수와 매개변수 이름이 같을 때 구분하기 위해 사용 혹은 강조하고 싶을 때 사용해도 됨
	}
	void setName(string name) {
		this -> name = name;
	}
	void setCost(int cost) {
		this -> cost = cost;
	}
	void starUp() {
		if (star < 4) {
			star++;
		}
	}
};
int main() {
	champion* myChampions[10];
	myChampions[0] = new champion("Yunara", 4, 1);//유나라이즈 덱 생성
	myChampions[1] = new champion("Ryze", 7, 1);
	myChampions[2] = new champion("Ashe", 2, 1);
	myChampions[1]->starUp();//라이즈 2성
	cout << "Total coin: " << coin << endl;
	delete myChampions[1];
	myChampions[0]->starUp();//유나라 2성
	myChampions[0]->starUp();//유나라 3성
	delete myChampions[0];
	delete myChampions[2];
	coin = 0;//코인 초기화

	champion* deck = new champion[9]{
	   {"유나라", 4, 2},
	   {"라이즈", 7, 2},
	   {"오공", 4, 2},
	   {"타릭", 4, 2},
	   {"리산드라", 4, 2},
	   {"케넨", 3, 2},
	   {"코부코&유미", 3, 2},
	   {"세주아니", 3, 2},
	   {"애쉬", 2, 2}
	};
	delete[] deck;
	deck = nullptr;
}