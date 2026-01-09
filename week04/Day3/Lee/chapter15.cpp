#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//예외를 던질 수도 있음
void Divide(int num1, int num2) {
    try {
        if (num2 == 0)
        //예외처리에 대한 책임은 함수를 호출한 영역을 넘어가게 됨
        throw num2; //예외를 던지고,
    }
    catch (int expn) {
        cout << "함수 내에서 먼저 잡기!" << endl;
        throw;
    }
    cout << "곱셈의 몫: " << num1 * num2 << endl;
}

//스택 풀기
void Func3() {
    cout << "Func3 start" << endl;
    throw 1;  // 예외 발생
    cout << "Func3 end" << endl;
}

void Func2() {
    cout << "Func2 start" << endl;
    Func3();
    cout << "Func2 end" << endl;
}

void Func1() {
    cout << "Func1 start" << endl;
    Func2();
    cout << "Func1 end" << endl;
}

//전달되는 예외의 명시
int StoI(char* str) throw (int, char) {
    int len = strlen(str);
    int num = 0;

    if (len != 0 && str[0] == '0')
        throw 0;
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i]>'9')
            throw str[i];
        num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
    }
    return num;
}

int main() {
    int num1, num2;
    string name;
    cout << "두 개의 숫자 입력: ";
    cin >> num1 >> num2;

    try { //예외를 발견하고,
        Divide(num1, num2);
        if (num2 == 0)
            throw num2; //예외를 던지고,
        cout << "나눗셈의 몫: " << num1 / num2 << endl;
        cout << "나눗셈의 나머지: " << num1 % num2 << endl;
    }
    catch (int expn) { //예외를 잡는다!
        cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
        cout << "프로그램을 다시 실행하세요." << endl;
    }
    cout << "-----------------------------" << endl;
    try {
        Func1();
    }
    catch (int e) {
        cout << "예외 잡음: " << e << endl;
    }
    cout << "-----------------------------" << endl;
    char str1[100];
    char str2[200];
    while (1) {
        cout << "두 개의 숫자 입력: ";
        cin >> str1 >> str2;
        
        //하나의 try 블록에 다수의 catch 블록 가능!!
        try {
            int res = StoI(str1) + StoI(str2);
            cout << str1 << " + " << str2 << " = " << res << endl;
            break;
        }
        catch (char ch)
        {
            cout << "문자 " << ch << "가 입력되었습니다" << endl;
            cout << "재입력 진행합니다." << endl << endl;

        }
        catch (int expn) {
            if (expn == 0)
                cout << "0으로 시작하는 숫자는 입력불가" << endl;
            else
                cout << "비정상적 입력이 이루어졌습니다." << endl;
            cout << "재입력 진행합니다." << endl << endl;
        }
    }
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}




