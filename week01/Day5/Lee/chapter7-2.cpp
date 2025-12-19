
#include <iostream>
using namespace std;

class SoBase {
private:
    int baseNum;
public:
    //SoDerived함수에서 명시 안하면 기본 생성자 자동 호출, 없으면 컴파일 에러
    SoBase() : baseNum(20) {
        cout << "Sobase()" << endl;
    }
    SoBase(int n) : baseNum(n) {
        cout << "SoBase(int n)" << endl;
    }
    void ShowBaseData() {
        cout << baseNum << endl;
    }
    ~SoBase() {
        cout << "삭제된 SoBase(): " << baseNum << endl;
    }
};

class SoDerived : public SoBase {
private:
    int derivNum;
public:
    SoDerived() : derivNum(30) {
        cout << "SoDerived()" << endl;
    }
    SoDerived(int n) : derivNum(n) {
        cout << "SoDerived(int n)" << endl;
    }
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) {
        cout << "SoDerived(int n1, int n2)" << endl;
    }
    void ShowDerivData() {
        ShowBaseData();
        cout << derivNum << endl;
    }
    //소멸 순서: ①생성순서와 반대 ②유도 -> 기초 클래스
    ~SoDerived() {
        cout << "삭제된 SoDerived(): " << derivNum << endl;
    }

};
//기초클래스의 멤버변수가 먼저 초기화 후 유도 클래스의 멤버변수 초기화
int main() {
    cout << "case1..." << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "-------------------------------" << endl;
    cout << "case2..." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "-------------------------------" << endl;
    cout << "case3..." << endl;
    SoDerived dr3(23,24);
    dr3.ShowDerivData();
    cout << "-------------------------------" << endl;

}
