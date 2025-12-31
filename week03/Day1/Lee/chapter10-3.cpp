#include <iostream>
namespace mystd {
	using namespace std;

	class ostream {
public:
    ostream& operator<<(const char* str) {
        printf("%s", str);
        return *this;
    }
    ostream& operator<<(char str) {
        printf("%c", str);
        return *this;
    }
    ostream& operator<<(int num) {
        printf("%d", num);
        return *this;
    }
    ostream& operator<<(double e) {
        printf("%g", e);
        return *this;
    }
    ostream& operator<<(ostream& (*fp)(ostream&)) {
        return fp(*this);
    }
};

	ostream& endl(ostream& ostm) {
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main(void) {
    using mystd::cout;
	using mystd::endl;


	
    cout << 3.14;
    cout << endl;
    cout << "Simple String"<<endl<<123123<<endl; //return *this 안하면 컴파일 에러!
    //<<연산자를 활용한 예시는 chapter 10-2에 존재
}
