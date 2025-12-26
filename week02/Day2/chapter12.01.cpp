#include <iostream>
#include <string>

using namespace std;

int main() {
	string std1;
	string std2;
	string *std3 = new string();		// string 동적할당
	string std4;

	getline(cin, std4);					// getline을 이용해 공백이 포함된 문자열 입력

	std1 = "Park";						// string 생성
	std2 = " Babo";

	*std3 = std1 + std2;				// string 더하기

	std1 += std2;						// += 연산자

	cout << std1 << endl;				

	if (std1 == *std3) {				// == 연산자 비교
		cout << "Lee Babo";
	}

	return 0;
	}
