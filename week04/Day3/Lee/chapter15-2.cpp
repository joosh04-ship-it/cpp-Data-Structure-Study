//예외 클래스와 예외 객체
#include <iostream>
#include <cstring>
#include <new>
using namespace std;

//상속 관계가 있는 예외 클래스

class MyException {
public:
    virtual void ShowInf() = 0;
};

class PJ : public MyException {
private:
    string name;
public:
    PJ(string name) : name(name) {}
    void ShowInf() {
        cout << "[평주니 예외 메시지: " << name << "(이)는 출입 불가]" << endl;
    }
};

class SH : public MyException {
private:
    string name;
public:
    SH(string name) : name(name) {}
    void ShowInf() {
        cout << "[승혀니 예외 메시지: " << name << "(이)는 출입 불가]" << endl;
    }
};

class GoPeople {
private:
    string name;
public:
    GoPeople(string n) : name(n) {}
    void NoEnter(string n) throw (PJ) {
        if (n == "평준") {
            PJ expn(n);
            throw expn;
        }
        else if (n == "승현") {
            SH expn(n);
            throw expn;
        }
        cout << n<<"이라는 친구는 통과" << endl;
    }
};



int main()
{
    GoPeople myacc("친구");
    string who;
    while (1) {

        if (who == "끝내기")

        cin >> who;
        try {
            myacc.NoEnter(who);
            
        }
        catch (MyException& expn) {
            
            expn.ShowInf();
        }
    }
    

    //프로그래머가 정의하지 않아도 발생하는 예외
    /*
    int num = 0;

    try {
        while (1) {
            num++;
            cout << num << "번째 할당 시도" << endl;
            new int[10000][10000];
        }
    }

    catch (bad_alloc& bad) {
        cout << bad.what() << endl;
        cout << "더 이상 할당 불가!" << endl;
    }
    */
}
