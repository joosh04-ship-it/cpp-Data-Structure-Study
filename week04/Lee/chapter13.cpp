// <<템플릿>> : 자료형(타입)에 의존하지 않는 일반화된 코드

#include <iostream>
#include <cstring>
using namespace std;

//함수 템플릿
template <typename T>
T add(T num1, T num2) {
    return num1 + num2;
}


template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

//함수 템플릿의 특수화 (이 함수는 새로운 템플릿이 아니다)
template <>
char* Max(char* a, char* b) {
    cout << "char* Max<char*>(char* a, cahr* b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b) {
    cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
    return strcmp(a, b) > 0 ? a : b;
}

template <class T1, class T2>
//double num을 각각 T1, T2 타입으로 형 변환
void showData(double num) {
    cout << (T1)num << "," << (T2)num << endl;
}

int main()
{
    cout << add<int>(15, 20) << endl;
    cout << add<double>(2.9, 3.7) << endl;
    cout << add<int>(3.2 , 3.2 ) << endl;
    showData<char, int>(65);
    showData<char, double>(68.9);
    showData<short, double>(70.4);
    //명시적으로 템플릿 인자를 지정
    //showData(70) (x)
    char str1[] = "simple";
    char str2[] = "best";
    cout << Max(str1, str2);
    
}


