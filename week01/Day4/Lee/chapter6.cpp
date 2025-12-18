//friend 함수: 클래스 외부에 정의되지만 해당 클래스의 private 멤버에 접근할 수 있는 함수입니다.
// 단점: 정보 은닉성을 약화시킬 수 있습니다.
// 장점: 두 클래스 간의 긴밀한 상호작용이 필요할 때 유용합니다.
//

#include <iostream>
#include <string>

using namespace std;

class Girl;

class Boy {
private:
	int height;
	friend class Girl; //이건 내부 구현과 관련된 비공개 관계라는 느낌
public:
	Boy(int h) : height(h) {}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl {
	private:
		string phoneNumber;
public:
	Girl(string pn) : phoneNumber(pn) {};
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Girl::ShowYourFriendInfo(Boy& frn) {
	cout << "My friend's height is " << frn.height << "cm." << endl;
}

void Boy::ShowYourFriendInfo(Girl& frn) {
	cout << "My friend's phone number is " << frn.phoneNumber << "." << endl;
}


int main() {
	Boy boy(170);
	Girl girl("010-1234");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}