// <클래스 템플릿의 특수화>
//특정 자료형을 기반으로 생성된 객체에 대해, 구분이 되는 다른 행동양식을 적용하기 위해

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class SimpleDataWrapper {
private:
    T mdata;
public:
    SimpleDataWrapper(T data) : mdata(data) {};
    void ShowDataInfo(void) {
        cout << "Data: " << mdata << endl;
    }
};

template <>
class SimpleDataWrapper <const char*> {
private:
    char* mdata;
public:
    SimpleDataWrapper(const char* data) {
        mdata = new char[strlen(data) + 1];
        strcpy_s(mdata, strlen(data) + 1, data); //책은 strcpy인데 그렇게 하면 컴파일러 오류: 코드는 맞는데 정책 때문에 막힘
                                                 //_s쓰라고 강요, 그냥 string이 짱임
    }
    void ShowDataInfo(void) {
        cout << "String: " << mdata << endl;
        cout << "Length: " << strlen(mdata) << endl;
    }
    ~SimpleDataWrapper() {
        delete[] mdata;
    }
};

template <>
class SimpleDataWrapper<string> {
private:
    string mdata;
public:
    SimpleDataWrapper(const string& data) : mdata(data) {}
    void ShowDataInfo() {
        cout << "String: " << mdata << endl;
        cout << "Length: " << mdata.length() << endl;
    }
};


//클래스 템플릿의 부분 특수화

template <typename T1, typename T2>
class Simple {
public:
    void WhoAreYou() {
        cout << "Size of T1: " << sizeof(T1) << endl;
        cout << "Size of T2: " << sizeof(T2) << endl;
        cout << "<typename T1, typename T2>" << endl;
    }
};

template <>
class Simple<int, double> {
public:
    void WhoAreYou() {
        cout << "Size of int: " << sizeof(int) << endl;
        cout << "Size of double: " << sizeof(double) << endl;
        cout << "<int, double>" << endl;
    }
};
//T2를 부분 특수화
template <typename T1>
class Simple<T1, double> {
public:
    void WhoAreYou() {
        cout << "Size of T1: " << sizeof(T1) << endl;
        cout << "Size of double: " << sizeof(double) << endl;
        cout << "<typename T1, double>" << endl;
    }
};


int main()
{
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo();
    SimpleDataWrapper<const char*> swrap("Class Template Specialization");
    swrap.ShowDataInfo();
    SimpleDataWrapper<string> sswrap("string is JJANG!!!!");
    sswrap.ShowDataInfo();

    cout << "---------------------" << endl;
    Simple<char, double> o1;
    o1.WhoAreYou();
    Simple<int, double> o3;
    o3.WhoAreYou();
    Simple<int, long> o2;
    o2.WhoAreYou();
    return 0;
    
}


