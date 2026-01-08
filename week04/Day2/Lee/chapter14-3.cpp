// <템플릿 인자>

//T같은 문자를 '템플릿 매개변수' ex) typename T, int N
//템플릿 매개변수에 전달되는 자료형 정보를 '템플릿 인자' ex) int, 10


#include <iostream>
using namespace std;

template <typename T, int len> //템플릿 매개변수에도 변수가 올 수 있음
//template <typename T = int, int len = 7>   -> 매개변수에 디폴트 값 지정 가능
class SimpleArray {
private:
    T arr[len]; //if <int, 5>이면 int arr[5]
public:
    T& operator[] (int idx) { return arr[idx]; }

    //같은 타입(T)과 같은 크기(len)를 가진
    //SimpleArray 객체를 대입받을 때 어떻게 복사할지 정의
    //템플릿 인자를 다시 쓰는 이유는 클래스 자체 타입을 정확히 표현한 것
    SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref) {
        for (int i = 0; i < len; i++)
            arr[i] = ref.arr[i];
        return *this;
    }
    //ex) <int, 5> a <int, 10> b는 a=b가 안됨
    //SimpleArray& operator=(const SimpleArray& ref) 사실 이것도 컴파일러 에러는 안뜸(코드가 클래스 템플릿 내부에 있어서)
};

//<함수 템플릿과 static 지역변수>
//static 지역변수: 프로그램 전체 실행 동안 한 번만 생성되고 유지되는 변수

template <typename T>
class SimpleStaticMem {
private:
    static T mem;
public:
    void ADDMem(T num) { mem += num;  }
    void ShowMem() { cout << mem << endl; }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0; // static 멤버의 초기화 문장!
template <>
double SimpleStaticMem<double>::mem = 323;

int main()
{
    SimpleArray<int, 5> i5arr1;
    for (int i = 0; i < 5; i++)
        i5arr1[i] = i * 10;

    SimpleArray<int, 5> i5arr2;
    i5arr2 = i5arr1;
    for (int i = 0; i < 5; i++)
        cout << i5arr2[i] << ", ";
    cout << endl;

    SimpleArray<double, 7> i7arr1;
    for (int i = 0; i < 7; i++)
        i7arr1[i] = i * 10.3;

    SimpleArray<double, 7> i7arr2;
    i7arr2 = i7arr1;
    for (int i = 0; i < 7; i++)
        cout << i7arr2[i] << ", ";
    cout << endl;
    
    cout << "----------------------" << endl;

    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
    obj1.ADDMem(2);
    obj2.ADDMem(3);
    obj1.ShowMem();
    SimpleStaticMem<double> obj3;
    SimpleStaticMem<double> obj4;
    obj3.ADDMem(2.221);
    obj4.ADDMem(3.4512);
    obj3.ShowMem();
}


