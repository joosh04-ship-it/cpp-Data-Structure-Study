#include <iostream>
using namespace std;

template <typename T>
class print{
public:
    void printer(const T& a) const {
        cout << "일반 : " << a << endl;
    }
};

template <>                                 //클래스 템플릿 특수화
class print<const char*> {
public:
    void printer(const char* a) const {
        cout << "특수화: " << a << endl;
    }
};

template <class T1, class T2>
class simple {
    T1 a;
    T2 b;
public:
    void printer() {
        cout << a << ',' << b << endl;
    }
};

template<class T1>
class simple<T1, int> {                 //클래스 템플릿 부분특수화
    T1 a;
    int b;
public:
    void printer() {
        cout << a << '~' << b << endl;
    }
};

template <typename T1,int len>              //템플릿 매개변수, 변수 선언
class simple2 {
    T1 arr[len];
public:
    T1& operator[](int idx) {
        return arr[idx];
    }
};

template <typename T1, int len=5>              //템플릿 배개변수, 변수 선언 및 디폴트 값 지정
class simple3 {
    T1 arr[len];
public:
    T1& operator[](int idx) {
        return arr[idx];
    }
};

template <typename T>
class simple4 {
    static T mem;
public:
    void AddMem(T num) { mem += num; }
    void ShowMem() { cout << mem << endl; }
};

template <typename T>
T simple4<T>::mem = 0;

int main() {
    simple2<int, 5> arr;
    simple2<int, 7> arr1;
    //arr=arr1 대입 불가능 arr과 arr1을 다른 타입으로 인식

    simple4<int> i1;
    simple4<int> i2;
    i1.AddMem(5);
    i2.AddMem(6);
    i1.ShowMem();

    simple4<long> l1;
    simple4<long> l2;
    l1.AddMem(100);
    l2.AddMem(5);
    l1.ShowMem();
}
